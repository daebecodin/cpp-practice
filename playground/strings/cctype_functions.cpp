#include <iostream>
#include <string>
#include <cctype>
using std::cin, std::cout, std::endl, std::string, std::boolalpha;

int main()
{
    char a;
    cin >> a;

    cout << boolalpha; 
    cout << !!(isalnum(a)) << endl; // true if letter or digit
    cout << !!(isalpha(a)) << endl; // true if letter
    cout << !!(iscntrl(a)) << endl; // true if a control character; \n, \t, \0, etc
    cout << !!(isdigit(a)) << endl; // true if a digit
    cout << !!(isgraph(a)) << endl; // true if not a space but printable
    cout << !!(islower(a)) << endl; // true is lowercase
    cout << !!(ispunct(a)) << endl; // true if a punctuation character
    cout << !!(isspace(a)) << endl; // true is a space; newline, tab, vertical tab, return, form-feed
    cout << !!(isupper(a)) << endl; // true if uppercase
    cout << !!(isxdigit(a)) << endl; // true if hex digit
    cout << !!tolower(a) << endl; // if uppercase, returns lowercase; otherwise return unchanged
    cout << !!toupper(a) << endl; // if lowercase, returns uppercase; otherwise return unchanged;

    return 0;

}


