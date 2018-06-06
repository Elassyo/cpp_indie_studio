/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AudioBuffer.hpp
*/

#ifndef CPP_INDIE_STUDIO_AUDIOFILE_HPP
	#define CPP_INDIE_STUDIO_AUDIOFILE_HPP

	#include <memory>
	#include <string>
	#include <AL/al.h>
	#include <vorbis/vorbisfile.h>

namespace bomb {

	class AudioBuffer {
	public:
		explicit AudioBuffer(const char *path);
		explicit AudioBuffer(const std::string &path);

		~AudioBuffer();

		ALuint getBuffer() const;

	private:
		void readFile(OggVorbis_File *vf, std::size_t size);

		std::unique_ptr<int16_t[]> _buf;

		ALuint _buffer;
	};

}

#endif /* CPP_INDIE_STUDIO_AUDIOFILE_HPP */
