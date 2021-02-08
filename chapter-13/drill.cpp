#include "../fltk/Graph.h"
#include "../fltk/Simple_window.h"
#include <random>
#include "Userdefined_Shapes.h"

int main()
{
    // intialise random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 6);

    try
    {
        Graph_lib::Point tl{100, 100};
        Simple_window win{tl, 800, 1000, "Chapter 13 Drill"};

        // make 8 by 8 grid of 100 by 100 px in the left most part of the window
        Graph_lib::Lines grid;
        for (int i{0}; i <= 800; i += 100)
        {
            grid.add(Point{i, 0}, Point{i, 800});
        }
        for (int j{0}; j <= 800; j += 100)
        {
            grid.add(Point{0, j}, Point{800, j});
        }
        win.attach(grid);

        // create a diagonal of red rectangle
        Graph_lib::Vector_ref<Graph_lib::Rectangle> list_of_rectangles;
        for (int i{0}; i < 800; i += 100)
        {
            list_of_rectangles.push_back(new Rectangle(Point{i, i}, Point{i + 100, i + 100}));
            list_of_rectangles[list_of_rectangles.size() - 1].set_fill_color(Color::red);
            win.attach(list_of_rectangles[list_of_rectangles.size() - 1]);
        }

        // put 3 copies of a 200x200 image on the grid
        Graph_lib::Image cat1{Point{200, 0}, "cat.jpg"};
        Graph_lib::Image cat2{Point{0, 600}, "cat.jpg"};
        Graph_lib::Image cat3{Point{500, 600}, "cat.jpg"};

        win.attach(cat1);
        win.attach(cat2);
        win.attach(cat3);

        // add user defined star
        Userdefined_Shapes::Star star{Point{400, 400}, 7, 200, 100};

        win.attach(star);

        // put a 100x100 image in the window and move when ever next button is clicked
        Graph_lib::Image puppy1{Point{100, 0}, "puppy.jpg"};
        win.attach(puppy1);

        win.wait_for_button();

        // move 100x100 image around randomly
        while (true)
        {
            Point current_location = puppy1.point(0);
            int i{distrib(gen) * 100};
            int j{distrib(gen) * 100};

            std::cout << i << " , " << j << std::endl;

            puppy1.move(i - current_location.x, j - current_location.y);
            win.wait_for_button();
        }

        return 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    catch (...)
    {
        return 2;
    }
}