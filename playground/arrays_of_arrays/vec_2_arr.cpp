/*
 * 
 */

#include "pch.h"
using std::vector;
using std::begin, std::end;
using std::cout;
using std::size_t;

int main() 
{
    vector<int> vi(5, 6);

    int ai[6] = {};

    for(size_t i = 0; i < vi.size(); ++i)
    {
        ai[i] = vi[i];
    }

    for (int* n = begin(ai); n < end(ai); ++n)
    {
        if ( n != ai) 
        {
            cout << ", " << *n;
        }
        else 
        {
            cout << *n;
        }
    }



    return 0;

}
