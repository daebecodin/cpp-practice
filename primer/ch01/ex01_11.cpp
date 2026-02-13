/*
 * This program prompts the user to enter two numbers.
 * It then prints each number in range of the two numbers inclusive
 */

#include <iostream>


void v1()
{
    int num1 = 0, num2 = 0;

    std::cout << "Plz enter 2 numbers" << std::endl; // prompt user
    std::cin >> num1 >> num2; // gather inputs
    std::cout << std::endl;

    while (num1 >= num2) {
        std::cout << num1 << std::endl;
        --num1;
    }
}

void v2()
{
    int num1 = 0, num2 = 0;

    std::cout << "Plz enter 2 numbers" << std::endl; // prompt user
    std::cin >> num1 >> num2; // gather inputs
    std::cout << std::endl;

    while (num1<= num2) {
        std::cout << num1 << std::endl;
        ++num1;
    }
}

int main()
{
    v1();
    // v2();
}