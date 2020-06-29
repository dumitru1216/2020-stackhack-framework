#pragma once
#include "../../menu.hpp"

namespace ui {
	class slider_bar {
	public:
		/* slider int */
		void draw( std::string name, int* item, int min, int max );
		void think( );

		/* slider float */

		/* slide float & int controls */
		void begin( );
		void end( );

		/* variables */
		int alpha = 0;
		float slider_size = 114;
		bool hovered = false;
	};
	extern slider_bar slider;
}