#include "pch.h"

using std::string, std::vector, std::cout, std::cin;

int main() 
{
    // 11 buckets, each empty
    vector<int> gradeBuckets(11,0);
    // read the grades
    cout << "enter grades: ";
    int grade;
    while(cin >> grade && grade != -1) {
        if (grade <= 100)// handle only valid grades
            ++gradeBuckets[grade/10];// increment the counter for the current cluster
        else
            cout << "invalid grade";
    }

    std::size_t i{};
    for (i = 0; i < gradeBuckets.size(); ++i) 
    {
        cout << "Bucket " << i << ": " << gradeBuckets[i] << '\n';
    }


    return 0;
}
