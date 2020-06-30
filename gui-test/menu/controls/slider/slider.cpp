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

	void slider_bar::draw( std::string name, int* item, int min, int max, int flags, int type, int flags2 ) {
		/* begin controls */
		this->begin( );

		/* pixel value */
		float _pixel_value = max / slider_size;

		/* mouse in region */
		renderer::pos mouse_pos;
		ui::render.mouse_pos( mouse_pos );

		if ( GetAsyncKeyState( VK_LBUTTON ) && ui::render.mouse_in_region( form.controls_x + 6, form.offset_y + 9, ( this->slider_size + 9 ) + ( 3 * 2 ), 8 ) ) {
			*item = abs( mouse_pos.x - ( form.controls_x + 6 ) ) * _pixel_value;
		}

		if ( *item > max ) {
			*item = max;
		}

		if ( *item < 0 ) {
			*item = 0;
		}

		/* slider + flags */
		if ( flags == slider_value ) {
			renderer::dim slider_name_size = render.text_size( name, menu::menu_font );

			if ( *item > 0 ) {
				render.text( form.controls_x + slider_name_size.w + 13, form.offset_y - 3, ":", menu::menu_font, color( 255, 255, 255 ) );
				render.text( form.controls_x + slider_name_size.w + 19, form.offset_y - 3, std::to_string( *item ).c_str( ), menu::menu_font, color( 255, 255, 255 ) );
			}
			else {

			}
		}

		/* sliderr preview : credits : alpha */
		if ( flags == slider_preview_next_value ) {
			/* slider position variables */
			renderer::pos slider_position;
			render.mouse_pos( slider_position );

			static bool slider_hovered = false;
			int posible_position = ( slider_position.x - form.controls_x );

			/* mouse region */
			if ( render.mouse_in_region( form.controls_x + 6, form.offset_y - 12, this->slider_size, 8 ) && !GetAsyncKeyState( VK_LBUTTON ) ) {
				render.filled_rect( form.controls_x + 6, form.offset_y - 12, posible_position, 8, color( 255, 0, 0, 100 ) );
			}
		}

		/* slider feteaured : cool english -> flags */
		if ( flags == slider_featured ) {
			/* slider position */
			/* slider name */
			renderer::dim slider_name_size = render.text_size( name, menu::menu_font );

			/* slider position variables */
			renderer::pos slider_position;
			render.mouse_pos( slider_position );

			static bool slider_hovered = false;
			int posible_position = ( slider_position.x - form.controls_x );

			/* overide system */
			static bool posible_hovered = false;
			if ( render.mouse_in_region( form.controls_x + 6, form.offset_y + 6, this->slider_size, 8 ) && !GetAsyncKeyState( VK_LBUTTON ) ) {
				posible_hovered = true;
			}
			else {
				posible_hovered = false;
			}

			/* mouse region */
			if ( posible_hovered ) {
				render.filled_rect( form.controls_x + 6, form.offset_y + 6, posible_position, 8, color( 255, 0, 0, 100 ) );
				//render.text( form.controls_x + slider_name_size.w + 19 + this->slider_size + 10, form.offset_y - 1, std::to_string( posible_position ).c_str( ), menu::menu_font, color( 255, 255, 255 ) );
			}
			else {

			}

			/* slider info */
			if ( *item > 0 ) {
				render.text( form.controls_x + slider_name_size.w + 13 + this->slider_size + 10, form.offset_y - 1, ":", menu::menu_font, color( 255, 255, 255 ) );
				render.text( form.controls_x + slider_name_size.w + 19 + this->slider_size + 10, form.offset_y - 1, std::to_string( *item ).c_str( ), menu::menu_font, color( 255, 255, 255 ) );

			}
			else {
				render.text( form.controls_x + slider_name_size.w + 13 + this->slider_size + 10, form.offset_y - 1, ":", menu::menu_font, color( 255, 255, 255, 120 ) );
				render.text( form.controls_x + slider_name_size.w + 19 + this->slider_size + 10, form.offset_y - 1, std::to_string( *item ).c_str( ), menu::menu_font, color( 255, 255, 255, 120 ) );
			}
		}

		/* slider types */
		switch ( type ) {
			case 0: /* normal slider : classic */ {
				/* normal slider */
				/* setup slider */
				if ( *item ) {
					if ( *item == max ) {
						ui::render.filled_rect( form.controls_x + 6, form.offset_y + 6, this->slider_size, 8, color( 255, 0, 0, 255 ) );
					}
					else {
						ui::render.filled_rect( form.controls_x + 6, form.offset_y + 6, ( *item / _pixel_value ), 8, color( 255, 0, 0, 255 ) );

					}
				}

				/* style good */
				if ( *item > 0 ) {
					render.rect( form.controls_x + 6, form.offset_y + 6, this->slider_size, 8, color( 255, 0, 0, 120 ) );
					render.text( form.controls_x + 6, form.offset_y - 4, name, menu::menu_title_font, color( 255, 255, 255 ) );
				}
				else {
					render.text( form.controls_x + 6, form.offset_y - 4, name, menu::menu_title_font, color( 255, 255, 255, 120 ) );
					render.rect( form.controls_x + 6, form.offset_y + 6, this->slider_size, 8, color( 120, 120, 120, 120 ) );
				}
			} break;
			case 1: /* modern slider : modern -> gradient */ {
				if ( *item ) {
					switch ( flags2 ) {
						case true_flag: {
							if ( *item == max ) {
								ui::render.gradient_rect( form.controls_x + 6, form.offset_y + 6, this->slider_size, 8, color( 150, 0, 0, 255 ), color( 255, 0, 0 ), true );
							}
							else {
								ui::render.gradient_rect( form.controls_x + 6, form.offset_y + 6, ( *item / _pixel_value ), 8, color( 150, 0, 0, 255 ), color( 255, 0, 0 ), true );
							}
						} break;
						case false_flag: {
							if ( *item == max ) {
								ui::render.gradient_rect( form.controls_x + 6, form.offset_y + 6, this->slider_size, 8, color( 150, 0, 0, 255 ), color( 255, 0, 0 ), false );
							}
							else {
								ui::render.gradient_rect( form.controls_x + 6, form.offset_y + 6, ( *item / _pixel_value ), 8, color( 150, 0, 0, 255 ), color( 255, 0, 0 ), false );
							}
						} break;
					}
				}

				/* style good */
				if ( *item > 0 ) {
					render.rect( form.controls_x + 6, form.offset_y + 6, this->slider_size, 8, color( 255, 0, 0, 120 ) );
					render.text( form.controls_x + this->slider_size + 10, form.offset_y - 1, name, menu::menu_title_font, color( 255, 255, 255 ) );
				}
				else {
					render.text( form.controls_x + this->slider_size + 10, form.offset_y - 1, name, menu::menu_title_font, color( 255, 255, 255, 120 ) );
					render.rect( form.controls_x + 6, form.offset_y + 6, this->slider_size, 8, color( 120, 120, 120, 120 ) );
				}

			} break;
		}

		/* end controls */
		this->end( );
	}
}
