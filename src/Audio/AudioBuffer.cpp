/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AudioBuffer.cpp
*/

#include <algorithm>
#include <cstring>

#include "../Exception/Exception.hpp"
#include "AudioBuffer.hpp"

bomb::AudioBuffer::AudioBuffer(const char *path)
{
	OggVorbis_File vf;
	if (ov_fopen(path, &vf) != 0)
		throw Exception("AudioBuffer",
				std::string("Failed to open file : ") + path);
	vorbis_info *vi = ov_info(&vf, -1);
	_channels = vi->channels;
	_rate = vi->rate;
	if (_channels != 1 && _channels != 2)
		throw Exception("AudioBuffer", "Invalid number of channels");
	_samples = ov_pcm_total(&vf, -1);
	if (_channels <= 0 || _samples < 0)
		throw Exception("AudioBuffer", "Invalid or corrupt file");
	_buf = std::unique_ptr<int16_t[]>(new int16_t[_samples * _channels]);
	readFile(&vf);
	cutParts(&vf);
	ov_clear(&vf);
}

bomb::AudioBuffer::AudioBuffer(const std::string &path) :
	AudioBuffer(path.c_str())
{
}

bomb::AudioBuffer::~AudioBuffer()
{
	alDeleteBuffers(_parts.size(), _parts.data());
}

std::vector<ALuint> bomb::AudioBuffer::getBuffers() const
{
	return _buffers;
}

void bomb::AudioBuffer::readFile(OggVorbis_File *vf)
{
	char buf[4096];
	int bitstream = 0;
	std::size_t off = 0;
	std::size_t buf_sz = _samples * _channels * sizeof(int16_t);
	while (off < buf_sz) {
		long rdsz = std::min<long>(sizeof(buf), buf_sz - off);
		rdsz = ov_read(vf, buf, rdsz, 0, 2, 1, &bitstream);
		if (rdsz <= 0)
			throw Exception("AudioBuffer", "Read error");
		memcpy((int8_t *)_buf.get() + off, buf, (std::size_t)rdsz);
		off += rdsz;
	}
}

void bomb::AudioBuffer::cutParts(OggVorbis_File *vf)
{
	ogg_int64_t loop_start = getLoopStart(vf);
	if (loop_start == -1) {
		cutPart(0, _samples);
		_buffers.push_back(_parts[0]);
	} else {
		cutPart(0, loop_start - 1);
		cutPart(loop_start, _samples);
		_buffers.push_back(_parts[0]);
		for (int i = 0; i < LOOP_REPEATS; i++)
			_buffers.push_back(_parts[1]);
	}
}

void bomb::AudioBuffer::cutPart(ogg_int64_t start, ogg_int64_t end)
{
	ALuint buffer;
	alGenBuffers(1, &buffer);
	alBufferData(buffer, getAlFormat(), &_buf[start * _channels],
		(end - start) * _channels * sizeof(int16_t), _rate);
	_parts.push_back(buffer);
}

ogg_int64_t bomb::AudioBuffer::getLoopStart(OggVorbis_File *vf)
{
	vorbis_comment *comments = ov_comment(vf, -1);
	for (int i = 0; i < comments->comments; i++) {
		std::string c = comments->user_comments[i];
		if (c.find("LOOP_START=") == 0) {
			try {
				return (std::stoll(c.substr(11)));
			} catch (std::invalid_argument &) {
				throw Exception("AudioBuffer",
					"Invalid loop marker");
			}
		}
	}
	return -1;
}

ALenum bomb::AudioBuffer::getAlFormat() const
{
	return _channels == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16;
}
