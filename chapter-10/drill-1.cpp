/**
 * @file drill-1.cpp
 *
 * @author David Hang (abundantsalmon@gmail.com)
 * @brief The end chapter drill for chapter 10 for PPPCPP2
 * @version 0.1
 * @date 2021-01-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <vector>
#include <iostream>
#include <istream>

/**
 * @brief Datatype to hold (x,y) coordinate points
 * 
 */
struct Point
{
public:
    int x; // coordinate x
    int y; // coordinate yß
};

/**
 * @brief extraction operator for "x y" input values for point
 * 
 * @param is input stream
 * @param pp point to extract to
 * @return std::istream& 
 */
std::istream &operator>>(std::istream &is, Point &pp)
{
    // Set stream to throw an exception if bad() condition is encountered
    is.exceptions(is.exceptions() | std::ios_base::badbit);

    int x;
    int y;
    std::cin >> x >> y;

    // if failure occurs, set state to fail and return
    if (std::cin.fail())
    {
        is.clear(std::ios_base::failbit);
        return is;
    }

    //if successful then set Point to entered values.
    pp = Point{x,y};

    return is;
}

int main()
{
    std::vector<Point> original_points;

    std::cout << "Please enter 7 (x, y) points in the format: x y\n";

    // convert into it's own read x values function
    for (int i = 1; i <= 7; ++i) // <= so range is 1 to 7
    {
        Point p;
        std::cout << "Point " << i << ": ";
        std::cin >> p;
        // std::cout << std::endl;
        original_points.push_back(p);
    }

    // exit's program if read error has occurred
    if (std::cin.fail())
    {
        return 1;
    }

    // output previously entered points
    std::cout << "The previously entered points were:\n";
    for (Point p : original_points)
    {
        std::cout << "(" << p.x << "," << p.y << ")" << std::endl;
    }

    return 0;
}
