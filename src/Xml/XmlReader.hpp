//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// XmlReader.hpp
//

#ifndef CPP_INDIE_STUDIO_XMLREADER_HPP
	#define CPP_INDIE_STUDIO_XMLREADER_HPP

	#include <irrlicht/irrlicht.h>
	#include <iostream>

	#include "../Exception/Exception.hpp"

namespace bomb {
	namespace xml {
		class XmlReader {
		public:
			explicit XmlReader(const std::string &filePath);
			~XmlReader();

			bool read();
			std::wstring getActualSection() const;
			int getIntValue(const std::wstring &properties) const;
			float getFloatValue(const std::wstring &prop) const;
			std::wstring getStringValue(const std::wstring &prop)
			const;
			std::wstring getNodeName() const;
		private:
			std::wstring _section;
			irr::IrrlichtDevice *_nullDevice;
			irr::io::IXMLReader *_xmlReader;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_XMLREADER_HPP */