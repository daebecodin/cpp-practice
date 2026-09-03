/*
 * Demonstrating iterator arithmetic with a binary search.
 */

#include "pch.h"

using std::cin, std::cout;
using std::vector;

void ignoreLine()
{
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

vector<int> getSequence()
{
    vector<int> values;
    int value{};

    cout << "Enter integers from 0 to 100 (-1 to finish): ";

    while (true)
    {
        if (!(cin >> value))
        {
            cout << "Invalid input. Enter an integer: ";
            cin.clear();
            ignoreLine();
            continue;
        }

        if (value == -1)
        {
            break;
        }

        if (value < 0 || value > 100)
        {
            cout << "The number must be between 0 and 100: ";
            continue;
        }

        values.push_back(value);
    }

    return values;
}

int getSoughtValue()
{
    int sought{};
    cout << "What number are you looking for? ";

    while (!(cin >> sought))
    {
        cout << "Invalid input. Enter an integer: ";
        cin.clear();
        ignoreLine();
    }

    return sought;
}

int main()
{
    vector<int> values = getSequence();

    if (values.empty())
    {
        cout << "No numbers were entered.\n";
        return 0;
    }

    // Binary search only works when the sequence is sorted.
    std::sort(values.begin(), values.end());

    cout << "\nSorted sequence: ";
    for (auto iter = values.cbegin(); iter != values.cend(); ++iter)
    {
        if (iter != values.cbegin())
        {
            cout << ", ";
        }
        cout << *iter;
    }
    cout << '\n';

    const int sought = getSoughtValue();

    auto begin = values.cbegin();
    auto end = values.cend();
    auto middle = begin + (end - begin) / 2;

    while (middle != end && *middle != sought)
    {
        if (sought < *middle)
        {
            end = middle;
        }
        else
    {
            begin = middle + 1;
        }

        middle = begin + (end - begin) / 2;
    }

    if (middle != values.cend() && *middle == sought)
    {
        cout << sought << " was found at index "
            << middle - values.cbegin() << ".\n";
    }
    else
{
        cout << sought << " was not found.\n";
    }

    return 0;
}
