/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AudioFile.cpp
*/

#include <cstring>

#include "../Exception/Exception.hpp"
#include "AudioFile.hpp"

bomb::AudioFile::AudioFile(const char *path)
{
	OggVorbis_File vf;
	if (ov_fopen(path, &vf) == 0)
		throw Exception("AudioFile", "Failed to open file");
	vorbis_info *vi = ov_info(&vf, -1);
	_channels = vi->channels;
	_samples = ov_pcm_total(&vf, -1);
	if (_channels <= 0 || _samples < 0)
		throw Exception("AudioFile", "Invalid or corrupt file");
	_buf = std::unique_ptr<int16_t[]>(new int16_t[_samples * _channels]);
	readFile(&vf);
	ov_clear(&vf);
}

bomb::AudioFile::AudioFile(const std::string &path) :
	AudioFile(path.c_str())
{
}

std::size_t bomb::AudioFile::getBufferSize() const
{
	return _samples * _channels * sizeof(int16_t);
}

int16_t *bomb::AudioFile::getBuffer() const
{
	return _buf.get();
}

void bomb::AudioFile::readFile(OggVorbis_File *vf)
{
	char buf[4096];
	int bitstream = 0;
	std::size_t off = 0;
	while (off < getBufferSize()) {
		long rdsz = ov_read(vf, buf, sizeof(buf), 0, 2, 1, &bitstream);
		if (rdsz <= 0)
			throw Exception("AudioFile", "Read error");
		memcpy((int8_t *)_buf.get() + off, buf, rdsz);
		off += rdsz;
	}
}
