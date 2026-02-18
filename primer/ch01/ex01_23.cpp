/*
 * Created by Durand Dyer-Branch on 2/18/26.
*/

#include <iostream>
#include "Sales_item.h"

void v1()
{
    Sales_item item;
    int cnt = 1;

    if (std::cin >> item) {

        Sales_item currItem;

        while (std::cin >> currItem) {

            if (currItem.isbn() == item.isbn()) {
                cnt++;
            } else {
                std::cout << currItem << " occurs " << cnt << " times" << std::endl; // what if it appears again and its not consecutive
                cnt = 1;
            }
        }
        std::cout << currItem << "occurs " << cnt << " times" << std::endl;
    }
    std::cout << "No data to process" << std::endl;
}


int fixed()
{
    Sales_item initSale; // initial state
    int saleCnt = 1; //count for initialized state

    if (std::cin >> initSale) {
        Sales_item nextSale; // var for following sales groups

        while (std::cin >> nextSale) { // loop for remaining sales
            if (nextSale.isbn() == initSale.isbn()) { // if we find a dupe
                saleCnt++; //increment count
            } else {
                std::cout << initSale.isbn() << " occurs " << saleCnt << " times" << std::endl; // print occurrences
                // manual flush
                initSale = nextSale; // transition state to next sale
                saleCnt = 1; // reset count
            }
        }
        std::cout << initSale.isbn() << " occurs " << saleCnt << " times" << std::endl; // print last group
        return 0;
    } else { // if there is no data to process
        std::cout << "no data to process" << std::endl;
        return -1;
    }
}

int main() {
    fixed();
    return 0;
}