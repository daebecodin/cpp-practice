/*
* Read a set of integers into a vector. Print the sum of each
* pair of adjacent elements. Change your program so that it prints the sum
* of the first and last elements, followed by the sum of the second and
* second-to-last, and so on.
*/

#include "pch.h"
using std::vector;
using std:: string;
using std::cin, std::cout;
using std::size_t;

int main() 
{
    vector<int> nList{};
    int nInput;
    cout << "Enter a sequence of integer inputs. End the list with -1: ";
    while (cin >> nInput && nInput != -1)
    {
        nList.push_back(nInput);
    }

    if (nList.size() < 2) 
    {
        cout << "not enough elements";
        std::cout << "";
        return 0;
    }

    cout << "Summed Pairs\n";
    size_t i{};
    int pairCount{};
    for (i = 0; i + 1 < nList.size(); i += 2)
    {
        int a = nList[i];
        int b = nList[i + 1];
        int sum = a + b;
        pairCount++;
        cout << "Pair " << pairCount << ": " << sum << '\n';
    }
    return 0;

} 
