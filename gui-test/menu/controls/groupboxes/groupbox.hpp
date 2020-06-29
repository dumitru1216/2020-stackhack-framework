#pragma once
#include "../../menu.hpp"

namespace ui {
	class child {
	public:
		/* i will add flags soon */
		
		/* controls */
		void begin( );
		void end( int x, int y, int w, int h );

		void think( );
		void draw( int x, int y, int w, int h, std::string name );
	};
	extern child begin_child;
}