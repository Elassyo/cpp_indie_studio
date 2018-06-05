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
	return Version(L"./assets/");
}
#elif (BOMB_VERSION == LINUX_REL)
bomb::Version bomb::Version::GetCurrentVersion()
{
	return Version(L"/usr/share/bombermario/");
}
#elif (BOMB_VERSION == WINDOWS)

	#include <ShlObj.h>

bomb::Version bomb::Version::GetCurrentVersion()
{
	TCHAR localAppData[MAX_PATH];
	SHGetFolderPath(NULL, CSIDL_LOCAL_APPDATA, NULL, 0, localAppData);
	return Version(std::string(localAppData) + "\\BomberMario\\");
}
#else
	#error Invalid build version
#endif

bomb::Version::Version(const std::string &assetsPath) :
	_assetsPath(assetsPath)
{
}

const std::string &bomb::Version::getAssetsPath() const
{
	return _assetsPath;
}
