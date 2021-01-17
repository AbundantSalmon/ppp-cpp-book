// Exercise from Chapter 3 page 83

#include "../std_lib_facilities.h"

int main()
{
    string first_name{"???"};
    string friend_name{"???"};
    char friend_sex{0};
    int age{0};

    // user prompts
    cout << "Enter the name of the person you want to write to:\n";
    cin >> first_name;
    cout << "Enter the name of a mutual friend:\n";
    cin >> friend_name;
    cout << "Enter 'm' or 'f' depending on the friend's gender:\n";
    cin >> friend_sex;
    cout << "Enter the age of the recipient:\n";
    cin >> age;

    if (age <= 0 || age >= 110)
    {
        simple_error("You're kidding!");
    }

    // formatted letter output
    cout << "Dear " << first_name << ", \n";
    cout << "   How are you? I am fine. I miss you.\n";
    cout << "   Have you seen " << friend_name << " lately?\n";
    if (friend_sex == 'm')
    {
        cout << "   If you see " << friend_name << " please ask him to call me.\n";
    }
    else
    {
        cout << "   If you see " << friend_name << " please ask her to call me.\n";
    }
    if (age < 12)
    {
        cout << "   Next year you will be " << age + 1 << "\n";
    }
    else if (age == 17)
    {
        cout << "   Next year you will be able to vote!\n";
    }
    else if (age > 70)
    {
        cout << "   I hope you're enjoying your retirement.\n";
    }

    cout << "Yours sincerely,\n\n\nDavid\n";
}