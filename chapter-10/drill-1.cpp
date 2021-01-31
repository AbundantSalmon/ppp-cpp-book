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
#include <fstream>

/**
 * @brief Datatype to hold (x,y) coordinate points
 * 
 */
struct Point
{
public:
    int x; // coordinate x
    int y; // coordinate y
};

/**
 * @brief Comparison operator for Point struct
 * 
 * @param lhs 
 * @param rhs 
 * @return true 
 * @return false 
 */
bool operator==(const Point &lhs, const Point &rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}

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
    is >> x >> y;

    // if failure occurs, return without touching Point pp
    if (!is)
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

    // TODO: convert to reprompt user for input if user input error has occurred
    for (int i = 1; i <= number_of_points; ++i) // <= so range is 1 to 7
    {
        Point p;
        std::cout << "Point " << i << ": ";
        std::cin >> p;
        // std::cout << std::endl;
        list_of_points.push_back(p);
    }
}

/**
 * @brief extraction operator for "(x,y)" input values for Point
 * 
 * @param is input stream
 * @param pp point to extract to
 * @return std::ifstream& 
 */
std::ifstream &operator>>(std::ifstream &is, Point &pp)
{
    // Set stream to throw an exception if bad() condition is encountered
    is.exceptions(is.exceptions() | std::ios_base::badbit);

    // Check for a start of formatting of (x,y)
    char ch;
    is >> ch;
    if (ch != '(')
    {
        is.unget();
        is.clear(std::ios::failbit); // set stream to fail if unexpected format
        return is;
    }

    int x;
    char ch1;
    int y;
    char ch2;
    is >> x >> ch1 >> y >> ch2;
    if (!is || ch1 != ',' || ch2 != ')')
    {
        // unexpected format handling
        is.clear(std::ios::failbit); // set stream to fail if unexpected format
        return is;
    }

    //if successful then set Point to entered values.
    pp = Point{x, y};
    std::cout << "Successful point read\n";

    return is;
}

/**
 * @brief Prints out a formated list of the (x,y) coordinates to a stream
 * 
 * @param stream a std::ostream
 * @param list_of_points std::vector<Point>
 */
void output_point_vector_to_stream(std::ostream &stream, std::vector<Point> &list_of_points)
{
    for (Point p : list_of_points)
    {
        stream << "(" << p.x << "," << p.y << ")" << std::endl;
    }
}

/**
 * @brief Read in values from a file stream to a vector of Points
 * 
 * @param stream a std::ifstream for a file
 * @param list_of_points std::vector<Point>
 */
void read_stream_to_point_vector(std::ifstream &stream, std::vector<Point> &list_of_points)
{
    Point read_point;
    std::cout << "Begin file read\n";
    while (stream >> read_point)
    {
        list_of_points.push_back(read_point);
    }
    std::cout << "End of file read\n";
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
    output_point_vector_to_stream(std::cout, original_points);

    // output each point to a file named mydata.txt
    std::ofstream write_file{"mydata.txt"};
    if (!write_file)
    {
        throw std::runtime_error("Can't open output file: mydata.txt");
    }
    output_point_vector_to_stream(write_file, original_points);

    write_file.close();

    // read the mydata.txt file
    std::cout << "Read the mydata.txt file\n";
    std::ifstream read_file{"mydata.txt"};
    if (!read_file)
    {
        throw std::runtime_error("Can't open input file: mydata.txt");
    }

    // output previously entered points
    std::vector<Point> processed_points;
    read_stream_to_point_vector(read_file, processed_points);

    read_file.close();

    std::cout << "The read points from mydata.txt were:\n";
    output_point_vector_to_stream(std::cout, processed_points);

    // check to make sure the original_points and processed_points are the same.
    if (original_points == processed_points)
    {
        std::cout << "Read values were good!\n";
    }
    else
    {
        std::cout << "Something's wrong!\n";
    }

    //program has successfully run
    return 0;
}
