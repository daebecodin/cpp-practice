/*
 * This program uses a while loop to sum numbers 50 to 100
 *
 */

#include <iostream>

int main()
{
    int sum = 0, val = 50; // def/init variables

    while (val <= 100) { //while val is less than or equal to 100
        sum += val; // add the current iteration to sum
        ++val; // increment then update
    }

    std::cout   << "The sum of all value between 50 and 100: "
                << sum << std::endl;
    return 0;
}
