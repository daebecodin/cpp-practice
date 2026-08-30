#include "pch.h"
using std::vector;
using std::string;

/*
 * We don't always know the size, elements/value for our vectors at creation
 * 
 * push_back();
 *  - adds an element to the final index of a vector at run-time
 */

vector<int> addInt() 
{
    int n;
    vector<int> numbers;
    while (std::cin >> n) {
        for (int i = 0; i <= n; ++n){
            numbers.push_back(n);
            std::cout << n << " added to vector." << '\x0a';
        }
    }

    return numbers;
}

int main() 
{
    vector<int> v1 = addInt();
    std::cout << "in main" << '\x0a';

    int i{};

    for (int &n : v1)
    {
        std::cout << i << ": " << n << '\x0a';
        ++i;
    }
    return 0;

} 
