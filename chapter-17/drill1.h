#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

namespace drill1
{
    // 4
    void print_array10(std::ostream &os, int *a)
    {
        for (int i = 0; i < 10; ++i) // don't for get int i = 0, not just int i, got caught out by that
        {
            os << a[i] << "\n";
        }
    }

    // 7
    void print_array(std::ostream &os, int *a, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            os << a[i] << "\n";
        }
    }

    // 10
    void print_vector(std::ostream &os, const std::vector<int> &a)
    {
        for (int value : a)
        {
            os << value << "\n";
        }
    }

    void first_part()
    {
        std::cout << "first_part():\n";
        // 1
        int *array_of_ints = new int[10];

        // 2
        for (int i = 0; i < 10; ++i)
        {
            std::cout << array_of_ints[i] << "\n";
        }

        // 3
        delete[] array_of_ints;

        //5
        int *array_of_10_ints = new int[10]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
        print_array10(std::cout, array_of_10_ints);
        delete[] array_of_10_ints;

        //6
        int *array_of_11_ints = new int[11]{100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
        print_array(std::cout, array_of_11_ints, 11);
        delete[] array_of_11_ints;

        // 8
        int *array_of_20_ints = new int[20];
        for (int i = 0; i < 20; ++i)
        {
            array_of_20_ints[i] = 100 + i;
        }
        print_array(std::cout, array_of_20_ints, 20);
        delete[] array_of_20_ints;

        // 10
        std::cout << "Vectors\n";
        std::vector<int> vector_of_10_ints = {100, 101, 102, 103, 104, 105, 106, 107, 108, 109};
        print_vector(std::cout, vector_of_10_ints);
    }

    void second_part()
    {
        std::cout << "second_part():\n";
        // 1
        int i{7};
        int *p1 = &i;
        // 2
        std::cout << p1 << ":"
                  << "\n";
        print_array(std::cout, p1, 1);

        // 3
        int *p2 = new int[7]{1, 2, 4, 8, 16, 32, 64};
        // 4
        std::cout << p2 << ":"
                  << "\n";
        print_array(std::cout, p2, 7);

        // 5
        int *p3 = p2;
        // 6
        p2 = p1;
        // 7
        p2 = p3;
        // 8
        std::cout << p1 << ":"
                  << "\n";
        print_array(std::cout, p1, 1);
        std::cout << p2 << ":"
                  << "\n";
        print_array(std::cout, p2, 7);

        // 9
        delete[] p2; // only when a call of new is use allocates memory from the heap, p1 and p2 don't need to be deleted

        // 10
        p1 = new int[10]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
        // 11
        p2 = new int[10];

        // 12
        for (int i = 0; i < 10; ++i)
        {
            p2[i] = p1[i];
        }

        std::cout << p1 << ":"
                  << "\n";
        print_array(std::cout, p1, 10);
        std::cout << p2 << ":"
                  << "\n";
        print_array(std::cout, p2, 10);

        // 13
        std::vector<int> v1{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
        std::vector<int> v2(10);

        for (int i = 0; i < v2.size(); ++i)
        {
            v2.at(i) = v1.at(i);
        }
        print_vector(std::cout, v1);
        print_vector(std::cout, v2);
    }
}
