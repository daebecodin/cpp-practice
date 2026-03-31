#include <string>
#include <iostream>
using namespace std;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() 
{
    /*
     * String Initialization
     */
    string s1; // empty string
    string s2 = s1; // copy of s1
    string s3 = "copy"; // copy of the string literal
    string s4(6, 's'); // 6 counts of s 
    string s5("copy");
    string s6("copy");
    string s7 = string(6,'d');

    /*
     * 
     */
    string s8, s9;
    cin >> s8 >> s9;
    cout << "your numbers are: " << s8 << " " << s9 << '\x0a';
    return 0;

    
}
