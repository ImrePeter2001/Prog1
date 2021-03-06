/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{	
	using namespace Graph_lib;

// 1.
	Point tl{100,100};
	Simple_window win{tl, 800, 1000, "Window"};

// 2.
	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;

// vertical 
	for (int x=x_grid; x<=x_size; x+=x_grid){
		grid.add(Point{x,0}, Point{x,y_size});
	}

// horizontal 
	for (int y=y_grid; y<=y_size; y+=y_grid)
		grid.add(Point{0,y}, Point{x_size,y});

	win.attach(grid);

// red diagonal
	Vector_ref<Rectangle> rects;
    for (int i = 0; i < x_size; i += x_grid) {
        rects.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        rects[rects.size() - 1].set_color(Color::invisible);
        rects[rects.size() - 1].set_fill_color(Color::red);

        win.attach(rects[rects.size() - 1]);
    }

// 4.
	Image im1 {Point{400,600}, "pikachu.gif"};
	Image im2 {Point{100,300}, "pikachu.gif"};
	Image im3 {Point{600,100}, "pikachu.gif"};

		win.attach(im1);
		win.attach(im2);
		win.attach(im3);
	
// 5.
	while (true){
		int x = rand() % 8;
		int y = rand() % 8;

		Image im4 {Point{x*100,y*100}, "parrot.jpg"};
		win.attach(im4);
		
		win.wait_for_button();
	}
}
