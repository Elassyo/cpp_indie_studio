//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// XmlWriter.cpp
//

#include "XmlWriter.hpp"
#include "../Exception/Exception.hpp"

bomb::xml::XmlWriter::XmlWriter(const irr::core::stringw &fileName) :
	_blockTypeStr({	      {Map::BlockType::BOMB, L"bomb"},
			      {Map::BlockType::BREAKABLE, L"breakable"},
			      {Map::BlockType::UNBREAKABLE, L"unbreakable"},
			      {Map::BlockType::EMPTY, L"empty"}})
{
	_nullDevice = irr::createDevice(irr::video::EDT_NULL);

	if (!_nullDevice)
		throw Exception("XmlWriter", "Can't load null device");
	_xmlWriter = _nullDevice->getFileSystem()->createXMLWriter(fileName);
}

bomb::xml::XmlWriter::~XmlWriter()
{
	_nullDevice->closeDevice();
	_nullDevice->run();
	_nullDevice->drop();
	_xmlWriter->drop();
}

bool bomb::xml::XmlWriter::iObjectToSection(std::unique_ptr<IObject> &object)
{
	object->getPos();
	return false;
}

bool bomb::xml::XmlWriter::mapBlockToSection(Map::BlockType blockType,
					     int x, int y)
{
	_xmlWriter->writeElement(_blockTypeStr.at(blockType).c_str(), true,
				L"x", std::to_wstring(x).c_str(),
				L"y", std::to_wstring(y).c_str());
	_xmlWriter->writeLineBreak();
	return true;
}

std::wstring bomb::xml::XmlWriter::_strToWstr(const std::string &str) const
{
	std::wstring res(str.length(),L' ');

	std::copy(str.begin(), str.end(), res.begin());
	return res;
}

bool bomb::xml::XmlWriter::mapToSection(std::shared_ptr<bomb::Map> &map)
{
	_xmlWriter->writeElement(L"Map");
	_xmlWriter->writeLineBreak();
	int size = map->getSize();
	for (int i = 0; i < size * size; i++)
		mapBlockToSection((*map)[i], i % size, i / size);
	_xmlWriter->writeClosingTag(L"Map");
	_xmlWriter->writeLineBreak();
	return true;
}

bool bomb::xml::XmlWriter::playerToSection(const game::Player &player)
{
	auto pos = player.getExactPos();

	_xmlWriter->writeElement(L"PlayerInfo", true,
	L"isIA", std::to_wstring(player.isAI()).c_str(),
	L"isAlive", std::to_wstring(player.isAlive()).c_str(),
	L"x", std::to_wstring(pos.X).c_str(),
	L"y", std::to_wstring(pos.Y).c_str());
	_xmlWriter->writeLineBreak();
	return true;
}
