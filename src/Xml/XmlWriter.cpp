//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// XmlWriter.cpp
//

#include "XmlWriter.hpp"
#include "../Exception/Exception.hpp"

bomb::xml::XmlWriter::XmlWriter(const std::string &fileName) :
	_fstream(fileName),
	_blockTypeStr({	      {Map::BlockType::BOMB, "Bomb"},
			      {Map::BlockType::BREAKABLE, "Breakable"},
			      {Map::BlockType::UNBREAKABLE, "Unbreakable"},
			      {Map::BlockType::EMPTY, "Empty"}})
{
	if (!_fstream)
		throw Exception("XmlWriter", "Can't create save file : " + fileName);
	_fstream << "<?xml version=\"1.0\"?>" << std::endl;
}

bomb::xml::XmlWriter::~XmlWriter()
{
	_fstream.close();
}

bool bomb::xml::XmlWriter::iObjectToSection(std::unique_ptr<IObject> &object)
{
	object->getPos();
	return false;
}

bool bomb::xml::XmlWriter::mapBlockToSection(Map::BlockType blockType,
					     int x, int y)
{
	_fstream << "<" << _blockTypeStr.at(blockType) << " " << "x=\"" <<
		 x << "\" y=\"" << y << "\"/>" << std::endl;
	return true;
}

bool bomb::xml::XmlWriter::mapToSection(std::shared_ptr<bomb::Map> &map)
{
	_fstream << "\t<Map>" << std::endl;
	int size = map->getSize();
	for (int i = 0; i < size * size; i++) {
		_fstream << "\t\t";
		mapBlockToSection((*map)[i], i % size, i / size);
	}
	_fstream << "\t</Map>" << std::endl;
	return true;
}

bool bomb::xml::XmlWriter::playerToSection(const game::Player &player)
{
	auto pos = player.getExactPos();

	_fstream << "<PlayerInfo isAI=\"" << player.isAI() << "\" isAlive=\"" <<
		 player.isAlive() << "\" x=\"" << pos.X << "\" y=\"" << pos.Y <<
		 "\"/>" << std::endl;
	return true;
}
