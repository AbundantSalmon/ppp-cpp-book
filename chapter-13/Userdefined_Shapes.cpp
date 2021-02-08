#include "Userdefined_Shapes.h"
#include "../fltk/Graph.h"
#include <cmath>

namespace Userdefined_Shapes
{
    static const float pi{3.14159265359};

    float convert_to_radian(float degrees)
    {
        return degrees / 180.0 * pi;
    }

    // Star Class Members:
    void Star::construct_star(const Graph_lib::Point &center)
    {
        assert(m_outer_radius > m_inner_radius);
        assert(m_number_of_points >= 3);
        for (int i{0}; i < m_number_of_points; i += 1)
        {
            // outer point
            int x1 = center.x + m_outer_radius * std::sin(convert_to_radian(i * 360 / m_number_of_points - 360 / m_number_of_points / 2)); //implicit conversion from float to int
            int y1 = center.y + m_outer_radius * std::cos(convert_to_radian(i * 360 / m_number_of_points - 360 / m_number_of_points / 2)); //implicit conversion from float to int
            // inner point
            int x2 = center.x + m_inner_radius * std::sin(convert_to_radian(i * 360 / m_number_of_points)); //implicit conversion from float to int
            int y2 = center.y + m_inner_radius * std::cos(convert_to_radian(i * 360 / m_number_of_points)); //implicit conversion from float to int

            Closed_polyline::add(Graph_lib::Point{x1, y1});
            Closed_polyline::add(Graph_lib::Point{x2, y2});
        }
    }
} // namespace Userdefined_Shapes