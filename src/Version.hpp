//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Version.hpp
//

#ifndef CPP_INDIE_STUDIO_VERSION_HPP
	#define CPP_INDIE_STUDIO_VERSION_HPP

	#include <string>

	#define LINUX_DEV 0
	#define LINUX_REL 1
	#define WINDOWS 2

namespace bomb {

	class Version {
	public:
		static Version GetCurrentVersion();

		const std::string &getAssetsPath() const;
		const std::string &getSavePath() const;

	private:
		explicit Version(const std::string &assetsPath,
			const std::string &savePath);

		std::string _assetsPath;
		std::string _savePath;
	};
}

#endif /* CPP_INDIE_STUDIO_VERSION_HPP */
