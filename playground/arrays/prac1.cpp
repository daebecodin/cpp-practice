
/*
 * ignore line
 * std clear
 * 
 */

#include "pch.h"
using std::cin, std::cout;
using std::string;
using std::size_t;

int main() 
{
    unsigned gradeBuckets[11] = {}; // buckets all initialized to 0;

    string prompt("enter some grades: ");
    cout << prompt;

    int grade;

    while (cin >> grade && grade != -1)
    {
        if (grade < 0 || grade > 100)
        {
            cout << "invaid input. try again\n";
            continue;
        }
        ++gradeBuckets[grade/10];

    }

    string buckets("Grade Buckets");
    cout << buckets << '\n';

    for (unsigned bucket : gradeBuckets) 
    {
        cout << ", " << bucket;

    }



    return 0;

}
