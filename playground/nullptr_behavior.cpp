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
      "Null Pointer Behavior",
      "Understand what operations are valid on a null pointer and confirm that null ptr"
        " represents a pointer that does not point to any object."
    );

    inputs({
        "No inputs",
        "Objects Involved: {int x, int *p, int *q}"
    });

    pipeline_begin();
    stage("Pre-State");
    int x = 420;
    int *p = nullptr; // holds no object address
    int *q = &x; // hold address of x

    kv("x -> ", x); // object value
    kv("&x -> ", &x); // object address
    kv("p -> ", p); // 0
    kv("q -> ", q); // address of x
    kv("&p -> ", &p); // address of the pointer variable
    kv("&q -> ", &q); // address of the pointer variable
    blank();

    stage("Comparisons");
    kv("p == nullptr -> ", p == nullptr); // true
    kv("q == nullptr -> ", q == nullptr); // false
    kv("p == q -> ",p == q); // false
    kv("q == &x -> ", q == &x); // true
    blank();

    stage("Assignment");
    p = q; // p now points to object address held in q
    kv("p = q -> ", "p now points to address held in q");
    blank();

    stage("Post-State");
    kv("p -> ", p); // address of x;
    kv("*p -> ", *p); // value held in target address (no longer null)
    kv("p == nullptr -> ", p == nullptr); // false
    kv("p == &x -> ", p == &x); // true
    blank();

    classify({
        "Well-Defined: assigning to nullptr, comparing to nullptr, and printing valid pointer values.",
        "Undefined: attempting to dereference a nullptr (*p when p == nullptr)."
    });

    rule({
        "p == nullptr -> *p is UB (If p == nullptr, p points to no object; dereferencing *p is undefined behavior).",
        "p = q copies the address value (Pointer assignment replaces the stored address: p = q copies q's address value to p)."
        "p == q -> *p aliases x (After p = &x , p == &x and *p reads/writes x)."
    });

    return 0;
}