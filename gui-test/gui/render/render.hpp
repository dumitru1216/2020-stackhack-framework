#ifndef RENDER_HPP
#define RENDER_HPP

#include <functional>
#include <vector>
#include "../../other/color.hpp"
#include "../../other/renderer/renderer.hpp"
namespace ui {

	/* many things shouldn't actually be in render.hpp, but since making another file for all of these is useless... */
	class dividers {
	public:
		std::vector< int > columns_per_row;
	};

	struct render {

		virtual void clip( renderer::rect area, std::function< void( ) > func ) {
			RECT backup_scissor_rect;
			renderer::device->GetScissorRect( &backup_scissor_rect );

			RECT rect{ area.x - 0.5f, area.y - 0.5f, area.x + area.w - 0.5f, area.y + area.h - 0.5f };
			renderer::device->SetRenderState( D3DRS_SCISSORTESTENABLE, true );
			renderer::device->SetScissorRect( &rect );

			func( );

			renderer::device->SetScissorRect( &backup_scissor_rect );
			renderer::device->SetRenderState( D3DRS_SCISSORTESTENABLE, false );
		}

		virtual void filled_rect( int x, int y, int width, int height, color color ) {
			renderer::rectangle( x, y, width, height, color.to_d3d( ) );
		}

		virtual void filled_rect( renderer::rect r, color color ) {
			filled_rect( r.x, r.y, r.w, r.h, color );
		}

		virtual void filled_rect( renderer::pos p, renderer::dim d, color color ) {
			filled_rect( p.x, p.y, d.w, d.h, color );
		}

		virtual void gradient_rect( int x, int y, int width, int height, color color1, color color2, bool horizontal ) {
			renderer::gradient( x, y , width, height , color1.to_d3d( ), color2.to_d3d( ), horizontal );
		}
	
		virtual void rect( int x , int y , int width , int height , color color ) {
			renderer::outline( x , y , width , height , color.to_d3d( ) );
		}

		virtual void rect( renderer::rect r , color color ) {
			rect( r.x , r.y , r.w , r.h , color );
		}

		virtual void rect( renderer::pos p , renderer::dim d , color color ) {
			rect( p.x , p.y , d.w , d.h , color );
		}

		virtual renderer::dim text_size( std::string text , LPD3DXFONT font ) {
			renderer::dim size;
			renderer::text_size( ( void* ) font , text , size );
			return size;
		}

		virtual void text( int x , int y , std::string t , LPD3DXFONT f , color c ) {
			renderer::text( x , y , c.to_d3d( ) , ( void* ) f , t );
		}

		virtual void text( renderer::pos p , std::string t , LPD3DXFONT f , color c ) {
			text( p.x , p.y , t , f , c );
		}

		virtual void screen_size( int& w , int& h ) {
			renderer::screen_size( w , h );
		}

		virtual void screen_size( renderer::dim& s ) {
			screen_size( s.w , s.h );
		}

		virtual void mouse_pos( int& x , int& y ) {
			renderer::pos p;
			renderer::mouse_pos( p );
			x = p.x;
			y = p.y;
		}


		virtual void mouse_pos( renderer::pos& p ) {
			mouse_pos( p.x , p.y );
		}

		virtual bool mouse_in_region( int x , int y , int w , int h ) {
			renderer::pos mpos;
			mouse_pos( mpos );

			if ( mpos.x > x && mpos.y > y && mpos.x < x + w && mpos.y < y + h )
				return true;

			return false;
		}

		virtual bool mouse_in_region( renderer::pos p1 , renderer::pos p2 ) {
			return mouse_in_region( p1.x , p1.y , p2.x , p2.y );
		}

		virtual bool mouse_in_region( renderer::pos p , renderer::dim d ) {
			return mouse_in_region( p.x , p.y , d.w , d.h );
		}

		virtual bool mouse_in_region( renderer::rect r ) {
			return mouse_in_region( r.x , r.y , r.w , r.h );
		}

		virtual bool mouse_click_in_region( int x , int y , int w , int h ) {
			static bool m_clicked = false;
			if ( !m_clicked && GetAsyncKeyState( VK_LBUTTON ) ) {
				if ( mouse_in_region( x , y , w , h ) ) {
					m_clicked = true;
					return true;
				}
			}
			else if ( m_clicked && !GetAsyncKeyState( VK_LBUTTON ) ) {
				m_clicked = false;
			}

			return false;
		}

		virtual bool mouse_click_in_region( renderer::pos p1 , renderer::pos p2 ) {
			return mouse_click_in_region( p1.x , p1.y , p2.x , p2.y );
		}

		virtual bool mouse_click_in_region( renderer::pos p , renderer::dim d ) {
			return mouse_click_in_region( p.x , p.y , d.w , d.h );
		}

		virtual bool mouse_click_in_region( renderer::rect r ) {
			return mouse_click_in_region( r.x , r.y , r.w , r.h );
		}

	}static render;
}

#endif // !RENDER_HPP