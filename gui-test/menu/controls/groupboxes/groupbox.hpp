#pragma once
#include "../../menu.hpp"

namespace ui {
	enum child_flags {
		child_none,
		child_outline,
		child_title_bar,
		child_animation,
		child_featured
	};

	class child {
	public:
		/* i will add flags soon */
		
		/* controls */
		void begin( );
		void end( int x, int y, int w, int h );

		void think( );
		void draw( int x, int y, int w, int h, std::string name, int flags, int anim );
	};
	extern child begin_child;
}