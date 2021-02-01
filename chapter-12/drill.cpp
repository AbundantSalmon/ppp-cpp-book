#include "Graph.h"
#include "Simple_window.h"

int main()
{
    Graph_lib::Point tl{100, 100};
    Simple_window win{tl, 600, 400, "Canvas"};
    win.wait_for_button();
}