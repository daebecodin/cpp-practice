/*
*  Created by Durand Dyer-Branch on 2/14/26.
*  The following programs will contain common compile time errors
*/

#include <iostream>

void syntaxE()
{
    //colon instead of semicolon
    std::cout << "hello, errors" << std::endl:

    std::cout >> "should be output operator" << std::endl;

    // no quotes around string literal
    std::cout << no quotes around string << std::endl;

    // missing second output operater
    std::cout << "hello, ; " "world" std::endl;

}

void typeE()
{
    // this variable expects to be initialized to an integer but we give it a string literal
    int num = "4"
}

int main()
{

}