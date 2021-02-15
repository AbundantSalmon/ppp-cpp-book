// Class definition drill

#include <string>
#include <iostream>
#include "../std_lib_facilities.h"

Vector<char> not_allow_chars{';', ':', '"', '\'', '[', ']', '*', '&', '^', '%', '$', '#', '@', '!'};

struct Person
{
public:
    Person()
    {
        verify();
    } // default constructor
    Person(std::string iName, int iAge) : m_name{iName}, m_age{iAge}
    {
        verify();
    }

    std::string name() const
    {
        return m_name;
    }

    int age() const
    {
        return m_age;
    }

    void verify() const
    {

        if (m_age < 0 || m_age > 150)
        {
            error("Age incorrect!");
        }
        for (char const &c : m_name)
        {
            for (char const &cc : not_allow_chars)
            {
                if (c == cc)
                {
                    error("Name contains not allowed characters!");
                }
            }
        }
    }

private:
    std::string m_name{}; // default blank
    int m_age{0};         // default 0
};

// << operator for Person
std::ostream &operator<<(std::ostream &os, Person &person)
{
    os << person.name() << " , " << person.age() << "\n";
    return os;
}

// >> operator for Person
std::istream &operator>>(std::istream &is, Person &person)
{
    // Set stream to throw an exception if bad() condition is encountered
    is.exceptions(is.exceptions() | std::ios_base::badbit);

    char comma;
    std::string name;
    int age;
    is >> name >> comma >> age;

    // if failure occurs, return without touching Point pp
    if (!is || comma != ',')
    {
        throw std::runtime_error("User input error");
    }

    person = Person{name, age};

    return is;
}

int main()
{
    Person enteredPerson;

    std::cout << "Enter Person (name , age): ";
    std::cin >> enteredPerson;
    std::cout << "You entered: " << enteredPerson;

    return 0;
}