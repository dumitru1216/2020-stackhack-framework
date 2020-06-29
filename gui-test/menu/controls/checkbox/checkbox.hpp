#pragma once
#include "../../menu.hpp"

namespace ui {
	class checkbox {
	public:
		void begin( );
		void end( );
		void draw( std::string name, bool* item );
		
		

	};
	extern checkbox check;
}
