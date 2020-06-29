#pragma once
#include "../../menu.hpp"

namespace ui {
	class tabs {
	public:
		void tab_think_rect( );
		void tab_think( );
		void create_tab( );
		void tab_button( );

		int tab_selected = 0;
	};
	extern tabs tab;
}