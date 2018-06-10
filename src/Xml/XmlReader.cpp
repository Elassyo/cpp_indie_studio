//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// XmlReader.cpp
//

#include "XmlReader.hpp"

bomb::xml::XmlReader::XmlReader(const std::string &filePath) :
	_section(L"")
{
	_nullDevice = irr::createDevice(irr::video::EDT_NULL);
	if (!_nullDevice)
		throw Exception("XmlReader", "can't create nullDevice");
	_xmlReader = _nullDevice->getFileSystem()->createXMLReader(filePath.c_str());
	if (!_xmlReader)
		throw Exception("XmlReader", "Can't create irr::XmlReader");
}

bomb::xml::XmlReader::~XmlReader()
{
	_xmlReader->drop();
	_nullDevice->closeDevice();
	_nullDevice->run();
	_nullDevice->drop();
}

bool bomb::xml::XmlReader::read()
{
	if (!_xmlReader->read())
		return false;
	if (_section.empty() && _xmlReader->getNodeType() ==
				irr::io::EXN_ELEMENT)
		_section = _xmlReader->getNodeName();
	if (_xmlReader->getNodeType() == irr::io::EXN_ELEMENT_END)
		_section = L"";
	return true;
}

std::wstring bomb::xml::XmlReader::getActualSection() const
{
	return _section;
}

int bomb::xml::XmlReader::getIntValue(const std::wstring &properties) const
{
	return _xmlReader->getAttributeValueAsInt(properties.c_str());
}

std::wstring bomb::xml::XmlReader::getStringValue(const std::wstring &prop) const
{
	return _xmlReader->getAttributeValueSafe(prop.c_str());
}

std::wstring bomb::xml::XmlReader::getNodeName() const
{
	return _xmlReader->getNodeName();
}
