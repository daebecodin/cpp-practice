#include "pch.h"
using std::vector, std::string;

int main() 
{
    vector<int> v1; // empty vector
    vector<int> v2(10); // 10 0-initialized elements
    vector<int> v3(10,42); // 10 items initialized to 42
    vector<int> v4{10}; // one item initialized to 10
    vector<int> v5{10,42}; // 2 initialized items
    vector<string> v6{10}; // one element converted to string
    vector<string> v7{10, "hi"}; // 2 initialized string elements

    return 0;

}
