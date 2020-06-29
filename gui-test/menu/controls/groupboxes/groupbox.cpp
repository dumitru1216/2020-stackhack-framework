#include "groupbox.hpp"

namespace ui {
	child begin_child;

	/* child think */
	void child::think( ) {

	}

	void child::begin( ) {

	}

	void child::end( int x, int y, int w, int h ) {
		form.controls_x = form.position.x + x;
		form.groupbox_bottom = ( form.position.y + ( y + h ) );
		form.groupbox_width = ( form.position.x + ( x + w ) );
	}

	/* child draw */
	void child::draw( int x, int y, int w, int h, std::string name ) {
		/* render group */
		render.filled_rect( form.position.x + x, form.position.y + y, w, h, color( 255, 15, 15 ) );
		render.rect( form.position.x + x, form.position.y + y, w, h, color( 35, 35, 35 ) );

		/* rect */
		render.rect( form.position.x + x, form.position.y + y + h - 19, w, 22, color( 35, 35, 35 ) );

		/* flame effect : low bugget*/
		render.gradient_rect( form.position.x + x, form.position.y + y + h, w, 7, color( 255, 0, 0, 230 ), color( 110, 0, 0, 30 ), false );

		/* render name */
		render.text( form.position.x + x + w / 2 - 12, form.position.y + y + h - 18, name, menu::menu_title_font, color( 255, 255, 255 ) );

		/* think */
		this->think( );

		/* controls */
		this->end( x, y, w, h );
	}
}