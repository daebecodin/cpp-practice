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
      "Pointer to Const",
      "Show that a pointer-to-const cannot modify the object it points to through that pointer,"
      " but the pointer itself can be reseated and the underlying object may still change thorugh another access path."
    );

    inputs({
        "No Inputs",
        "Objects Involved: { int i, const int ci, const int *p }"
    });

    pipeline_begin();
    stage("Pre-State");
    int i = 420;
    const int ci = 67; // const int
    const int *p = &i; // pointer-to-const int; stores address of i

    kv("i -> ", i); // 420
    kv("ci -> ", ci); // 67
    kv("p -> ", p); // address of i
    kv("*p -> ", *p); // 420
    kv("&i -> ", &i); // address of i
    kv("&ci -> ", &ci); // address of ci
    blank();

    stage("Comparisons");
    kv("p == &i -> ", p == &i); // true
    kv("*p == i -> ", *p == i); // true
    blank();

    stage("Operation");
    kv("Reseat p -> ", "p = &ci");
    p = &ci;
    kv("p -> ", p); // address of ci;
    kv("*p -> ", *p); // 67
    kv("p == &ci -> ", p == &ci); // true
    blank();

    stage("Runtime Modifications");
    kv("Assign to non-const-> ", "i = 100");
    i = 100;
    kv("i -> ", i); // 100
    kv("p -> ", p); // address of  ci
    kv("*p -> ", *p); // value fo ci; 67
    blank();

    stage("Compile-Time Checks");
#if 0
    *p = 50; // cannot write through a const pointer
#endif
#if 0
int *bad = &ci // cannot assign a cont to a non-const pointer
#endif

    classify({
        "Well-Defined: binding a pointer-to-const to const or non-const objects.",
        "Well-Defined: reading through a pointer-to-const.",
        "Ill-Formed: assigning through a pointer-to-const.",
        "Ill-Formed: converting/assigning a const to a non-const pointer"
    });

    rule({
        "A pointer-to-const can point to both const and non-const objects.",
        "Const on the pointee type restricts modifications through that pointer.",
        "The pointer itself is still modifiable and can be reseated."
    });
    return 0;
}
