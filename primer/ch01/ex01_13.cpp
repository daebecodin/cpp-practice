/*
* Created by Durand Dyer-Branch on 2/13/26.
* These programs are for loop rewrites of exercises 9-11 to
* which were written which with while loops
*/

#include <iostream>

void redo9()
{
    int sum = 0;

    for (int val = 50; val <= 100; ++val) {
        sum += val;
    }

    std::cout   << "The sum of all values between 50 and 100: "
                << sum << std::endl;
}

void redo10()
{
    for (int val = 10; val >= 0; --val) {
        std::cout << val << std::endl;
    }
}

void redo11()
{
    int num1 = 0, num2 = 0;
    std::cout << "plz enter 2 numbers. lowest first ;)" << std::endl;
    std::cin >> num1 >> num2;
    std::cout << std::endl;

    for (int i = num1; i <= num2; ++i) {
        std::cout << i << std::endl;
    }

}

int main()
{
    // redo9();
    // redo10();
    redo11();
    return 0;
}
