/*
 * Write a program to define an array of ten ints. Give each
 * element the same value as its position in the array.
 */

#include "pch.h"
using std::string;
using std::cin, std::cout;
using std::size_t;
using std::vector;

int main() 
{

    constexpr int count {10};

    string getCount("Our array count is: ");
    cout << getCount << count << '\n';

    int arr[count];


    string initMsg("Initializing elements from index");
    cout << initMsg << '\n';

    for (size_t i = 0; i < count; ++i)
    {
        arr[i] = i;
    }

    for (int i : arr)
    {
        cout << i << " ";
    }

    string copyMsg("Copy of the previous array");
    cout << '\n' << copyMsg << '\n';

    int arrCopy[count];
    for (size_t i = 0; i < count; ++i)
    {
        arrCopy[i] = arr[i];
    }
    
    for (int i : arrCopy)
    {
        cout << arrCopy[i] << " ";
    }

    return 0;

}
