/*
 * Created by Durand Dyer-Branch on 2/16/26.
 * This program will read several transactions with the same ISBN then write the sum of all transactions read
 *
 *
*/

#include <iostream>
#include "Sales_item.h"

int main() {
    // variable to hold data for all transactions
    Sales_item avg;

    //read the first transaction and check if the list continues
    if (std::cin >> avg) {
        // variable to hold the represent the next transaction
        Sales_item currTrans;

        // read and process the rest of the book transactions
        while (std::cin >> currTrans) {
                // add it to the total
                avg += currTrans;
        }
        // print the last transaction(eof)
        std::cout << avg << std::endl;
    } else {
    // print error if no input
        std::cerr << "no data to process" << std:: endl;

        return -1;
    }
    return 0;
}