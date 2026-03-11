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
      "Top vs Low Level Const",
      "Show that top-level const is ignored during copying, while low-level const is preserved and restricts conversions."
    );

    inputs({
        "No Inputs",
        "Objects Involved: { int i, const int c1, int *p, const int *p pc }"
    });

    pipeline_begin();
    stage("Pre-State");
    int i = 420;
    const int ci = 67; // const int
    int *p = &i; // pointer to int
    const int *pc  = &ci; // low level pointer to const

    kv("i -> ", i); // 420
    kv("ci -> ", ci); // 67
    kv("p -> ", p); // address pf i
    kv("pc -> ", pc); // address of ci
    kv("*p -> ", *p); // 420
    kv("*pc -> ", *pc); // 67
    blank();

    stage("Copy Operations");
    int j = ci; // value coby; high-level const -> non-const
    int *p2 = p; // value copy from i;
    const int *pc2 = p; // pointer-to-const int; hold &i; get value copy; non-const -> low level const

    kv("j -> ", j); // value copy of ci; 67
    kv("p2 -> ", p2); // &i
    kv("pc2 -> ", pc2); // &i
    kv("*p2 -> ", *p2); // 420
    kv("*pc2 -> ", *pc2); // 420
    blank();

    stage("Compile-Time Checks");
#if 0
    int *bad = pc; // doesn't work bc requires low level conversion (dropping low level)
#endif

    stage("Runtime Modifications");
    i = 69;
    kv("i -> ", i); // 69
    kv("*p -> ", *p); // new value at &i
    kv("*pc2 -> ", *pc2); // new value at &i

    classify({
        "Well-Defined: copying objects where only top-level const is involved.",
        "Well-Defined: converting int *p -> const int *p2.",
        "Ill-Formed: converting const int *p -> int *p2"
    });

    rule({
        "Top-Level const can be applied to any object type and is ignored by regular value copying (the object itself is const).",
        "Low-Level const is applies to what a compound type refers or points to and is preserved in type conversions.",
        "You can add low-level const (int *p -> const int *p), but you cannot remove it (const int *p -> int *p2)",
        "The Distinction matters copies and conversions applied from them: Top level const is ignored. Low level is preserved",
    });
    return 0;
}
