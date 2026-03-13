/*
 * Created by imdem on 3/13/2026.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    header(
     "constexpr basics",
     "Show that constexpr guarantees a compile-time constant, while const only prevents modifications and may still be initialized at runtime"
   );

    inputs({
        "No Inputs",
        "Objects Involved: { int i, const int ci, constexpr int cx }"
    });

    pipeline_begin();
    stage("Pre-State");
    int i = 420;
    const int ci = i; // value copy of i; separate object
    constexpr int cx = 67;
    kv("i -> ", i); // 420
    kv("ci -> ", ci); // 420; value copy
    kv("cx -> ", cx); // 67
    kv("&i -> ", &i); // address of i
    kv("&ci -> ", &ci); // address of ci
    kv("&cx -> ", &cx); // address of cx
    blank();

    stage("Compile-Time Checks");
#if 0
    int arr1[cx];
#endif
#if 0
    int arr2[ci]; // not guaranteed in standard c++
#endif
    blank();

    stage("Runtime Modifications");
    i = 69;
    kv("Assign 69 -> ", "i");
    kv("i -> ", i); // 69
    kv("ci -> ", ci); // 420; separate obj so keeps copied value
    kv("cx -> ", cx); // 67

    classify({
        "Well-Defined: constexpr variables initialized with constant expressions.",
        "Well-Defined: const objects initialized with runtime values.",
        "Ill-Formed: constexpr initialized with a non-constant expression"
    });

    rule({
        "const prevents modification after initialization, but does not guarantee compile-time constancy.",
        "constexpr requires a constant-expression initializer and guarantee compile-time constancy.",
        "A const object initialized from a runtime value (const int ci = i) is a runtime constant, not a constexpr"
    });
    return 0;
}
