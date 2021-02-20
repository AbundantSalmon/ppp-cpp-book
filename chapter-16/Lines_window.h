#pragma once

#include "../fltk/Window.h"
#include "../fltk/Graph.h"
#include "../fltk/GUI.h"

struct Lines_window : Graph_lib::Window
{
public:
    Lines_window(Graph_lib::Point xy, int w, int h, const string &title);

private:
    Graph_lib::Button next_button; // add (next_x, next_y) to lines
    Graph_lib::Button quit_button;
    Graph_lib::In_box next_y;
    Graph_lib::In_box next_x;
    Graph_lib::Out_box xy_out;
    Graph_lib::Open_polyline lines;
    Graph_lib::Menu color_menu;
    Graph_lib::Button color_menu_button;
    Graph_lib::Menu line_style_menu;

    // callback function
    static void cb_red(Graph_lib::Address, Graph_lib::Address pw);         // callback for red button
    static void cb_blue(Graph_lib::Address, Graph_lib::Address pw);        // callback for blue button
    static void cb_black(Graph_lib::Address, Graph_lib::Address pw);       // callback for black button
    static void cb_colour_menu(Graph_lib::Address, Graph_lib::Address pw); // callback for color menu button

    static void cb_solid(Graph_lib::Address, Graph_lib::Address pw); // callback for red button
    static void cb_dot(Graph_lib::Address, Graph_lib::Address pw);   // callback for blue button
    static void cb_dash(Graph_lib::Address, Graph_lib::Address pw);  // callback for black button

    // the actions
    void next();
    void quit();
    void change_color(Graph_lib::Color c);
    void red_pressed();
    void blue_pressed();
    void black_pressed();
    void hide_color_menu();
    void change_line_style(Graph_lib::Line_style ls);
    void solid_pressed();
    void dot_pressed();
    void dash_pressed();
};