/*
 *  This program utilizes a while loop and the decrement
 *  operator to write a program that prints numbers form
 *  10 down to 0
 */

#include <iostream>

/*
 * Initial version
 */
void v1()
{
    int val = 11;

    while(val <= 11) {
        val--;
        std::cout << val << std::endl;
        if (val <= 0) {
            break;
        }
    }
}

/*
 * Cleaner version
 */
void v2()
{
    int val = 10; // we start our countdown at 10

    while (val >= 0) { // loop continues while non-negative
        std::cout << val << std::endl; // print current value
        --val; // subtract val by 1 then update and check
    }
}

int main()
{
    // v1();
    v2();
}