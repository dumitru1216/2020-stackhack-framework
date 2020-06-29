#pragma once
#include "../../menu.hpp"

namespace ui {
	class combobox {
	public:
		void think( );
		void draw( int size, std::string name, std::string* itemname, int* item );

		/* controls */
		void begin( );
		void end( );
	};
	extern combobox combo;
}