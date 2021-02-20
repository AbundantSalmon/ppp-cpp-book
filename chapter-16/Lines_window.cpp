#include "Lines_window.h"
#include "../fltk/Window.h"

Lines_window::Lines_window(Graph_lib::Point xy, int w, int h, const string &title)
    : Graph_lib::Window{xy, w, h, title},
      next_button{
          Graph_lib::Point{x_max() - 150, 0}, 70, 20, "New point", [](Graph_lib::Address, Graph_lib::Address pw) { Graph_lib::reference_to<Lines_window>(pw).next(); }},
      quit_button{
          Graph_lib::Point{x_max() - 70, 0}, 70, 20, "Quit", [](Graph_lib::Address, Graph_lib::Address pw) { Graph_lib::reference_to<Lines_window>(pw).quit(); }},
      next_x{Graph_lib::Point{x_max() - 310, 0}, 50, 20, "next x:"},
      next_y{Graph_lib::Point{x_max() - 210, 0}, 50, 20, "next y:"},
      xy_out{Graph_lib::Point{100, 0}, 100, 20, "current (x,y):"},
      color_menu{Graph_lib::Point{x_max() - 70, 40}, 70, 20, Graph_lib::Menu::vertical, "color"},
      color_menu_button{Graph_lib::Point{x_max() - 80, 40}, 80, 20, "Colour Menu", cb_colour_menu},
      line_style_menu{Graph_lib::Point{x_max() - 70, 120}, 70, 20, Graph_lib::Menu::vertical, "line style"}
{
    attach(next_button);
    attach(quit_button);
    attach(next_x);
    attach(next_y);
    attach(xy_out);
    attach(lines);

    color_menu.attach(new Graph_lib::Button{Graph_lib::Point{0, 0}, 0, 0, "red", cb_red});
    color_menu.attach(new Graph_lib::Button{Graph_lib::Point{0, 0}, 0, 0, "blue", cb_blue});
    color_menu.attach(new Graph_lib::Button{Graph_lib::Point{0, 0}, 0, 0, "black", cb_black});
    attach(color_menu);
    color_menu.hide();

    attach(color_menu_button);

    line_style_menu.attach(new Graph_lib::Button{Graph_lib::Point{0, 0}, 0, 0, "solid", cb_solid});
    line_style_menu.attach(new Graph_lib::Button{Graph_lib::Point{0, 0}, 0, 0, "dot", cb_dot});
    line_style_menu.attach(new Graph_lib::Button{Graph_lib::Point{0, 0}, 0, 0, "dash", cb_dash});
    attach(line_style_menu);
}

// member functions
void Lines_window::quit()
{
    hide(); // curious FKLK idiom to delete window
}

void Lines_window::next()
{
    int x = next_x.get_int();
    int y = next_y.get_int();

    lines.add(Graph_lib::Point{x, y});

    // update current position readout:
    ostringstream ss;
    ss << '(' << x << ',' << y << ')';
    xy_out.put(ss.str());

    redraw();
}

// colour menu functions
void Lines_window::change_color(Graph_lib::Color c)
{
    lines.set_color(c);
}
void Lines_window::red_pressed()
{
    change_color(Graph_lib::Color::red);
}
void Lines_window::blue_pressed()
{
    change_color(Graph_lib::Color::blue);
}
void Lines_window::black_pressed()
{
    change_color(Graph_lib::Color::black);
}
void Lines_window::hide_color_menu()
{
    color_menu.hide();
    color_menu_button.show();
}

// line style functions
void Lines_window::change_line_style(Graph_lib::Line_style ls)
{
    lines.set_style(ls);
}
void Lines_window::solid_pressed()
{
    change_line_style(Graph_lib::Line_style::solid);
}
void Lines_window::dot_pressed()
{
    change_line_style(Graph_lib::Line_style::dot);
}
void Lines_window::dash_pressed()
{
    change_line_style(Graph_lib::Line_style::dash);
}

// call back functions
void Lines_window::cb_red(Graph_lib::Address, Graph_lib::Address pw) // callback for red button
{
    Graph_lib::reference_to<Lines_window>(pw).red_pressed();
    Graph_lib::reference_to<Lines_window>(pw).hide_color_menu();
}
void Lines_window::cb_blue(Graph_lib::Address, Graph_lib::Address pw) // callback for blue button
{
    Graph_lib::reference_to<Lines_window>(pw).blue_pressed();
    Graph_lib::reference_to<Lines_window>(pw).hide_color_menu();
}
void Lines_window::cb_black(Graph_lib::Address, Graph_lib::Address pw) // callback for black button
{
    Graph_lib::reference_to<Lines_window>(pw).black_pressed();
    Graph_lib::reference_to<Lines_window>(pw).hide_color_menu();
}
void Lines_window::cb_colour_menu(Graph_lib::Address, Graph_lib::Address pw) // callback for menu button
{
    Graph_lib::reference_to<Lines_window>(pw).color_menu.show();
    Graph_lib::reference_to<Lines_window>(pw).color_menu_button.hide();
}
void Lines_window::cb_solid(Graph_lib::Address, Graph_lib::Address pw) // callback for red button
{
    Graph_lib::reference_to<Lines_window>(pw).solid_pressed();
}
void Lines_window::cb_dot(Graph_lib::Address, Graph_lib::Address pw) // callback for blue button
{
    Graph_lib::reference_to<Lines_window>(pw).dot_pressed();
}
void Lines_window::cb_dash(Graph_lib::Address, Graph_lib::Address pw) // callback for black button
{
    Graph_lib::reference_to<Lines_window>(pw).dash_pressed();
}