#pragma once
#include "../gui/gui.hpp"
#include "../gui/render/render.hpp"
#include <chrono>
#include "../other/vec2.hpp"

/* include controls */
#include "controls/window/window.hpp"
#include "controls/tabs/tabs.hpp"
#include "controls/groupboxes/groupbox.hpp"
#include "controls/checkbox/checkbox.hpp"
#include "controls/slider/slider.hpp"
#include "controls/combobox/combo.hpp"

enum
{
	check_box_control,
	slider,
	combo_box_control,
	multi_box
};

namespace menu {
	long __stdcall wndproc( HWND hwnd , UINT msg , WPARAM wparam , LPARAM lparam );
	void create( );
	void destroy( );
	void reset( );
	void init( );;
	void initialize( );
	


	static enum
	{
		check_box_control,
		slider,
		combo_box_control,
		multi_box
	};

	
	inline LPD3DXFONT menu_title_font;
	inline LPD3DXFONT menu_font;
	inline LPD3DXFONT main_logo;
	static std::shared_ptr< ui::window > window;
	inline bool initialized = false;

#define FIND( type, object, object_name, object_type ) \
static auto& object = *( type* ) window->find_obj( std::string( object_name ), object_type )
}
