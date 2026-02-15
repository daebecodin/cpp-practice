/*
* Created by Durand Dyer-Branch on 2/13/26.
* What does this for loop do and what is the final value of sum?
*/

#include <iostream>

int main()
{
    int sum = 0; // define and init sum to 0
    /*
     * loops init variable is -100
     * its checks if the init variable is <= 100
     * then it increments and updates the init variables
     * total of 202 check
     *  -100 to 100 inclusive is 201
     *  final false check at 100 <= 100 is false is 1 last check
     *
     */
    for (int i = -100; i <= 100; ++i) {
        sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}