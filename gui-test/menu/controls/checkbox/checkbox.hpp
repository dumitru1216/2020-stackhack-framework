#pragma once
#include "../../menu.hpp"

namespace ui {
	enum checkbox_flags {
		check_animation,
		check_outline,
		check_featured /* fully featured checkbox */
	};

	class checkbox {
	public:
		void begin( );
		void end( );
		void draw( std::string name, bool* item, int flags, int anim );
		
		

	};
	extern checkbox check;
}
