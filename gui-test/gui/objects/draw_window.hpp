#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <functional>
#include <memory>
#include <vector>
#include "object.hpp"
namespace ui {

	enum window_flags_t {
		show_titlebar,
		show_animation
	};

	class window {
	public:
		void think( );
		void window_draw( int w, int h, color c, std::string window_name );

		LPD3DXFONT title_font = nullptr;
		LPD3DXFONT font = nullptr;
		std::string title;
		bool opened = true;
		int key = -1;
		renderer::pos pos { 0, 0 };
		renderer::dim dim { 200, 200 };

		/* other vars */
		theme_t theme = theme_t( );
		renderer::pos cursor_pos { 0, 0 };

		/* wnd proc */
		long __stdcall wndproc( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam ) {
			if ( opened ) {

				return true;
			}

			return false;
		}
	};
	extern window c_window;
}

#endif // !WINDOW_HPP