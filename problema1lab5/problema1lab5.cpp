#include"Number.h"
#include <iostream>

int main()
{
    Number n1("10110010", 2);//178
    Number n2("734", 8);
    Number n3("FF", 16);//255
    Number n4("1", 16);
    //n1.Print();
    //n1.SwitchBase(16);
    //n1.Print();
    //printf("%d\n", n1.GetBase());
    //n1.SwitchBase(10);
    //n1.Print();
    //std::cout << "Hello World!\n";
    std::cout << "reprezentarea adunarii in baza maxima: " << n1 + n3 << "\n";
    std::cout << "reprezentarea adunarii in baza maxima: " << n3 - n1 << "\n";

    std::cout << "\n";
    
    if (n1 > n2)std::cout << "da sefu" << "\n";
    else std::cout << "nu sefu" << "\n";

    std::cout << "\n";
    
    if (n1 == n2)std::cout << "egale sefu" << "\n";
    else std::cout << "nu egale sefu" << "\n";

    n1 = 10;
    //de ce nu pot face Number n1 = 10?
    n1.Print();
}
