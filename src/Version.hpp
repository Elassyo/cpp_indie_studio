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

		const std::wstring &getAssetsPath() const;

	private:
		explicit Version(const std::wstring &assetsPath);

		std::wstring _assetsPath;
	};
}

#endif /* CPP_INDIE_STUDIO_VERSION_HPP */
