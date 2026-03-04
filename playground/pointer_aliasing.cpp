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
        "Pointer Aliasing",
        "Show that two pointers can store the same address,, so writing through one (*q = ...) changes what the other "
            "pointer (*p) sees, because they alias the same object"
        );

    inputs({
        "No inputs",
        "Objects involved: {int x, int* p = &x, int* q = &x}"
    });

    int x = 420;
    int* p = &x; // points to x
    int* q = &x; // points to x

    pipeline_begin();
    stage("Pre-State");
    kv("x -> ", x); // value of x
    kv("&x -> ", &x); // address of x
    kv("p -> ", p); // address of object pointed to
    kv("q -> ", q); // address of object pointed to
    kv("*p -> ", *p); // value of object pointed to
    kv("*q -> ", *q); // value of object pointed to
    kv("&p -> ", &p); // address of pointer object
    kv("&q -> ", &q); // address of pointer object
    blank();

    stage("Aliasing Write-Through");
    *q = 69;
    note("Here we assign *q with a ner value");
    kv("*q -> " , *q);
    kv("*p -> ", "?");
    blank();

    stage("Post State");
    kv("x -> ", x); // new value of x
    kv("&x -> ", &x); // stay same
    kv("p -> ", p); // stay same
    kv("q -> ", q); // stays same
    kv("*p -> ", *p); // new value of object pointed to
    kv("*q -> ", *q); // new value of object pointed to
    kv("&p -> ", &p); // stays same
    kv("&q -> ", &q); // stay same
    blank();

    stage("Comparisons");
    cout << boolalpha;
    kv("p == q -> ", p == q); // should be true
    kv("p == &x -> ", p == &x); // should be true
    kv("q == &x -> ", q == &x); // should be true
    kv("x == *p -> ", x == *p); // should be true
    kv("x == *q -> ", x == *q); // should be true
    kv("*p == *q -> ", *p == *q); // should be true
    blank();

    classify({
        "*q is well-defined if q points to a live object.",
        "With p = &x and q = &x, dereferencing both is well-defined.",
        "Reading/dereferencing an uninitialized pointer is undefined behavior.",
        "Dereferencing nullptr is undefined behavior.",
        "Dereferencing a dangling pointer is undefined behavior"
    });

    rule({
        "If p == q -> *p and *q alias the same object.",
        "*q = v -> *p == v, when p == q (writing through one alias updates the shared object for the other alias as well.)",
        "&p != &q (pointer objects are separate variables, even when pointing to the same object (p == q))."
    });



}
