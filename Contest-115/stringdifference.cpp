#include <iostream>

#include <string.h>

int main()
{
    const char *str_inp1 = "string match";
    const char *str_inp2 = "string tch";

    std::cout << "String 1: " << str_inp1 << std::endl;
    std::cout << "String 2: " << str_inp2 << std::endl;

    //if (strcmp(str_inp1, str_inp2) == 0)
        std::cout << strcmp(str_inp1, str_inp2) << std::endl;
    //else
        //std::cout << "\nThe input strings are not equal." << std::endl;
}