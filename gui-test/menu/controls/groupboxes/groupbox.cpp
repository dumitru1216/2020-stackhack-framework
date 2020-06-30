#include "groupbox.hpp"

namespace ui {
	child begin_child;

	/* child think */
	void child::think( ) {

	}

	void child::begin( ) {

	}

	void child::end( int x, int y, int w, int h ) {
		form.offset_y = form.position.y + y + 12;
		form.controls_x = form.position.x + x;
		form.groupbox_bottom = ( form.position.y + ( y + h ) );
		form.groupbox_width = ( form.position.x + ( x + w ) );
	}

	/* child draw */
	void child::draw( int x, int y, int w, int h, std::string name, int flags, int anim ) {
		render.filled_rect( form.position.x + x, form.position.y + y, w, h, color( 25, 25, 25 ) );

		/* setup flags */
		/* child outline flag */
		if ( flags == child_outline ) {
			render.rect( form.position.x + x, form.position.y + y, w, h, color( 120, 120, 120, 120 ) );
		}
		if ( flags == child_animation ) {
			/* start animation */
			static bool hovered = false;
			int group_animation1[ 9999 ];
			int group_animation2[ 9999 ];

			/* check if we are hovering */
			if ( render.mouse_in_region( form.position.x + x, form.position.y + y, w, h ) ) {
				hovered = true;
			}
			else {
				hovered = false;
			}

			/* setup animation */
			if ( hovered ) {
				group_animation1[ anim ] = 0;
				if ( anim > 0 ) {
					if ( group_animation2[ anim ] < 120 ) {
						group_animation2[ anim ] += 2;
					}
					else {
						group_animation2[ anim ] = 120;
					}
				}
			}
			else {
				group_animation2[ anim ] = 0;
				if ( anim > 0 ) {
					if ( group_animation1[ anim ] < 120 ) {
						group_animation1[ anim ] += 2;
					}
					else {
						group_animation1[ anim ] = 120;
					}
				}
			}

			render.rect( form.position.x + x, form.position.y + y, w, h, color( 120, 120, 120, group_animation2[ anim ] ) );
		}

		/* child flag name */
		if ( flags == child_title_bar ) {
			render.text( form.position.x + x + 3, form.position.y + y, name.c_str( ), menu::menu_font, color( 255, 255, 255 ) );
		}

		/* think */
		this->think( );

		/* controls */
		this->end( x, y, w, h );
	}
}