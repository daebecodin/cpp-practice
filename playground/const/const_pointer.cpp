/*
 * Created by imdem on 3/9/2026.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    cout << boolalpha;
    header(
      "Const Pointer",
      "Show that a const pointer itself cannot be reseated after initialization, but if it points to a non-const object,"
            "the pointee may still be modified through the pointer"
    );

    inputs({
        "No Inputs",
        "Objects Involved { int i, int y, int *const p }"
    });

    pipeline_begin();
    int i = 420;
    int y = 67;
    int *const p = &i; // const pointer storing i

    stage("Pre-State");
    kv("i -> ", i); // 420
    kv("y -> ", y); // 67
    kv("p -> ", p); // address of i; can only point here
    kv("*p -> ", *p); // 420; can be modified through pointer
    kv("&i -> ", &i); // address of i
    kv("&y -> ", &y); // address of y
    kv("&p -> ", &p); // address of p
    blank();

    stage("Comparisons");
    kv("p == &i -> ", p == &i); // true
    kv("*p == i -> ", *p == i); // true
    blank();

    stage("Runtime Operation");
    *p = 69; // we can write through the pointer
    kv("write through pointer -> ", "*p = 69");
    kv("i -> ", i); // 69 after pointer write-through
    kv("p -> ", p); // still address of i
    kv("*p -> ", *p); // 69
    blank();

    stage("Compile-Time Checks");
#if 0
    p = &y; // cannot reseat a const pointer
#endif
#if 0
    int *const bad; // must initialize const pointers;
#endif

    classify({
        "Well-Defined: initializing a const pointer.",
        "Well-Defined: reading through a const pointer.",
        "Well-Defined: writing through a const pointer when it points to a non-const object",
        "Ill-Formed: reseating a const pointer.",
        "Ill-Formed: uninitializing a const pointer"
    });

    rule({
        "Const on the pointer restrict reseating and must be initialized.",
        "Const pointers are allowed to modify their pointee if the pointee type is defined non-const.",
        "\'*\' to the right of the const keyword applies to const behavior to the pointer, not pointee"
    });
    return 0;
}
