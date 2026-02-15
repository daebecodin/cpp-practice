/*
* Created by Durand Dyer-Branch on 2/14/26.
* This program reads an unknown set of integers from cin and sums them all
* until we reach end of the file or an invalid argument is entered
*/

#include <iostream>

int main() {
    int val = 0;
    int sum = 0;

    std::cout << "plz enter how ever many numbers you like" << std::endl;

    while (std::cin >> val) {
        sum += val;
    }
    std::cout   << "the sum of all numbers entered: "
                << sum << std::endl;
    return 0;
}