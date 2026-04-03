#include <iostream>
#include <vector>
#include <string>
using std::vector, std::cout, std::cin, std::endl, std::string;



/*
 * Vector 
 * A collection of objects if like type, each accessible though their associated index
 * 
 * A vector  is a class template, not a type; meaning is provides instructions to the compiler on how to 
 * instantiate its contents
 * 
 * Since reference are not objects, we cannot have a vector<&>; Vector will store almost any object though
 */
int main() 
{
    /*
     * Defining and Initializing 
     * 
     */
    vector<int> v1; // vector that holds objects of type int; default initialized; v1 is empty
    vector<int> v2(v1); // v2 has a copy of each element inside v2
    vector<int> v3 = v1; // v3 has a copy of each element in v1
    vector<int> v4(4, 67); // v4 // v4 initialized with 4 items each initialized to 67 
    vector<int> v5(4); // v5 has 4 4 copies
    vector<int> v6 = {67, 420, 69}; // v6 has 3 elements from 3 initializers
    vector<int> v7{67, 420, 69}; // identical to v6 

    for(int i: v1) {
        i = {420};
    }
    //
    // for(int i = 0; i < 100; ++i) {
    //     v1.push_back(i);
    //     cout << i << endl;
    // }
    vector<string> v8;
    string str;
    while (cin >> str) {
        v8.push_back(str);
    }

    for(auto letter : v8) {
        cout << letter << " ";
        if (letter == v8[-1]) {
            cout << ".";
        }
    }

    
    

}
