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
	#include <vector>
	#include <AL/al.h>
	#include <vorbis/vorbisfile.h>

namespace bomb {

	constexpr int LOOP_REPEATS = 42;

	class AudioBuffer {
	public:
		explicit AudioBuffer(const char *path);
		explicit AudioBuffer(const std::string &path);

		~AudioBuffer();

		std::vector<ALuint> getBuffers() const;

	private:
		void readFile(OggVorbis_File *vf);

		void cutParts(OggVorbis_File *vf);
		void cutPart(ogg_int64_t start, ogg_int64_t end);
		ogg_int64_t getLoopStart(OggVorbis_File *vf);

		ALenum getAlFormat() const;

		std::unique_ptr<int16_t[]> _buf;
		ogg_int64_t _samples;

		int _channels;
		long _rate;

		std::vector<ALuint> _parts;
		std::vector<ALuint> _buffers;
	};

}

#endif /* CPP_INDIE_STUDIO_AUDIOFILE_HPP */
