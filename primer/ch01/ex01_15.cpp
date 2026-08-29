/*
*  Created by Durand Dyer-Branch on 2/14/26.
*  The following programs will contain common compile time errors
*/

#include <iostream>

void syntaxE()
{
    // Fixed: colon instead of semicolon
    std::cout << "hello, errors" << std::endl;

    // Fixed: should be output operator
    std::cout << "should be output operator" << std::endl;

    // Fixed: no quotes around string literal
    std::cout << "quotes around string" << std::endl;

    // Fixed: missing second output operator
    std::cout << "hello, ; " << "world" << std::endl;

}

void typeE()
{
    // Fixed: this variable expects to be initialized to an integer but we give it a string literal
    int num = 4;
}

int main()
{

}