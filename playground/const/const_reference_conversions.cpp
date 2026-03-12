/*
 * Created by imdem on 3/11/2026.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    header(
      "Const Reference Conversions",
      "Show that references behave like pointers regarding low-level const: a reference-to-const can bind to a non-const object"
        ", but a non-const reference cannot bind to a const object."
    );

    inputs({
        "No Inputs",
        "Objects Involved: { int i, const int ci, int &r, const int &rc }"
    });

    pipeline_begin();
    int i = 420; // int
    const int ci = 67; // const int
    int &r = i; // reference to an int
    const int &rc = i; // reference toa const int

    kv("i -> ", i); // 420;
    kv("ci -> ", ci); // 67
    kv("r -> ", r); // 420
    kv("rc -> ", rc); //420
    kv("&i -> ", &i); // address of i
    kv("&ci -> ", &ci); // address of ci
    kv("&r -> ", &i); // address of i
    kv("&rc -> ", &i); // address of i
    blank();

    stage("Comparisons");
    kv("r == i -> ", r == i); // true
    kv("rc == i -> ", rc == i); // true
    kv("&r == &i -> ", &r == &i); // trur
    kv("&rc == &i -> ", &rc == &i); // true
    blank();

    i = 69;
    rc = ci;


    classify({
        "",
        "",
        ""
    });

    rule({
        "",
        "",
        ""
    });
    return 0;
}
