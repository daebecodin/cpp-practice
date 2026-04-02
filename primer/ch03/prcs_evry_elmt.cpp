#include <iostream>
#include <string>
#include <cctype>
using std::endl, std::cout, std::cin, std::string, std::getline;

int main() 
{
    /*
     * to process every element is an char* arr or arr
     * we can use a range-based loop a.k.a for each loop
     * an operation is performed on each iteration
     */
    string str;

    decltype(str.size()) punct_count = 0; // variable of type string::size_type

    while (getline(cin, str)) {

    for (auto c : str) {
        if (ispunct(c)) { // if the current char is a punctuation char
            ++punct_count;
        }
    }
    cout << punct_count << " puncuations show up in " << str;
    return 0;
    }
   
}
