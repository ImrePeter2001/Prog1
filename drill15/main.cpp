/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

double one(double x){
	return 1;
}

double slope(double x){
	return x/2;
}

double square(double x){
	return x*x;
}

double sloping_cos(double x){
	return cos(x)+slope(x);
}

int main()
{	
	Point origio{300,300};

	Simple_window win(Point{100,100},600,600,"Function graphs");

	Axis x{Axis::x,Point{100,300},400,20,"1==20 pixels"};
	x.set_color(Color::red);
	win.attach(x);

	Axis y{Axis::y,Point{300,500},400,20,"1==20 pixels"};
	y.set_color(Color::red);
	win.attach(y);

	int min_range=-10;
	int max_range=11;
	int points=400;
	int scale_x=20;
	int scale_y=20;

	Function func_one(one,min_range,max_range,origio,points,scale_x,scale_y);
	Function func_slp(slope,min_range,max_range,origio,points,scale_x,scale_y);
		Text txt{Point{100,420},"x/2"};
		win.attach(txt);	
	Function func_sqr(square,min_range,max_range,origio,points,scale_x,scale_y);
	Function func_cos(cos,min_range,max_range,origio,points,scale_x,scale_y);
		func_cos.set_color(Color::blue);
	Function func_slp_cos(sloping_cos,min_range,max_range,origio,points,scale_x,scale_y);

	win.attach(func_one);
	win.attach(func_slp);
	win.attach(func_sqr);
	win.attach(func_cos);
	win.attach(func_slp_cos);

	win.wait_for_button();

}
