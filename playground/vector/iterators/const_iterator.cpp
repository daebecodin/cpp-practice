/*
 * Since the type of the object determines the type of the iterator,
 * we may encounter the const_iterator
 * 
 * The begin() and end() functions called from const objects return const_iterators
 * 
 * To manually call const_iterator
 *  - cbegin()
 *  - cend()
 * 
 * 
 * 
 */

#include "pch.h"
using std::cout, std::cin;
using std::vector;
using std::string;
int main() 
{
    vector<int> v;
    const vector<int> cv;
    auto i1 = v.begin(); // vector<int>::iterator
    auto i2 = cv.begin(); // vector<int>::const_iterator

    auto i3 = v.cbegin(); // vector<int>::const_iterator

    return 0;

}
