#include "window.hpp"

namespace ui {
	main_form form;

	/* window start */
	void main_form::start( ) {
		this->group_tab_position[ 0 ] = this->position.x + 85;
		this->group_tab_position[ 1 ] = this->position.y + 25;
		this->group_tab_position[ 2 ] = this->width - 91;
		this->group_tab_position[ 3 ] = this->height - 50;
		this->controls_x = this->group_tab_position[ 0 ];
		this->group_tab_bottom = this->group_tab_position[ 1 ] + this->group_tab_position[ 3 ];
		this->offset_y = this->group_tab_position[ 1 ] + 7;
		this->tab_offset = 0;
		this->sub_tab_offset = 0;
		this->previous_control = -1;
		this->old_offset_y = 0;

	}

	/* window end */
	void main_form::end( ) {
		this->tab_size = this->tab_offset;
		this->sub_tab_size = this->sub_tab_offset;
	}
	static bool dragging = false;

	/* window think */
	void main_form::think( ) {
		/* variables */
		bool click = false;

		/* when clicked */
		if ( GetAsyncKeyState( VK_LBUTTON ) )
			click = true;

		/* get mouse pos */
		renderer::pos mouse_pos;
		ui::render.mouse_pos( mouse_pos );

		/* dragging position */
		static decltype( this->position )
			dragging_pos{ 0, 0 };

		/* setup dragging */
		if ( dragging && !click )
		{
			dragging = false;
		}

		/* get dragging position */
		if ( dragging && click )
		{
			this->position.x = mouse_pos.x - dragging_pos.x;
			this->position.y = mouse_pos.y - dragging_pos.y;
		}

		/* if we're 'dragging' */
		if ( ui::render.mouse_in_region( this->position.x, this->position.y, this->width, 30 ) ) {
			dragging = true;
			dragging_pos.x = mouse_pos.x - this->position.x;
			dragging_pos.y = mouse_pos.y - this->position.y;
		}
	}

	/* window draw */
	void main_form::draw( std::string title, int anim ) {
		this->think( );

		/* start controls */
		this->start( );

		/* for animation */
		static int main_rect_animation1[ 9999 ];
		static int main_rect_animation2[ 9999 ];
		static bool hovered = false;

		/* get the mouse position when hovered for drag */
		if ( render.mouse_in_region( this->position.x, this->position.y, this->width, 50 /* i dont need full dragging animation */ ) ) {
			hovered = true;
		}
		else {
			hovered = false;
		}

		/* main window setup */
		render.filled_rect( this->position.x, this->position.y, this->width, this->height, this->theme.backround_color );
		render.rect( this->position.x, this->position.y, this->width, this->height, color( 120, 120, 120, main_rect_animation2[ anim ] ) );
		
		/* tab rect looks better im think u can turn off outlines with flags : configurating that in " window.cpp " */
		if ( !window_flags::outline ) {
			/* tab rect */
			/* doing that auto spacing : this dont working idk why prob bcz im braindead rn */
		
			if ( window_flags::title_bar ) {
				render.rect( this->position.x + 5, this->position.y + 25, this->width - 10, 35, color( 120, 120, 120 ) );
			}
			else {
				render.rect( this->position.x + 5, this->position.y + 5, this->width - 10, 35, color( 120, 120, 120 ) );
			}

		}

		/* title bar : need to fix spacing btw */
		if ( window_flags::title_bar ) {
			/* im gonna fix auto spacing */
			if ( dragging && GetAsyncKeyState( VK_LBUTTON ) ) {
				render.text( this->position.x + this->width / 2 - 95, this->position.y + 5, " the menu are in drag mode ", menu::menu_font, color( 255, 255, 255, 255 ) );
			}
			else {
				render.text( this->position.x + 5, this->position.y + 5, " stackhack ui 2020 - created by Dutu#6952 ", menu::menu_font, color( 255, 255, 255 ) );
			}
		}

		/* setup animation */ {
			if ( hovered ) {
				main_rect_animation1[ anim ] = 0;
				if ( anim > 0 ) {
					if ( main_rect_animation2[ anim ] < 255 ) {
						main_rect_animation2[ anim ] += 2;
					}
					else {
						main_rect_animation2[ anim ] = 255;
					}
				}
			}
			else {
				main_rect_animation2[ anim ] = 0;
				if ( anim > 0 ) {
					if ( main_rect_animation1[ anim ] < 255 ) {
						main_rect_animation1[ anim ] += 2;
					}
					else {
						main_rect_animation1[ anim ] = 255;
					}
				}

			}
		}		

		/* end controls */
		this->end( );
	}
}