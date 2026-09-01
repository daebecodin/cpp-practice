#include "pch.h"

int main() 
{

    std::cout << "hello world" << '\x0a';

    std::vector<int> v1; // holds only int
    std::vector<std::string> v2; // holds only string
    std::vector<std::vector<int>> v3; // holds only vectors of int
    return 0;

}

