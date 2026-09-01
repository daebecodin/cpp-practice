/*
 * Write a program to print the size and contents if the vectors
 * 
 */

#include "pch.h"
using std::string, std::vector, std::cin, std::cout;
using std::distance; // returns steps between two iterators; use to calculate index

int main() 
{

    vector<int> v1; // empty vector
    vector<int> v2(10); // 10 0-initialized elements
    vector<int> v3(10,42); // 10 items initialized to 42
    vector<int> v4{10}; // one item initialized to 10
    vector<int> v5{10,42}; // 2 initialized items
    vector<string> v6{10}; // 10 empty strings
    vector<string> v7{10, "hi"}; // 10 string initialized to hi

    vector<vector<int>> vi {v1 , v2, v3, v4, v5};
    vector<vector<string>> vs {v6, v7};


    
    for (auto it = vi.cbegin(); it != vi.cend(); ++it)
    {
        auto index = distance(vi.cbegin(), it); // both return same iterator -> distance == 0
        cout << "vector " << index + 1 << '\n';
        cout << "size: "<< it->size() << '\n';
        cout << "elements: ";

        if (it->empty())
        {
            cout << "empty" << '\n' << '\n';
        }
        else 
        {
            for (auto iit = it->cbegin(); iit != it->cend(); ++iit)
            {
                if (iit != it->cbegin())
                {
                    cout << ", "; 
                }  

                cout << *iit;  
            }
        }
        cout << '\n' << '\n';
    }
    return 0;
}
