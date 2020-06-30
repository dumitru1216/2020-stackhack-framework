#pragma once
#include "../../menu.hpp"

namespace ui {
	enum combo_flags {
		ouline
	};

	class combobox {
	public:
		void think( );
		void draw( std::string name, int* item, std::string* item_name, int size, int flags );

		/* controls */
		void begin( );
		void end( );
	};
	extern combobox combo;
}