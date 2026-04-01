#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::getline, std::string;

int main() 
{
    string s1 = "hello", s2 = "world";
    string s3 = s1 + ", " + s2 + '\x0a';
    cout << s3;


    /*
     * when mixing character and string literals,
     * there must be a string literal for each +
     * not a character literal or char* arr
     */
    string s4 = s1 + ", "; 
//  string s5 = "hello" + ", "; // no string literal for the +
    string s6 = s1 + ", " + "world"; // here we have a string literal 21 for the + operator
    // string s7 = "hello" + ", " + s2; // cannot add string literals

    return 0;

}
