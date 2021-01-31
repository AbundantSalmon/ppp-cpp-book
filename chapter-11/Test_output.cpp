/**
 * @file Test_output.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-01-31
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

int main()
{
    int birth_year{2000};
    int current_year{2021};
    std::cout << std::showbase;
    std::cout << "decimal:\t" << birth_year << std::endl;
    std::cout << "hexadecimal:\t" << std::hex << birth_year << std::endl;
    std::cout << "octal:\t\t" << std::oct << birth_year << std::endl;

    std::cout << "Age: " << std::dec << current_year - birth_year << std::endl;

    return 0;
}