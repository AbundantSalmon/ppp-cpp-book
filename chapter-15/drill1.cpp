#include "../fltk/Graph.h"
#include "../fltk/Simple_window.h"

// one function
double one(double x)
{
    return 1;
}

// slope function
double slope(double x)
{
    return x / 2;
}

// square function
double square(double x)
{
    return x * x;
}

// sloping_cos function
double sloping_cos(double x)
{
    return slope(x) + cos(x);
}

// int main()
// {
//     try
//     {
//         Graph_lib::Point tl{100, 100};
//         Simple_window win{tl, 600, 600, "Function Graphs"};

//         // generate axes
//         Graph_lib::Axis xAxis{Graph_lib::Axis::x, Point{100, 300}, 400, 400 / 20, "1==20 pixels"};
//         Graph_lib::Axis yAxis{Graph_lib::Axis::y, Point{300, 500}, 400, 400 / 20, "1==20 pixels"};
//         xAxis.set_color(Graph_lib::Color::red);
//         yAxis.set_color(Graph_lib::Color::red);
//         win.attach(xAxis);
//         win.attach(yAxis);

//         // generate functions
//         double range_min{-10};
//         double range_max{11};
//         double xScale{20};
//         double yScale{20};

//         Graph_lib::Function oneGraph{one, range_min, range_max, Point{300, 300}, 400, xScale, yScale};
//         Graph_lib::Function slopeGraph{slope, range_min, range_max, Point{300, 300}, 400, xScale, yScale};
//         Graph_lib::Text slopeGraphLabel{Point{100, 430}, "x/2"};
//         Graph_lib::Function squareGraph{square, range_min, range_max, Point{300, 300}, 400, xScale, yScale};
//         Graph_lib::Function cosineGraph{cos, range_min, range_max, Point{300, 300}, 400, xScale, yScale};
//         cosineGraph.set_color(Graph_lib::Color::blue);
//         Graph_lib::Function slopingCosGraph{sloping_cos, range_min, range_max, Point{300, 300}, 400, xScale, yScale};
//         win.attach(oneGraph);
//         win.attach(slopeGraph);
//         win.attach(slopeGraphLabel);
//         win.attach(squareGraph);
//         win.attach(cosineGraph);
//         win.attach(slopingCosGraph);

//         win.wait_for_button();

//         return 0;
//     }
//     catch (const std::exception &e)
//     {
//         std::cerr << e.what() << '\n';
//         return 1;
//     }
//     catch (...)
//     {
//         return 2;
//     }
// }