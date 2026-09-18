#include <iostream>
#include "header.h"

int main()
{
    std::cout<<"Input .obj filename: ";
    std::string filein;
    std::cin>>filein;
    filein = filein + ".obj";
    
    convert(filein);

    return 0;
}