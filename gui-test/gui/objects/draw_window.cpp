#include <algorithm>
#include "draw_window.hpp"


namespace ui {
	window c_window;
	void window::think( ) {

		/* get screen size */
		renderer::dim screen_size;
		render.screen_size( screen_size );

		/* get mouse pos */
		renderer::pos mouse_pos;
		render.mouse_pos( mouse_pos );

		/* dragging system */
		if ( this->theme.draggable ) {
			static bool m_dragging = false;
			bool m_click = false;

			static decltype( this->pos ) dragging_pos { 0, 0 };

			if ( this->opened ) {
				/* drag menu etc. */
				if ( GetAsyncKeyState( VK_LBUTTON ) ) {
					m_click = true;
				}

				if ( m_dragging && !m_click )
				{
					m_dragging = false;
				}

				if ( m_dragging && m_click )
				{
					this->pos.x = mouse_pos.x - dragging_pos.x;
					this->pos.y = mouse_pos.y - dragging_pos.y;
				}

				/* if we're 'dragging' */
				if ( render.mouse_in_region( this->pos.x , this->pos.y , this->dim.w , this->theme.drag_title ? this->theme.titlebar_size : this->dim.h ) ) {
					m_dragging = true;
					dragging_pos.x = mouse_pos.x - this->pos.x;
					dragging_pos.y = mouse_pos.y - this->pos.y;
				}
			}
		}

		/* clamp window pos on screen */ {
			if ( this->pos.x < 0 )
				this->pos.x = 0;

			if ( this->pos.y < 0 )
				this->pos.y = 0;

			if ( ( this->pos.x + this->dim.w ) > screen_size.w )
				this->pos.x = screen_size.w - this->dim.w;

			if ( ( this->pos.y + this->dim.h ) > screen_size.h )
				this->pos.y = screen_size.h - this->dim.h;
		}

		/* toggle open */
		if ( this->key != -1 ) {
			static bool m_pressed = false;
			const bool m_held = GetAsyncKeyState( this->key );
			if ( m_pressed != m_held ) {
				if ( m_held ) {
					this->opened = !this->opened;
				}

				m_pressed = m_held;
			}
		}

		/* set actual cursor position */
		this->cursor_pos = this->pos;
	}

	void window::window_draw( int w, int h, color c, std::string window_name ) {

		/* think before drawing */
		think( );

		/* draw main window */
		render.filled_rect( pos.x, pos.y, w, h, c );

		/* render the title bar */
		render.rect( pos.x, pos.y, w - 1, 25, color( 255, 255, 255, 120 ) );
		render.text( pos.x / 2, pos.y, window_name, title_font, color(255, 255, 255, 255) );

		
			

	}
}
