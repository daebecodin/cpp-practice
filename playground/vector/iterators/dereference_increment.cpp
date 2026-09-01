/*
 * Similar to integers, 
 * Iterators use the increment (++) operator to move over to the next element
 * 
 * NOTE
 * Because.end() returns am empty iterator, it may not be incremented or de-referenced
 * 
 * PROGRAM
 * In this program we read a string including white space.
 * We define it to denote the first char in the string.
 * The loop de-references it, passes the current char to 'toupper()', 
 * and assign the resulting  uppercase letter back to it
 * 
 */

#include "pch.h"
#include <cctype>
using std::string;
using std::cin, std::cout;


int main() 
{
    cout << "Enter a string or a sentence -> ";
    string s{};
    cin >> s;
    cout << '\n';
            
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) 
    {
        *it = toupper(*it);
    }

    cout << s;


    return 0;

}
