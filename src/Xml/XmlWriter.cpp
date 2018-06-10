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
	_blockTypeStr({	      {BomberMap::BlockType::BOMB, "Empty"},
			      {BomberMap::BlockType::BREAKABLE, "Breakable"},
			      {BomberMap::BlockType::UNBREAKABLE, "Unbreakable"},
			      {BomberMap::BlockType::EMPTY, "Empty"}})
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

bool bomb::xml::XmlWriter::mapBlockToSection(BomberMap::BlockType blockType,
					     int x, int y)
{
	_fstream << "<" << _blockTypeStr.at(blockType) << " " << "x=\"" <<
		 x << "\" y=\"" << y << "\"/>" << std::endl;
	return true;
}

bool bomb::xml::XmlWriter::mapToSection(std::shared_ptr<bomb::BomberMap> &map)
{
	_fstream << "\t<BomberMap size=\"" << map->getSize() << "\">" <<
		 std::endl;
	int size = map->getSize();
	for (int i = 0; i < size * size; i++) {
		_fstream << "\t\t";
		mapBlockToSection((*map)[i], i % size, i / size);
	}
	_fstream << "\t</BomberMap>" << std::endl;
	return true;
}

bool bomb::xml::XmlWriter::playerToSection(const game::Player &player,
					   const PlayerInfo &playerInfo)
{
	auto pos = player.getExactPos();

	_fstream << "<PlayerInfo character=\"" << playerInfo.getCharacter() <<
		 "\" isAI=\"" << player.isAI() << "\" isAlive=\"" <<
		player.isAlive() << "\" x=\"" << pos.X << "\" z=\"" << pos.Z <<
		"\" isGhost=\"" << player.isGhostMode() <<
		"\" isBombGhost=\"" << player.isGhostBombMode() <<
		"\" speed=\"" << std::to_string(player.getSpeed()) <<
		"\" range=\"" << std::to_string(player.getBombRange()) <<
		"\" nbBombs=\"" << std::to_string(player.getNbBombs()) <<
		 "\"/>" << std::endl;
	return true;
}
