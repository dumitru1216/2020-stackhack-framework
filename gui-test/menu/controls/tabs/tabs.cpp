#include "tabs.hpp"

namespace ui {
	tabs tab;

	void tabs::create_tab( ) {
		/* we making the rects */
	
		/* setup faster tab position */
		int area = form.width / 5 - 20 + 5;
		int tab_x = form.position.x + form.width / 15;
		int reset_tab = form.width / 5 - 20;

		/* we gonna setup tabs with my nemesis method */
		/* setup tabs */ {
			/* rage */ if ( render.mouse_in_region( tab_x, form.position.y + 30.5, reset_tab, 25 ) && GetAsyncKeyState( VK_LBUTTON ) ) {
				this->tab_selected = 0;
			}
			/* anti-aim */ if ( render.mouse_in_region( tab_x + area, form.position.y + 30.5, reset_tab, 25 ) && GetAsyncKeyState( VK_LBUTTON ) ) {
				this->tab_selected = 1;
			}
			/* visuals */ if ( render.mouse_in_region( tab_x + area * 2, form.position.y + 30.5, reset_tab, 25 ) && GetAsyncKeyState( VK_LBUTTON ) ) {
				this->tab_selected = 2;
			}
			/* misc */ if ( render.mouse_in_region( tab_x + area * 3, form.position.y + 30.5, reset_tab, 25 ) && GetAsyncKeyState( VK_LBUTTON ) ) {
				this->tab_selected = 3;
			}
			/* config */ if ( render.mouse_in_region( tab_x + area * 4, form.position.y + 30.5, reset_tab, 25 ) && GetAsyncKeyState( VK_LBUTTON ) ) {
				this->tab_selected = 4;
			}
		}


		/* filled_rect */ {
			/* rage */ render.filled_rect( tab_x, form.position.y + 25 + 5.5, reset_tab, 25, color( 35, 35, 35 ) );
			/* anti-aim */ render.filled_rect( tab_x + area, form.position.y + 25 + 5.5, reset_tab, 25, color( 35, 35, 35 ) );
			/* visuals */ render.filled_rect( tab_x + area + area, form.position.y + 25 + 5.5, reset_tab, 25, color( 35, 35, 35 ) );
			/* misc */ render.filled_rect( tab_x + area + area + area, form.position.y + 25 + 5.5, reset_tab, 25, color( 35, 35, 35 ) );
			/* config */ render.filled_rect( tab_x + area + area + area + area, form.position.y + 25 + 5.5, reset_tab, 25, color( 35, 35, 35 ) );
		}

		/* tex_size */ 
		/* rage */ renderer::dim rage = render.text_size( "rage", menu::menu_font );
		/* antiaim */ renderer::dim antihit = render.text_size( "anti-aim", menu::menu_font );
		/* visuals */ renderer::dim visuals = render.text_size( "visuals", menu::menu_font );
		/* misc */ renderer::dim misc = render.text_size( "misc", menu::menu_font );
		/* config */ renderer::dim config = render.text_size( "config", menu::menu_font );

		/* tab name */ {
			/* rage */ if ( this->tab_selected == 0 ) {
				render.filled_rect( tab_x, form.position.y + 30.5, 3, 25, color( 255, 0, 0 ) );
				render.text( tab_x + 6, form.position.y + rage.h + 17.5, "rage", menu::menu_font, color( 255, 255, 255 ) );
			}
			else {
				render.text( tab_x + 6, form.position.y + rage.h + 17.5, "rage ", menu::menu_font, color( 255, 255, 255, 120 ) );
			}

			/* anti-aim */ if ( this->tab_selected == 1 ) {
				render.filled_rect( tab_x + area, form.position.y + 30.5, 3, 25, color( 255, 0, 0 ) );
				render.text( tab_x + area+ 4, form.position.y + antihit.h + 17.5, "anti-aim", menu::menu_font, color( 255, 255, 255 ) );
			}
			else {
				render.text( tab_x + area + 4, form.position.y + antihit.h + 17.5, "anti-aim", menu::menu_font, color( 255, 255, 255, 120 ) );
			}
			
			/* visuals */ if ( this->tab_selected == 2 ) {
				render.filled_rect( tab_x + area * 2, form.position.y + 30.5, 3, 25, color( 255, 0, 0 ) );
				render.text( tab_x + area * 2 + 4, form.position.y + visuals.h + 17.5, "visuals", menu::menu_font, color( 255, 255, 255 ) );
			}
			else {
				render.text( tab_x + area * 2 + 4, form.position.y + visuals.h + 17.5, "visuals", menu::menu_font, color( 255, 255, 255, 120 ) );
			}

			/* misc */ if ( this->tab_selected == 3 ) {
				render.filled_rect( tab_x + area * 3, form.position.y + 30.5, 3, 25, color( 255, 0, 0 ) );
				render.text( tab_x + area * 3 + 4, form.position.y + misc.h + 17.5, "misc", menu::menu_font, color( 255, 255, 255 ) );
			}
			else {
				render.text( tab_x + area * 3 + 4, form.position.y + misc.h + 17.5, "misc", menu::menu_font, color( 255, 255, 255, 120 ) );
			}
			
			/* config */ if ( this->tab_selected == 4 ) {
				render.filled_rect( tab_x + area * 4, form.position.y + 30.5, 3, 25, color( 255, 0, 0 ) );
				render.text( tab_x + area * 4 + 4, form.position.y + config.h + 17.5, "config", menu::menu_font, color( 255, 255, 255 ) );
			}
			else {
				render.text( tab_x + area * 4 + 4, form.position.y + config.h + 17.5, "config", menu::menu_font, color( 255, 255, 255, 120 ) );
			}
		}
	}

	/* draw tabs */
	void tabs::tab_button( ) {
		this->create_tab( );
	}
}