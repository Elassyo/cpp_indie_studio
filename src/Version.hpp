//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Version.hpp
//

#ifndef CPP_INDIE_STUDIO_VERSION_HPP
	#define CPP_INDIE_STUDIO_VERSION_HPP

	#include <map>
	#include <string>

namespace bomb {
	enum VersionID {
		LINUX_DEV,
		LINUX_REL,
		WINDOWS
	};

	class Version {
	public:
		static const Version &GetVersion(VersionID version);
		static const Version &GetCurrentVersion();

		Version() = default;

		const std::string &getAssetsPath();

	private:
		explicit Version(const std::string &assetsPath);

		static std::map<VersionID,Version> Versions;

		std::string _assetsPath;
	};
}

#endif /* CPP_INDIE_STUDIO_VERSION_HPP */
