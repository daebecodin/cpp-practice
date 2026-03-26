/*
 * Created by Durand Dyer-Branch on 3/26/26.
*/

#include <iostream>
#include <string>
#include "Sales_data.h"
using namespace std;

int printSum(const Sales_data& b1, const Sales_data& b2){
    if (b1.bookNo == b2.bookNo) {
        unsigned int totalCount = b1.units_sold + b2.units_sold;
        double totalRevenue = b1.revenue + b2.revenue;
        cout << b1.bookNo << " " << totalCount << " " << totalRevenue << " ";

        if (totalCount != 0) {
            cout << totalRevenue/totalCount << '\x0a';
        } else {
            cout << "NO SALES" << '\x0a';
        }
        return  0;
    } else {
        cerr << "data must refer to same ISBN" << '\x0a';
    }
    return  -1;
}

int main() {
    Sales_data data1, data2;

    double price {0.0}; // price per book used to calculate total revenue

    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cout << data1.revenue << '\x0a';

    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;
    cout << data2.revenue << '\x0a';


    printSum(data1, data2);







    return 0;
}