/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** AudioFile.hpp
*/

#ifndef CPP_INDIE_STUDIO_AUDIOFILE_HPP
	#define CPP_INDIE_STUDIO_AUDIOFILE_HPP

	#include <memory>
	#include <string>
	#include <AL/al.h>
	#include <vorbis/vorbisfile.h>

namespace bomb {

	class AudioFile {
	public:
		explicit AudioFile(const char *path);
		explicit AudioFile(const std::string &path);

		std::size_t getBufferSize() const;
		int16_t *getBuffer() const;

	private:
		void readFile(OggVorbis_File *vf);

		int _channels;
		ogg_int64_t _samples;

		std::unique_ptr<int16_t[]> _buf;
	};

}

#endif /* CPP_INDIE_STUDIO_AUDIOFILE_HPP */
