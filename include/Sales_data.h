/*
 * Created by Durand Dyer-Branch on 3/26/26.
*/

#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

typedef struct Sales_data{
    std::string bookNo;
    unsigned units_sold{0};
    double revenue{0.0};
}Sales_data;
#endif //SALES_DATA_H