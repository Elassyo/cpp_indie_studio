//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// ATransformableObject.hpp
//

#ifndef CPP_INDIE_STUDIO_ATRANSFORMABLEOBJECT_HPP
#define CPP_INDIE_STUDIO_ATRANSFORMABLEOBJECT_HPP

#include "src/interface/ITransformable.hpp"
#include "AObject.hpp"

namespace bomb {
	class ATransformableObject :
		virtual public ITransformable,
		public AObject {
	public:
		explicit ATransformableObject(
			const irr::core::vector3df &pos = {0, 0, 0},
			const irr::core::vector3df &scale = {0, 0, 0},
			const irr::core::vector3df &rotation = {0, 0, 0}
		);

		void move(const irr::core::vector3df &df) override;
		void rotate(const irr::core::vector3df &df) override;
		void scale(const irr::core::vector3df &df) override;
	};
}

#endif /* CPP_INDIE_STUDIO_ATRANSFORMABLEOBJECT_HPP */