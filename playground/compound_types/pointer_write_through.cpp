/*
 * Created by imdem on 3/4/2026.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main ()
{
    header(
        "Pointer Write-Through",
        "Demonstrate that writing through a pointer (*p = ...) modifies the pointed-to object, not the pointer"
    );

    inputs({
        "No inputs",
        "Objects involves: {int x , int* p}"
    });

    int x = 420;
    int* p = &x;

    pipeline_begin();
    stage("Pre-State");
    kv("x -> ", x);
    kv("&x -> ", &x);
    kv("p -> ", p);
    kv("*p -> ", *p);
    kv("&p -> ", &p);
    blank();

    stage("Write-Through");
    *p = 69;
    kv("*p = 69 -> ?","" );
    blank();

    stage("Post-State");
    kv("x -> ", x); // should be new value
    kv("&x -> ", &x); // stays same
    kv("p -> ", p); // stays same
    kv("*p -> ", *p); // should be new value
    kv("&p -> ", &p); // stays same
    blank();

    stage("Comparisons");
    cout << boolalpha;
    kv("x == *p -> ", x == *p); // should be true
    kv("p == &x -> ", p == &x); // should be true

    classify({
        "*p = NEW is an assignment to the object stored, not the pointer.",
        "Well-defined if p points to a live object",
        "Undefined if p is uninitialized, assigned to nullptr, or dangling."
    });

    rule({
        "If p == &x -> *p == x (they alias the same object)",
        "If *p = v -> x becomes v (update value at the object at the address stored in p)",
        "*p = v does not change p (updating the pointee, not the pointer"
    });

    return 0;
}