#ifndef THEME_HPP
#define THEME_HPP

#include "../../other/color.hpp"
namespace ui {
	struct theme_t {
		theme_t( ) {
			animation_speed = 20 * 0.01; /* we transform the speed to decimals. */

			draggable = true;
			drag_title = true;

			column_spacing = 4;

			backround_color = { 5, 5, 5 };
		}

		double animation_speed;
		bool draggable;
		bool drag_title;
		int column_spacing;
		int titlebar_size;

		color backround_color;
	};
}

#endif // !THEME_HPP