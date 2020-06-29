#include "slider.hpp"

namespace ui {
	slider_bar slider;

	void slider_bar::begin( ) {
		if ( form.groupbox_bottom <= form.offset_y + 30 )
			return;
	}

	void slider_bar::end( ) {
		form.offset_y += 21;
	}

	void slider_bar::draw( std::string name, int* item, int min, int max ) {
		/* begin controls */
		this->begin( );

		/* pixel value */
		float _pixel_value = max / slider_size;

		/* mouse in region */
		renderer::pos mouse_pos;
		ui::render.mouse_pos( mouse_pos );

		if ( GetAsyncKeyState( VK_LBUTTON ) && ui::render.mouse_in_region( form.controls_x + 73, form.offset_y + 1, ( this->slider_size + 76 ) + ( 3 * 2 ), 8 ) ) {
			*item = abs( mouse_pos.x - ( form.controls_x + 73 ) ) * _pixel_value;
		}

		if ( *item > max ) {
			*item = max;
		}

		if ( *item < 0 ) {
			*item = 0;
		}

		/* setup slider */
		if ( *item ) {
			if ( *item == max ) {
				ui::render.filled_rect( form.controls_x + 75, form.offset_y + 3, this->slider_size, 8, color( 255, 0, 0, 255 ) );
			}
			else {
				ui::render.filled_rect( form.controls_x + 75, form.offset_y + 3, ( *item / _pixel_value ), 8, color( 255, 0, 0, 255 ) );

			}
		}

		/* style good */
		if ( *item > 0 ) {
			render.rect( form.controls_x + 75, form.offset_y + 3, this->slider_size, 8, color( 255, 0, 0 ) );
			render.text( form.controls_x + 6, form.offset_y - 5, name, menu::menu_title_font, color( 255, 255, 255 ) );
		}
		else {
			render.rect( form.controls_x + 75, form.offset_y + 3, this->slider_size, 8, color( 45, 45, 45 ) );
			render.text( form.controls_x + 6, form.offset_y - 5, name, menu::menu_title_font, color( 255, 255, 255, 120 ) );

		}

		/* end controls */
		this->end( );
	}
}
