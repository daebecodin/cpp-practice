/*
 * begin() represents the first element in the container/string 
 * end() represents one spot over the last element, marking a processed container/string
 * 
 * if the container is empty, both begin and end return the same iterator
 * 
 * we do not care for the return type, so us `auto`
 * they will have whatever type is returned by the iterator
 * 
 * OPERATIONS
 * *iter : returns a reference to the element denoted by the iterator iter
 * iter->mem : this is like calling using `.` notation to call a member function
 * 
 * ++iter : incerement iter to refer to next object in the container
 * --iter : decrement iter to to the previous element
 * 
 * iter1 == iter2 ; comparison check
 * iter1 != iter2 ; if they denote the same element or are off-the-end iterator for the same container
 * 
 * 
 */

#include "pch.h"
using std::cin, std::cout;
using std::vector;
using std::string;
using std::size_t;

int main() 
{
    string s("daebecodin");
    // check if our string is empty
    if (s.begin() != s.end()) 
    {
        auto it = s.begin(); // marker for first element
        auto it2 = --s.end();
        *it = toupper(*it);
        *it2 = toupper(*it2);
    }

    cout << s;
    return 0;

}
