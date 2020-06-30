#include "menu.hpp"


/* animation for begin */
int begin_g_alpha[ 9999 ];
int begin_h_alpha[ 9999 ];
int begin_o_alpha[ 9999 ];


void menu::create( )
{

	/* we will use this function to create our fonts */
	renderer::create_font( ( void** )&menu_title_font, "Josefin Sans Regular", 19, 0 | FW_REGULAR );
	renderer::create_font( ( void** ) &menu_font , "Verdana" , 16 , FW_NORMAL );
	renderer::create_font( ( void** ) &main_logo, "Verdana", 40, FW_NORMAL | FW_DEMIBOLD );
	
}

void menu::destroy( )
{
	if ( menu_title_font ) menu_title_font->Release( );
	if ( menu_font) menu_font->Release( );

}

void menu::reset( )
{
	create( );
}

void menu::init( ) {
	/* 2k17.club watermark */ {
		ui::render.rect( 499, 29, 401, 30, color( 255, 255, 255, 255 ) );
		ui::render.filled_rect( 500, 30, 400, 30, color( 15, 15, 15, 245 ) );
		ui::render.text( 520, 37, "stellarhook.xyz | alpha | user: space | fps : 700", menu_font, color( 255, 255, 255, 255 ) );

	}
	/* main style watermark */ {
		ui::render.filled_rect( 500, 30, 380, 30, color( 15, 15, 15, 245 ) );
		ui::render.gradient_rect( 500, 30, 380, 3, color( 92, 55, 0 ), color( 255, 152, 0 ), true );
		ui::render.text( 540, 37, "| stellarhook.xyz | alpha | user: space |", menu_font, color( 255, 255, 255, 255 ) );

	}
	/* logo watermark */ {
		/* LOGO */ {
			/* main rect */
			ui::render.filled_rect( 500, 30, 50, 50, color( 15, 15, 15, 245 ) );
			ui::render.rect( 500, 30, 50, 50, color( 255, 255, 255, 255 ) );
			ui::render.text( 513, 35, "S", main_logo, color( 255, 255, 255, 255 ) );
		}

	}

}

long __stdcall menu::wndproc( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam )
{
	if ( !initialized )
		return false;

	return ui::c_window.wndproc( hwnd, msg, wparam, lparam );
}

void menu::initialize( ) {
	create( );
	 
	/* checkbox test */
	static bool test = false;
	static bool test2 = false;

	static int test_slider = 0;
	static int test_combo = 0;

	/* combo help */
	std::string xd_test[] = { "off", "xd" };

	ui::form.draw( "menu", 1 );
	/* draw tabs */ ui::tab.tab_button( );

	/* tabs */
	switch ( ui::tab.tab_selected ) {
		case 0: {
			ui::begin_child.draw( 10, 70, ui::form.width / 2 - 15, ui::form.height - 80, "name", ui::child_flags::child_animation, 1 );
			ui::check.draw( " test", &test, ui::checkbox_flags::check_featured, 1 );
			ui::check.draw( " 22", &test, ui::checkbox_flags::check_featured, 2 );

			ui::begin_child.draw( 10 + ui::form.width / 2 - 15 + 10, 70, ui::form.width / 2 - 15, ui::form.height - 80, "test", ui::child_flags::child_animation, 2 );
		} break;
		case 1: {

		} break;
	}
}