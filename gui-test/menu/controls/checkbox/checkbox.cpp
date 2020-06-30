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

	void checkbox::draw( std::string name, bool* item, int flags, int anim ) {
		/* begin controls */
		this->begin( );

		/* text size */
		renderer::dim text_size = ui::render.text_size( name, menu::menu_title_font );

		/* check for checkbox enable */
		if ( !GetAsyncKeyState( VK_LBUTTON ) && ui::render.mouse_in_region( form.controls_x + 6, form.offset_y, 9 + 17 + text_size.w, 9 ) ) {
			if ( pressed ) {
				*item = !*item;
			}
			pressed = false;
		}
		if ( GetAsyncKeyState( VK_LBUTTON ) && ui::render.mouse_in_region( form.controls_x + 6, form.offset_y, 9 + 17 + text_size.w, 9 ) && !pressed ) {
			pressed = true;
		}

		if ( *item ) {
			ui::render.filled_rect( form.controls_x + 6, form.offset_y + 1, 12, 12, color( 255, 0, 0 ) );
			ui::render.text( form.controls_x + 25, form.offset_y - 2, name, menu::menu_title_font, color( 255, 255, 255, 255 ) );
		}
		else {
			ui::render.filled_rect( form.controls_x + 6, form.offset_y + 1, 12, 12, color( 45, 45, 45 ) );
			ui::render.text( form.controls_x + 25, form.offset_y - 2, name, menu::menu_title_font, color( 255, 255, 255, 120 ) );
		}

		/* setup flags */
		if ( flags == check_outline ) {
			/* check the item if is true or false */
			if ( *item ) {
				ui::render.rect( form.controls_x + 6, form.offset_y + 1, 12, 12, color( 180, 0, 0 ) );
			}
			else {
				ui::render.rect( form.controls_x + 6, form.offset_y + 1, 12, 12, color( 120, 120, 120, 120 ) );
			}
		}

		/* animation flag */ 
		if ( flags == check_animation ) {
			/* hovered animation */
			if ( ui::render.mouse_in_region( form.controls_x + 6, form.offset_y, 9 + 17 + text_size.w, 9 ) ) {
				hovered = true;
			}
			else {
				hovered = false;
			}

			/* setup animation */
			if ( hovered ) {
				checkbox_anim_1[ anim ] = 0;
				if ( checkbox_anim_2[ anim ] < 120 ) {
					checkbox_anim_2[ anim ] += 2;
				}
				else {
					checkbox_anim_2[ anim ] = 120;
				}
			}
			else {
				checkbox_anim_2[ anim ] = 0;
				if ( checkbox_anim_1[ anim ] < 120 ) {
					checkbox_anim_1[ anim ] += 2;
				}
				else {
					checkbox_anim_1[ anim ] = 120;
				}
			}

			/* draw the outline + rect  */
			if ( hovered ) {
				ui::render.filled_rect( form.controls_x + 6, form.offset_y + 1, 12, 12, color( 255, 0, 0, checkbox_anim_2[ anim ] ) );
				ui::render.rect( form.controls_x + 6, form.offset_y + 1, 12, 12, color( 180, 0, 0, checkbox_anim_2[ anim ] ) );
			}
			else {

			}
		}

		/* fully featured checkbox */
		if ( flags == check_featured ) {
			/*
				*** info ***
					we gonna make the turn on animation of checkbox
					we gonna make the hovered animation again

					**** in future more things ****
			*/

			/* start */
						/* hovered animation */
			if ( ui::render.mouse_in_region( form.controls_x + 6, form.offset_y, 9 + 17 + text_size.w, 9 ) ) {
				hovered = true;
			}
			else {
				hovered = false;
			}

			/* setup animation */
			if ( hovered ) {
				checkbox_anim_1[ anim ] = 0;
				if ( checkbox_anim_2[ anim ] < 120 ) {
					checkbox_anim_2[ anim ] += 2;
				}
				else {
					checkbox_anim_2[ anim ] = 120;
				}
			}
			else {
				checkbox_anim_2[ anim ] = 0;
				if ( checkbox_anim_1[ anim ] < 120 ) {
					checkbox_anim_1[ anim ] += 2;
				}
				else {
					checkbox_anim_1[ anim ] = 120;
				}
			}

			/* draw the outline + rect  */
			if ( hovered ) {
				ui::render.filled_rect( form.controls_x + 6, form.offset_y + 1, 12, 12, color( 255, 0, 0, checkbox_anim_2[ anim ] ) );
				ui::render.rect( form.controls_x + 6, form.offset_y + 1, 12, 12, color( 180, 0, 0, checkbox_anim_2[ anim ] ) );
			}
			else {

			}

			/* variables for turn on : off animation */
			int check_turn1[ 9999 ];
			int check_turn2[ 9999 ];

			/* start aninmation */
			if ( *item ) {
				check_turn1[ anim ] = 0;
				if ( anim > 0 ) {
					if ( check_turn2[ anim ] < 255 ) {
						check_turn2[ anim ] += 2;
					}
					else {
						check_turn2[ anim ] = 255;
					}
				}
			}
			else {
				check_turn2[ anim ] = 0;
				if ( anim > 0 ) {
					if ( check_turn1[ anim ] < 255 ) {
						check_turn1[ anim ] = 255;
					}
					else {
						check_turn1[ anim ] = 255;
					}
				}
			}

			/* render checkbox */
			if ( *item ) {
				ui::render.filled_rect( form.controls_x + 6, form.offset_y + 1, 12, 12, color( 255, 0, 0, check_turn2[ anim ] ) );
				ui::render.rect( form.controls_x + 6, form.offset_y + 1, 12, 12, color( 180, 0, 0, check_turn2[ anim ] ) );
			}
			else {

			}
		
		}

		/* end controls */
		this->end( );
	}
}