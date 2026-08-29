//
// Created by Durand Dyer-Branch on 2/11/26.
//

#include <iostream>

/*
 * example program showing incorrectly(nested) used comments
 * This demonstrates that nested block comments don't work in C++
 */
int main()
{

    int v1 = 3, v2 = 6;
    int sum = v1 + v2; // sum holds the sum of the 2 variables
     std::cout << sum << std::endl;


    return 0;
}