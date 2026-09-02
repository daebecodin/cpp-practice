/*
 *
 */

#include "pch.h"
using std::string;
using std::vector;
using std::cin, std::cout;

int main()
{

    string prompt("Enter a sequence of grades: ");
    cout << prompt;

    vector<int> gradeBucket(11);
    int grades;

    while (cin >> grades && grades != -1)
    {
        auto bucket = gradeBucket.begin();
        bucket += (grades/10);
        if (grades <= 100)
        {
            ++(*bucket);
        }
    }

    string printBuckets("===Grade Buckets===");
    cout << printBuckets << '\n';

    for(auto bucket = gradeBucket.cbegin(); bucket != gradeBucket.cend(); ++bucket)
    {
        if (bucket != gradeBucket.cbegin())
        {
            cout << ", " << *bucket;
        }
        else
        {
            cout << *bucket;
        }
    }
    return 0;

}
