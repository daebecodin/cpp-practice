/*
* Created by Durand Dyer-Branch on 2/16/26.
* This program will read a set of book sales transactions,
* writing each traction to the standard output
*/

#include <iostream>
#include "Sales_item.h"

int main()
{

    Sales_item item;

    while (std::cin >> item) {
        std::cout << item << std::endl;
    }

    return 0;
}