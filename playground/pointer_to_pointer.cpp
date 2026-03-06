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
      "Pointer to Pointer",
      "Show that a pointer can store the address of another pointer, allowing indirect access to the original object through "
        "multiple dereference levels."
    );

    inputs({
        "No Inputs",
        "Objects Involved: { int x, int *p, int **pp}"
    });

    pipeline_begin();
    stage("Pre-State");
    int x = 67;
    int *p = &x; // pointer -> int x
    int **pp = &p; // pointer -> pointer -> int x

    kv("x -> ", x); // value stored in x
    kv("&x -> ", &x); // address of x
    kv("p -> ", p); // address stored in p (x)
    kv("*p -> ", *p); // value inside of address pointed to
    kv("&p -> ", &p); // address of pointer p
    kv("pp -> ", pp); // address of the pointer pointing to
    kv("*pp -> ", *pp); // address stored in the pointer pointing to
    kv("**p -> ", **pp); // value of the object address stored in the pointer pointing to
    kv("&pp -> ", &pp); // address of the pointer pp
    blank();

    stage("Comparisons");
    kv("p == &x -> ", p == &x); // true
    kv("pp == &p -> ", pp == &p); // true
    kv("*pp == p -> ", *pp == p); // true
    kv("**pp == x -> ", **pp == x); // true

    classify({
        "Well-Defined: pointer assignment.",
        "Well-Defined: multi-level dereferencing when each pointer pointes to a live object.",
        "Undefined-Behavior: dereferencing any null, uninitialized, opr dangling pointer."
    });

    rule({
        "For each level of indirection, we must provide a dereference operator in order to reach the base object pointed to.",
        "A dereferenced pointer to pointer gives the pointer it points to (if pp == &p -> *pp == p).",
        "If p == &x and pp == &p -> **pp aliases x."
    });
    return 0;
}