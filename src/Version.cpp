//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Version.cpp
//

#include "Exception/Exception.hpp"
#include "Version.hpp"

#ifndef BOMB_VERSION
	#error Build version not specified (BOMB_VERSION not defined)
#endif

std::map<bomb::VersionID,bomb::Version> bomb::Version::Versions = {
	{ LINUX_DEV, Version("./assets/") },
	{ LINUX_REL, Version("/usr/share/bomberman/") }
};

const bomb::Version &bomb::Version::GetVersion(VersionID version)
{
	auto it = Versions.find(version);
	if (it == Versions.end())
		throw Exception("Version", "Unknown build version");
	return it->second;
}

const bomb::Version &bomb::Version::GetCurrentVersion()
{
	return GetVersion(BOMB_VERSION);
}

bomb::Version::Version(const std::string &assetsPath) :
	_assetsPath(assetsPath)
{
}

const std::string &bomb::Version::getAssetsPath()
{
	return _assetsPath;
}

