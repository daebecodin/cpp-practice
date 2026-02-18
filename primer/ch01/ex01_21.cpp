/*
 * Created by Durand Dyer-Branch on 2/16/26.
 * this program will read 2 identical isbns and sum up their transaction totals
*/

#include <iostream>
#include "Sales_item.h"

void add() {
    Sales_item item1, item2;

    while (std::cin >> item1 >> item2) {
        std::cout << item1 + item2 << std::endl;

    }
}

int add2() {
    Sales_item item1, item2;

    std::cin >> item1 >> item2;

    if (item1.isbn() == item2.isbn()) {
        std::cout << item1 + item2 << std::endl;
    } else {
        std::cerr << "Data must be from identical ISBN" << std::endl;
    }
    return -1;
}
int main()
{
    add2();
    return 0;
}
