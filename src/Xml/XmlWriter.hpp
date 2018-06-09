//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// XmlWriter.hpp
//

#ifndef CPP_INDIE_STUDIO_XMLWRITER_HPP
	#define CPP_INDIE_STUDIO_XMLWRITER_HPP

	#include <fstream>
	#include <iostream>
	#include <memory>
	#include <unordered_map>

#include "../Interface/IObject.hpp"
	#include "../Map/Map.hpp"
	#include "../Scenes/General/Player.hpp"

namespace bomb {
	namespace xml {
		class XmlWriter {
		public:
			explicit XmlWriter(const std::string &fileName);
			~XmlWriter();

			bool iObjectToSection(std::unique_ptr<IObject> &);
			bool mapBlockToSection(Map::BlockType, int, int);
			bool mapToSection(std::shared_ptr<Map> &);
			bool playerToSection(const game::Player &);

		private:
			std::ofstream _fstream;

			const std::unordered_map<Map::BlockType, std::string>
				_blockTypeStr;
			};
		}
	}

#endif /* CPP_INDIE_STUDIO_XMLWRITER_HPP */