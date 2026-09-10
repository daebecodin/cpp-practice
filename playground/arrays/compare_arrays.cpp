/*
 * 
 *
 */

#include "pch.h"
using std::cin, std::cout, std::string;
using std::begin, std::end;

int main() 
{
    constexpr int SIZE = 4;

    int arr1[SIZE];
    int arr2[SIZE];

    string arr1Prompt("Enter your 4 arr1 elements: ");
    cout << arr1Prompt;
    for (int i = 0; i < SIZE; ++i)
    {
        cin >> arr1[i];
    }

    string arr2Prompt("Enter your 4 arr2 elements: ");
    cout << arr2Prompt;
    for (int i = 0; i < SIZE; ++i)
    {
        cin >> arr2[i];
    }
    cout << '\n';

    string printPrompt("==Your arrays==\n");
    cout << printPrompt;

    int* e1 = end(arr1);
    cout << "arr 1: ";
    for (int* b1 = begin(arr1); b1 < e1; ++b1)
    {
        cout << *b1 << " ";
    }
    cout << '\n';

    int* e2 = end(arr2);
    cout << "arr 2: ";
    for (int* b2 = begin(arr2); b2 < e2; ++b2)
    {
        cout << *b2 << " ";
    }
    cout << '\n' << '\n';

    string comparePrompt("Are the arrays equal?: ");
    cout << comparePrompt;

    bool areEqual = true;
    for (int i = 0; i < SIZE; ++i)
    {
        if (arr1[i] != arr2[i])
        {
            areEqual = false;
            break;
        }
    }

    if (areEqual)
    {
        cout << "Yes!\n";
    }
    else 
    {
        cout << "No :(\n";
    }
    return 0;

}
