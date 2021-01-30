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
 * @brief extraction operator for "x y" input values for Point
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

    // if failure occurs, return without touching Point pp
    if (!std::cin)
    {
        throw std::runtime_error("User input error");
    }

    //if successful then set Point to entered values.
    pp = Point{x, y};

    return is;
}

/**
 * @brief function to prompt user to enter points to be stored in list of points
 * 
 * @param number_of_points must be must be at least 1
 * @param list_of_points std::vector<Point>
 */
void prompt_user_for_points(int number_of_points, std::vector<Point> &list_of_points)
{
    // number of requested points must be at least 1
    assert(number_of_points >= 1);

    for (int i = 1; i <= number_of_points; ++i) // <= so range is 1 to 7
    {
        Point p;
        std::cout << "Point " << i << ": ";
        std::cin >> p;
        // std::cout << std::endl;
        list_of_points.push_back(p);
    }
}

int main()
{
    std::vector<Point> original_points;

    // prompt user to enter points
    try
    {
        std::cout << "Please enter 7 (x, y) points in the format: x y\n";
        prompt_user_for_points(7, original_points);
    }
    catch (std::exception &exception)
    {
        // gracefully exit program if input error has occurred
        std::cerr << exception.what() << std::endl;
        return 1;
    }

    // output previously entered points
    std::cout << "The previously entered points were:\n";
    for (Point p : original_points)
    {
        std::cout << "(" << p.x << "," << p.y << ")" << std::endl;
    }

    //program has successfully run
    return 0;
}
