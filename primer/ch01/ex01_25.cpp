/*
 * Created by Durand Dyer-Branch on 2/18/26.
*/

#include <iostream>
#include "Sales_item.h"

int main() {

    Sales_item total;

    if (std::cin >> total) {

        Sales_item trans;

        while (std::cin >> trans) {
            if (trans.isbn() == total.isbn()) {
                total += trans;
            } else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cerr << "no data" << std::endl;
        return -1;
    }
    //initial state

    //read first input
    //next state var

    //while more
        //if same
        //accumulate
        //else; print/move on

    //print last group

    //if no data



    return 0;
}
