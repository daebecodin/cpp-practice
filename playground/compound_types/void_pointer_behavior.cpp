/*
 * Created by imdem on 3/5/2026.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    cout << boolalpha;
    header(
        "Void Pointer Behavior",
        "Show that void* can store any object address, but cannot be dereferenced without a cast."
    );

    inputs({
        "No Inputs",
        "Objects Involves: {int x, double d, void *vp}"
    });

    pipeline_begin();
    int x = 420;
    double d = 6.7;
    void *vp = &x; // vp holds address of x

    stage("Pre-State");
    kv("&x -> ", static_cast<const void*>(&x)); // address of x
    kv("&d -> ", static_cast<const void*>(&d)); // address of x
    kv("vp -> ", static_cast<const void*>(vp)); // address of x
    kv("vp == nullptr -> ", vp == nullptr); // false
    blank();

    stage("Operation");
    vp = &d; // reassign to d;
    kv("vp = &d -> ", "reassigning our void ptr to d");
    blank();

    stage("Post-State");
    kv("vp -> ", vp);
    kv("vp == nullptr -> ", vp == nullptr); // false
    blank();

    stage("Compile-Time Checks");
#if 0
    kv("*vp -> ", *vp); // cannot operate on void type
#endif
#if 0
    kv("vp + 1 -> ", vp + 1); // cannot operate on void type
#endif
    blank();

    classify({
        "Well-Defined: assigning/comparing void* with address and nullptr",
        "Ill-Formed: dereferencing void* without cast; pointer arithmetic on void*",
    });

    rule({
        "void* can store the address of any object.",
        "Dereferencing void* is ill-formed (unless you cast to real pointer type first) because the compiler doesn't know the object type.",
        "Pointer arithmetic on void* is ill-formed in standard C++."
    });
    return 0;
}