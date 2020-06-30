#include "combo.hpp"

namespace ui {
	combobox combo;

	/* variables */
	bool pressed = false;
	bool open = false;
	static bool selected_opened = false;
	static bool click_rest;
	static bool rest;
	static std::string name_selected;


	/* begin controls */
	void combobox::begin( ) {
		if ( form.groupbox_bottom <= form.offset_y + 35 )
			return;
	}

	/* end controls */
	void combobox::end( ) {
		form.controls_x += 22;
	}

	void combobox::draw( std::string name, int* item, std::string* item_name, int size, int flags ) {
		/* begin controls */
		this->begin( );

		/* random shit */
		int combo_size = 80;
		form.controls_x -= 22;

		/* combo think */
		if ( GetAsyncKeyState( VK_LBUTTON ) && render.mouse_in_region( form.controls_x + 75, form.offset_y + 2, combo_size, 14 ) && !click_rest ) {
			name_selected = name;
			pressed = true;
			click_rest = true;
		}
		else if ( !GetAsyncKeyState( VK_LBUTTON ) && render.mouse_in_region( form.controls_x + 75, form.offset_y + 2, combo_size, 14 ) ) {
			click_rest = false;
		}

		/* if presed */
		if ( pressed ) {
			if ( !rest ) {
				selected_opened = !selected_opened;
			}
			rest = true;
		}
		else {
			rest = false;
		}

		/* selected item */
		if ( name_selected == name ) {
			open = selected_opened;
		}

		/* setup combo */
		render.filled_rect( form.controls_x + 75, form.offset_y + 2, combo_size, 14, color( 35, 35, 35 ) );
		render.rect( form.controls_x + 75, form.offset_y + 2, combo_size, 14, color( 45, 45, 45 ) );

		/* combo name */
		render.text( form.controls_x + 29, form.offset_y - 2, name, menu::menu_font, color( 255, 255, 255 ) );

		/* open checkbox */
		if ( open ) {
			/* setup combo */
			render.filled_rect( form.controls_x + 75, form.offset_y + 2 + 21, combo_size, ( size * 14 ), color( 35, 35, 35 ) );
			render.rect( form.controls_x + 75, form.offset_y + 2 + 21, combo_size, ( size * 14 ), color( 45, 45, 45 ) );

			/* finish combo */
			for ( int i = 0; i < size; i++ ) {
				if ( GetAsyncKeyState( VK_LBUTTON ) && render.mouse_in_region( form.controls_x + 75, form.offset_y + 22 + i * 19, combo_size, 11 ) )
					*item = i;

				/* check if item is > 0 and put ouline red */
				if ( *item > 0 ) {
					render.rect( form.controls_x + 75, form.offset_y + 2, combo_size, 14, color( 255, 0, 0 ) );
				}
				else {

				}

				/* doing the combo names || bugged */
				if ( i == *item ) {
					render.text( form.controls_x + 77, form.offset_y - 1 * size, item_name[ i ], menu::menu_font, color( 255, 255, 255 ) );
				}
				else {
					if ( !render.mouse_in_region( form.controls_x + 29, form.offset_y + 22 + i * 14, combo_size, 11 ) ) {
						render.text( form.controls_x + 77, form.offset_y - 1, item_name[ i ], menu::menu_font, color( 255, 255, 255 ) );
					}
					else {
						render.text( form.controls_x + 77, form.offset_y - 1, item_name[ i ], menu::menu_font, color( 255, 0, 0 ) );
						render.text( form.controls_x + 77, form.offset_y - 1, item_name[ i ], menu::menu_font, color( 255, 0, 0 ) );
					}
				}

			}
		}

		render.text( form.controls_x + 77, form.offset_y - 1, item_name[ *item ], menu::menu_font, color( 255, 255, 255 ) );

		/* spacing : paster_mode on :) */
		if (open ) {
			if ( name == "" ) {
				form.offset_y += 47 - 26 + ( size * 19 );
			}
			else {
				form.offset_y += 47 + ( size * 19 );
			}
		}
		else {
			if ( name == "" ) {
				form.offset_y += 47 - 27;
			}
			else {
				form.offset_y += 41;
			}
		}
		

		/* end controls */
		this->end( );
	}
}