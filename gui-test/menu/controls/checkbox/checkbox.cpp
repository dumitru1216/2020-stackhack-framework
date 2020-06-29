#include "checkbox.hpp"

namespace ui {
	checkbox check;

	/* variables */
	static bool hovered = false;
	static bool pressed = false;

	/* animation */
	int checkbox_anim_1[ 9999 ];
	int checkbox_anim_2[ 9999 ];

	void checkbox::begin( ) {
		if ( form.groupbox_bottom <= form.offset_y + 16 )
			return;
	}

	void checkbox::end( ) {
		form.offset_y += 21;
	}

	void checkbox::draw( std::string name, bool* item ) {
		/* begin controls */
		this->begin( );

		/* text size */
		renderer::dim text_size = ui::render.text_size( name, menu::menu_title_font );

		/* check for checkbox enable */
		if ( !GetAsyncKeyState( VK_LBUTTON ) && ui::render.mouse_in_region( form.controls_x + 75, form.offset_y, 9 + 17 + text_size.w, 9 ) ) {
			if ( pressed ) {
				*item = !*item;
			}
			pressed = false;
		}
		if ( GetAsyncKeyState( VK_LBUTTON ) && ui::render.mouse_in_region( form.controls_x + 75, form.offset_y, 9 + 17 + text_size.w, 9 ) && !pressed ) {
			pressed = true;
		}

		if ( *item ) {
			ui::render.filled_rect( form.controls_x + 75 + 6, form.offset_y + 1, 6, 8, color( 255, 0, 0 ) );
			ui::render.rect( form.controls_x + 75, form.offset_y, 12, 8, color( 255, 120, 120, 255 ) );
			ui::render.text( form.controls_x + 6, form.offset_y - 8, name, menu::menu_title_font, color( 255, 255, 255, 255 ) );

		}
		else {
			ui::render.filled_rect( form.controls_x + 75, form.offset_y + 1, 6, 8, color( 45, 45, 45 ) );
			ui::render.rect( form.controls_x + 75, form.offset_y, 12, 8, color( 45, 45, 45 ) );
			ui::render.text( form.controls_x + 6, form.offset_y - 8, name, menu::menu_title_font, color( 255, 255, 255, 120 ) );
		}

		/* end controls */
		this->end( );
	}
}