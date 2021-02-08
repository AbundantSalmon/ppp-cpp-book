#pragma once
#include "../fltk/Graph.h"

// chapter 13 exercise 19
// define a class Star, one parameter should be the number of points
namespace Userdefined_Shapes
{
    class Star : public Graph_lib::Closed_polyline
    {
    public:
        Star(Graph_lib::Point center, int number_of_points, int outer_radius, int inner_radius) // constructor
            : m_number_of_points{number_of_points},
              m_outer_radius{outer_radius},
              m_inner_radius{inner_radius}
        {
            construct_star(center);
        }
        Star(Graph_lib::Point center, int number_of_points) // constructor
            : m_number_of_points{number_of_points}
        {
            construct_star(center);
        }
        Star(Graph_lib::Point center) // constructor
        {
            construct_star(center);
        }

    private:
        int m_number_of_points{5};
        int m_outer_radius{50};
        int m_inner_radius{25};
        void construct_star(const Graph_lib::Point &center);
    };

} // namespace Userdefined_Shapes