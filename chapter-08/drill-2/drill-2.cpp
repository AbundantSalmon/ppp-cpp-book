#include <iostream>

void swap_v(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_r(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// can't run can't modify const values
// void swap_cr(const int &a, const int &b)
// {
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

void print_values(int i, int j)
{
    std::cout << i << std::endl;
    std::cout << j << std::endl;
}

int main()
{
    int x = 7;
    int y = 9;

    //swap_v(x, y); // print_value -> x=7 and y=9
    swap_r(x, y); // print_value -> x=9 and y=7

    print_values(x, y);

    return 0;
}