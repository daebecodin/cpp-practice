/*
 * 
 */

#include "pch.h"
using std::cout, std::string;

int main() 
{

    int nums[] = {1, 2, 3, 4, 5};

    int* n = nums; // n = nums[0]
    int n2 = n[2]; // n2 = (nums + 2)
    n2 = *(n + 2); // n2 = nums[2]

    int* two = &nums[1]; // points to the element indexed at 2
    int three = two[2]; // same as writing *(two + 1)
                        // three is the same element as nums[2]

    int one = two[-1]; // same as writing nums[0], *(two - 1)







    return 0;

}
