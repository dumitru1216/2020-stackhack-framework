#pragma once
#include "../../menu.hpp"

namespace ui {
	enum slider_flags {
		slider_preview_next_value,
		slider_value,
		slider_featured
	};

	enum slider_gradient_flags {
		true_flag,
		false_flag
	};

	class slider_bar {
	public:
		/* slider int */
		void draw( std::string name, int* item, int min, int max, int flags, int type, int flags2 );
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