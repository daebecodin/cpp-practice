/*
 * Created by imdem on 3/4/2026.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    header(
        "Pointer, Object, Address Relationships",
        "Reveal the relationship between an object, a pointer storing its address, dereferencing, and "
            "the address of the pointer itself"
    );

    inputs({
        "No user defined inputs",
        "Objects involved: {int x, int* p}"
    });

    int x = 44;
    int* p = &x;

    pipeline_begin();
    cout << "Addresses and Values" << '\x0a';
    kv("x -> ", x); // value stored in x
    kv("&x -> ", &x); // address of x
    kv("p -> ", p); // address of x, inside p
    kv("*p -> ", *p); // value at address of x, stored in p
    kv("&p -> ",&p); // address of p
    cout << '\x0a';

    cout << boolalpha<< "Comparisons" << '\x0a';
    kv("x vs *p -> ", x == *p);
    kv("&x vs p -> ", &x == p);
    kv("&p vs p -> ", static_cast<const void*>(&p) == static_cast<const void*>(p));

    classify({
        "Well-defined, if the pointer is initialized to a live object or nullptr",
        "Undefined, if p is uninitialized and you attempt to read its value.",
        "x, &x, &p, p are well-defined here because everything is initialized and alive.",
        "Reading p when it's uninitialized (automatic storage) is undefined behavior.",
        "Dereferencing *p is undefined behavior unless p points to a live object."
    });

    rule({
        "An object and a pointer to that object store the same address.",
        "An object value and a dereferenced pointer to that object store the same value.",
        "The address stored in the pointer != the address of the pointer; pointers are their own objects.",
        "To compare the address stored in a pointer and the address of the pointer, static cast both to const void*"
    });

    return 0;
}