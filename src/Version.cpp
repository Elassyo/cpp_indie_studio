//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Version.cpp
//

#include "Exception/Exception.hpp"
#include "Version.hpp"

#ifndef BOMB_VERSION
	#error Build version not specified
#endif

#if (BOMB_VERSION == LINUX_DEV)

bomb::Version bomb::Version::GetCurrentVersion()
{
	return Version("./assets/", "./");
}

#elif (BOMB_VERSION == LINUX_REL)

	#include <algorithm>
	#include <sys/stat.h>
	#include <unistd.h>

bomb::Version bomb::Version::GetCurrentVersion()
{
	std::string home(getenv("HOME"));
	std::string savePath(".local/share/bombermario/");
	std::string::iterator it(savePath.begin());
	while (it != savePath.end()) {
		std::string::iterator sep(std::find(it, savePath.end(), '/'));
		std::string dir(home + '/' +
			std::string(savePath.begin(), sep));
		struct stat s;
		if (stat(dir.c_str(), &s) != 0 && mkdir(dir.c_str(), 0755) != 0)
			throw Exception("Version",
				"Failed to create save directory");
		else if (!S_ISDIR(s.st_mode))
			throw Exception("Version",
				"Cannot create save directory");
		it = sep + 1;
	}
	return Version("/usr/share/bombermario/", home + '/' + savePath);
}

#elif (BOMB_VERSION == WINDOWS)

	#include <ShlObj.h>

bomb::Version bomb::Version::GetCurrentVersion()
{
	TCHAR localAppData[MAX_PATH];
	TCHAR myDocuments[MAX_PATH];
	SHGetFolderPathA(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, localAppData);
	SHGetFolderPathA(NULL, CSIDL_MYDOCUMENTS, NULL, 0, myDocuments);
	std::string savePath = std::string(myDocuments) +
		"\\My Games\\BomberMario\\";
	int res = SHCreateDirectoryExA(NULL, savePath.c_str(), NULL);
	if (res != ERROR_SUCCESS && res != ERROR_ALREADY_EXISTS)
		throw Exception("Version", "Failed to create save directory");
	return Version(std::string(localAppData) + "\\BomberMario\\", savePath);
}

#else

	#error Invalid build version

#endif

bomb::Version::Version(const std::string &assetsPath,
	const std::string &savePath) :
	_assetsPath(assetsPath), _savePath(savePath)
{
}

const std::string &bomb::Version::getAssetsPath() const
{
	return _assetsPath;
}

const std::string &bomb::Version::getSavePath() const
{
	return _savePath;
}
