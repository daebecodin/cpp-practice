#include "pch.h"
using std::vector;
using std::string;
using std::cout, std::cin;

int main() 
{
    vector<int> v1; // empty vector
    vector<int> v2(10); // 10 0-initialized elements
    vector<int> v3(10,42); // 10 items initialized to 42
    vector<int> v4{10}; // one item initialized to 10
    vector<int> v5{10,42}; // 2 initialized items
    vector<string> v6{10}; // 10 empty strings
    vector<string> v7{10, "hi"}; // 10 string initialized to hi
    
    vector<vector<int>> vi {v1, v2, v3, v4, v5};
    vector<vector<string>> vs {v6, v7};

    std::size_t i{};
    std::size_t j{};
    for (i = 0; i < vi.size(); ++i) 
    { 
        cout << "Vector " << i + 1 << "\n";
        cout << "size -> " << vi[i].size() << '\n';
        cout << "elements -> " ;

        if (vi[i].size() == 0) 
        {
            cout << "empty" << '\n' << '\n';
        }
        else 
        {
            for (j = 0; j < vi[i].size(); ++j) 
            {
                if (j == vi[i].size() - 1) 
                {
                cout << vi[i][j];
                }  else {
                    cout << vi[i][j] << ", ";
                }
            }
            cout << '\n' << '\n';
        }
    }

    for (i = 0; i < vs.size(); ++i) {
        cout << "Vector " << i + 1 << "\n";
        cout << "size -> " << vs[i].size() << '\n';
        cout << "elements -> " ;

        if (vs[i].size() == 0) 
        {
            cout << "empty" << '\n' << '\n';
        }
        else 
        {
            for (j = 0; j < vs[i].size(); ++j) 
            {
                if (j == vs[i].size() - 1) 
                {
                cout << vs[i][j];
                }  else {
                    cout << vs[i][j] << ", ";
                }
            }
            cout << '\n' << '\n';
        }

    }
    return 0;

}
