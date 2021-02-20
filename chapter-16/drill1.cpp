#include "../fltk/Graph.h"
#include "../fltk/Simple_window.h"
#include "Lines_window.h"

int main()
{
    try
    {
        Lines_window win{Graph_lib::Point{100, 100}, 600, 400, "lines"};
        return gui_main();
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