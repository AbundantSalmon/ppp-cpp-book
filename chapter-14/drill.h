#pragma once

#include <string>

class B1
{
public:
    B1() {} //default constructor
    virtual void vf();
    void f();
    virtual void pvf() = 0;

private:
};

class D1 : public B1
{
public:
    D1() {} //default constructor
    void vf() override;
    void f();
    void pvf() override;

private:
};

class D2 : public D1
{
public:
    D2() {} //default constructor
    void vf() override;
    void f();
    void pvf() override;

private:
};

class B2
{
public:
    B2() {} //default constructor
    virtual void pvf() = 0;

private:
};

class D21 : public B2
{
public:
    D21() {} //default constructor
    void pvf();

private:
    std::string values = "D21";
};

class D22 : public B2
{
public:
    D22() {} //default constructor
    void pvf();

private:
    int values = 45;
};