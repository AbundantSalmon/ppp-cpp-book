#include "Graph.h"
#include "Simple_window.h"

int main()
{
    try
    {
        Graph_lib::Point tl{100, 100};
        Simple_window win{tl, 600, 400, "My window"};
        win.wait_for_button();

        // 12.7.3
        Graph_lib::Axis xa{Graph_lib::Axis::x, Point{20, 300}, 280, 10, "x axis"};
        win.attach(xa);
        win.set_label("Canvas #2");
        win.wait_for_button();

        Graph_lib::Axis ya{Graph_lib::Axis::y, Point{20, 300}, 280, 10, "y axis"};
        ya.set_color(Color::cyan);
        ya.label.set_color(Color::dark_red);
        win.attach(ya);
        win.set_label("Canvas #3");
        win.wait_for_button();

        // 12.7.4
        Graph_lib::Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 20};
        win.attach(sine);
        win.set_label("Canvas #4");
        win.wait_for_button();

        // 12.7.5
        sine.set_color(Color::blue);
        Graph_lib::Polygon poly;
        poly.add(Point{300, 200});
        poly.add(Point{350, 100});
        poly.add(Point{400, 200});
        poly.set_color(Color::red);
        poly.set_style(Line_style::dash);
        win.attach(poly);
        win.set_label("Canvas #5");
        win.wait_for_button();

        // The rest of the drill is trival.

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