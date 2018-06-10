//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// ExplosionBlast.hpp
//

#ifndef CPP_INDIE_STUDIO_EXPLOSIONBLAST_HPP
	#define CPP_INDIE_STUDIO_EXPLOSIONBLAST_HPP

	#include <memory>

	#include "../../BillboardObject.hpp"

namespace bomb {
	namespace object {
		class ExplosionBlast {
		public:
			explicit ExplosionBlast(
				std::unique_ptr<BillboardObject>);
			void scaleDown();
			bool isFinished() const;
			std::unique_ptr<BillboardObject> releasePtr();
		private:
			std::unique_ptr<BillboardObject> _billBoard;
		};
	}
}

#endif /* CPP_INDIE_STUDIO_EXPLOSIONBLAST_HPP */