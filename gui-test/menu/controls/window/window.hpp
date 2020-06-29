#pragma once
#include "../../menu.hpp"

namespace ui {
	enum window_flags {
		outline,
		title_bar,
		skeet_border
	};

	class main_form {
	public:
		void think( );
		void draw( std::string title, int anim );


		/* controls */
		void start( );
		void end( );

		/* get the mouse positions */
		static vec2_t old_position;
		static vec2_t mouse_position;

		/* size */
		int width = 600;
		int height = 400;

		/* theme var */
		theme_t theme = theme_t( );

		/* drag system */
		int drag_x = 0;
		int drag_y = 0;

		/* variables */
		bool hovered = false;
		bool switch_pulse = false;

		/* pulsating */
		float pulsating;
		float pulsating2;

		/* position */
		struct
		{
			float x = 0.f, y = 0.f;
		} position;

		/* controls */
		int controls_x;
		int group_tab_bottom;
		int offset_y;
		int old_offset_y;
		int tab_offset;
		int sub_tab_offset;
		float sub_tab_size; 
		float tab_size;
		int group_tab_position[ 4 ];
		int groupbox_width;
		int groupbox_bottom;
		int groupbox_top;
		int tab_num = 0;
		int sub_tab_num = 0;
		int previous_control = -1;

	};
	extern main_form form;
}
