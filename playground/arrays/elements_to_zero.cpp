/*
 * Using pointers, write a program to set the elements in an
 array to zero.
 */

#include "pch.h"
using std::cin, std::cout, std::string;
using std::begin, std::end;

int main() 
{
    string prePrompt("Before setting each string to 0: ");
    cout << prePrompt;
    constexpr int sz = 10;

    int nums[sz] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int* b = nums;
    int* e = b + 10;

    int* first = begin(nums);

    while (b < e)
    {
        if (b == first )
        {
            cout << *b;
        }
        else 
        {
            cout << ", " << *b;
        }
        ++b;
    }

    string conversionPrompt("\nAfter setting each element to 0: ");
    cout << conversionPrompt;

    int* last = end(nums);

    for (int* b = begin(nums); b < last; ++b)
    {
        *b = 0;
    }

    bool zero = true;

    for (int i : nums)
    {
        if (zero) 
        {
            cout << i;
        }
        else
        {
            cout << ", " << i;
        }

        zero = false;
    }


    return 0;

}
