/*
 * Created by imdem on 3/6/2026.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    cout << boolalpha;
    header(
      "Reference to Pointer",
      "Show that a reference can alias a pointer variable, allowing assignment"
        " through the reference to change which object the pointer points to."
    );

    inputs({
        "No Inputs",
        "Objects Involved: {int x, int y, int *p, int *&rp}"
    });

    pipeline_begin();
    stage("Pre-State");
    int x = 420;
    int y = 67;
    int *p = &x; // pointing to x
    int *&rp = p; // alias for pointer p

    kv("x -> ", x); // value of x
    kv("y -> ", y); // value of y
    kv("p -> ", p); // address of x
    kv("*p -> ", *p); // value of x
    kv("rp -> ", rp); // address of x
    kv("*rp -> ", *rp); // value of x
    kv("&p -> ", &p); // address of p
    kv("&rp -> ", &rp); // address of p
    kv("&x -> ", &x); // address of x
    kv("&y -> ", &y); // address of y
    blank();

    stage("Comparisons");
    kv("rp == p -> ", rp == p); // true
    kv("p == &x -> ", p == &x); // true
    kv("rp == &x -> ",rp == &x); // true
    kv("&p == &rp -> ", &p == &rp); // true
    blank();

    stage("Operation");
    kv("Reassign through the reference -> ", "rp = y"); // p now points to y
    rp = &y;
    blank();

    stage("Post-State");
    kv("p -> ", p); // address of y
    kv("*p -> ", *p); // value of y
    kv("rp -> ", rp); // address of y
    kv("*rp -> ", *rp); // value of y
    kv("&p -> ", &p); // address of p
    kv("&rp -> ", &rp); // address of p
    blank();

    stage("Post-Comparisons");
    kv("p == &y -> ", p == &y); // true
    kv("rp == &y -> ", rp == &y); // true
    kv("rp == p -> ", rp == p); // true
    kv("*p == y -> ", *p == y); // true
    kv("*rp == y -> ", *rp == y); // true
    kv("&p == &rp -> ", &p == &rp); // true

    classify({
        "Well-Defined: binding a reference to a live pointer object.",
        "Well-Defined: Assigning through a reference.",
        "Well-Defined: Dereferencing after the pointer points to a live object.",
        "Ill-Formed: uninitialized reference to a pointer (references are not objects).",
        "Undefined-Behavior: dereferencing through p or rp if the pointer value is null, uninitialized, or dangling."
    });

    rule({
        "Assigning though the reference to pointer affects the pointer it aliases, not the object pointed to.",
        "&p == &rp (A pointer and a reference to a pointer alias the same point pointer object).",
        "If a rp aliases a p, then changing the rp changes p; dereferencing either follows the same object."
    });
    return 0;
}
