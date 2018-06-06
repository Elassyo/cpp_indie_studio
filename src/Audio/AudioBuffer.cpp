/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AudioBuffer.cpp
*/

#include <codecvt>
#include <cstring>
#include <locale>

#include "../Exception/Exception.hpp"
#include "AudioBuffer.hpp"

bomb::AudioBuffer::AudioBuffer(const char *path)
{
	OggVorbis_File vf;
	if (ov_fopen(path, &vf) == 0)
		throw Exception("AudioBuffer", "Failed to open file");
	vorbis_info *vi = ov_info(&vf, -1);
	int channels = vi->channels;
	if (channels != 1 && channels != 2)
		throw Exception("AudioBuffer", "Invalid number of channels");
	ogg_int64_t samples = ov_pcm_total(&vf, -1);
	if (channels <= 0 || samples < 0)
		throw Exception("AudioBuffer", "Invalid or corrupt file");
	_buf = std::unique_ptr<int16_t[]>(new int16_t[samples * channels]);
	std::size_t size = samples * channels * sizeof(int16_t);
	readFile(&vf, size);
	ov_clear(&vf);
	alGenBuffers(1, &_buffer);
	alBufferData(_buffer,
		channels == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16,
		_buf.get(), size, vi->rate);
}

bomb::AudioBuffer::AudioBuffer(const std::string &path) :
	AudioBuffer(path.c_str())
{
}

bomb::AudioBuffer::~AudioBuffer()
{
	alDeleteBuffers(1, &_buffer);
}

ALuint bomb::AudioBuffer::getBuffer() const
{
	return _buffer;
}

void bomb::AudioBuffer::readFile(OggVorbis_File *vf, size_t size)
{
	char buf[4096];
	int bitstream = 0;
	std::size_t off = 0;
	while (off < size) {
		long rdsz = ov_read(vf, buf, sizeof(buf), 0, 2, 1, &bitstream);
		if (rdsz <= 0)
			throw Exception("AudioBuffer", "Read error");
		memcpy((int8_t *)_buf.get() + off, buf, (std::size_t)rdsz);
		off += rdsz;
	}
}
