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
        "Pointer Reassignment",
        "Show that reassigning a pointer (p = &y) changes the address stored in the pointer, not the objects. "
        "After reassignment, *p refers to a different object."
    );

    inputs({
        "No inputs",
        "Objects involved: {int x, int y, int* p}"
    });

    int x = 420; // starting value
    int y = 69; // reassignment value
    int* p = &x; // pointer to x

    pipeline_begin();
    stage("Pre-State");
    kv("x -> ", x); // value of x
    kv("y -> ", y); // value of y
    kv("&x -> ", &x); // address of x
    kv("&y -> ", &y); // address of y
    kv("p -> ", p); // address of x
    kv("*p -> ", *p); // value of x stored in p
    kv("&p -> ", &p); // address of p
    blank();

    stage("Reassignment");
    p = &y; // reassigning p to point to y instead of x
    kv("p = &y -> ", "p = ?");
    blank();

    stage("Mid-State");
    kv("x -> ", x); // value of x
    kv("y -> ", y); // value of y
    kv("&x -> ", &x); // address of x
    kv("&y -> ", &y); // address of y
    kv("p -> ", p); // address of y
    kv("*p -> ", *p); // value of y stored in p
    kv("&p -> ", &p); // address of p
    blank();

    stage("Post-State");
    kv("x -> ", x); // value of x
    kv("y -> ", y); // value of y
    kv("p -> ", p); // address of y
    kv("*p -> ", *p); // value of y stored in p
    blank();

    stage("Comparisons");
    cout << boolalpha;
    kv("p == &x -> ", p == &x); // should be false
    kv("p == &y -> ", p == &y); // should be true
    kv("*p == x -> ", *p == x); // should be false
    kv("*p == y ->", *p == y); // should be true
    blank();

    classify({
        "p = &y is well-defined as an assignment to the pointer (changes the object pointed to).",
        "Dereferencing *p is defined if p pointes to a live object.",
        "Dereferencing nullptr / uninitialized/ dangling pointer is undefined behavior.",
    });

    rule({
        "p = &y -> p == &y (Reassigning a pointer changes the address it stores).",
        "If p == &y -> *p reads/writes y (After reassignment, dereferencing follows the new target).",
        "Changing p does not change x/y (modifying pointer); changing *p does (modifying object stored)."
    });

    return 0;
};