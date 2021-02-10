#include "drill.h"
#include <iostream>

void B1::f()
{
    std::cout << "B1::f()" << std::endl;
}

void B1::vf()
{
    std::cout << "B1::vf()" << std::endl;
}

void B1::pvf()
{
    std::cout << "B1::pvf()" << std::endl;
}

void D1::vf()
{
    std::cout << "D1::vf()" << std::endl;
}

void D1::f()
{
    std::cout << "D1::vf()" << std::endl;
}

void D1::pvf()
{
    std::cout << "D1::pvf()" << std::endl;
}

void D2::vf()
{
    std::cout << "D2::vf()" << std::endl;
}

void D2::f()
{
    std::cout << "D2::vf()" << std::endl;
}

void D2::pvf()
{
    std::cout << "D2::pvf()" << std::endl;
}

void D21::pvf()
{
    std::cout << values << std::endl;
}

void D22::pvf()
{
    std::cout << values << std::endl;
}

void f(B2 &arg)
{
    arg.pvf();
}

int main()
{
    //1
    // B1 objectB1;
    // objectB1.vf();
    // objectB1.f();

    //2
    D1 objectD1;
    objectD1.vf();
    objectD1.f();
    objectD1.pvf();

    //3
    B1 &refObjectB1 = objectD1;
    refObjectB1.vf();
    refObjectB1.f(); //4 B1::f() will be called due to the type of B1, parent class despite D1 object assigned
    refObjectB1.pvf();

    //5 B1 class object cannot be created because B1 would be an abstract class

    D2 objectD2;

    objectD2.f();
    objectD2.vf();
    objectD2.pvf();

    //7
    D21 objectD21;
    D22 objectD22;
    f(objectD21);
    f(objectD22);

    return 0; // progran successfully exited
}