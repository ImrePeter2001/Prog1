/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Simple_window win {Point{100,100},600,400,"My window"};

    Axis xa {Axis::x, Point{20,300}, 280, 10, " axis"};
    win.attach(xa); 
	win.set_label("Canvas #2"); 
	

	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
	ya.set_color(Color::blue); 
	ya.label.set_color(Color::red); 
	win.attach(ya);
	win.set_label("Canvas #3");
	

	Function sine {sin,0,100,Point{20,150},1000,50,50}; 
	win.attach(sine);
	win.set_label("Canvas #4");
	

	sine.set_color(Color::green); 
	Polygon poly; 
	poly.add(Point{300,200}); 
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("Canvas #5");
	

	Rectangle r {Point{200,200}, 100, 50}; 
	win.attach(r);
	win.set_label("Canvas #6");
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);

	poly_rect.add(Point{50,75});

	r.set_fill_color(Color::black); 
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::yellow);
	win.set_label("Canvas #7");
	
	Text t {Point{100,150}, "Hello, graphical world!"};
	win.attach(t);
	win.set_label("Canvas #8");

	t.set_font(Font::times_bold);
	t.set_font_size(23);
	win.set_label("Canvas #9");

	//Image ii {Point(50,25),"badge.jpg"}; 
	//win.attach(ii);
	//win.set_label("Canvas #10");
	//ii.move(100,100);
	//win.set_label("Canvas #11");

	win.wait_for_button();
}

