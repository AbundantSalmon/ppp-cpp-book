#include "drill1.h"

int main()
{
    try
    {
        drill1::first_part();
        drill1::second_part();
        return 0; // program exited successfully
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return 1; // program exited unsuccessfully
    }
    catch (...)
    {
        return 2; // program exited unsuccessfully
    }
}