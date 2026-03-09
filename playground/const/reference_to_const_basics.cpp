/*
 * Created by imdem on 3/8/2026.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    cout << boolalpha;
    header(
      "Reference to Const Basics",
      "Show that a reference to const can bind to both const and non-const objects, allows reading but not writing through the reference,"
      " and does not necessarily mean the underlying object itself is const."
    );

    inputs({
        "No Inputs",
        "Objects Involved: { int t, const int ci, const int &r1, const int &r2 }"
    });

    pipeline_begin();
    stage("Pre-State");
    int i = 420;
    const int ci = 67;
    const int &r1 = i; // reference to const of non-const int (const alias)
    const int &r2 = ci; // reference to const of const int (const alias)

    kv("i -> ", i); // 420
    kv("ci -> ", ci); // 67
    kv("r1 -> ", r1); // 420
    kv("r2 -> ", r2); // 67
    blank();

    stage("Comparison");
    kv("r1 == i -> ", r1 == i); // true bc alias
    kv("r2 == ci -> ", r2 == ci); // true bc alias
    kv("&r1 == &1 -> ", &r1 == &i); // true bc alias
    kv("&r2 == &ci -> ", &r2 == &ci); // true bc alias
    blank();

    stage("Runtime Modifications");
    i = 69; // modifying non-const object; should update the reference as well
    kv("assigning 69 to ", "i");
    kv("i -> ", i); // 69
    kv("r1 -> ", r1); // 69;
    kv("ci -> ", ci); // 67
    kv("r2 -> ", r2); // 67
    blank();

    stage("Compile-Time Checks");
#if 0
    r1 = 5; // cannot write through const reference
#endif
#if 0
    const int &bad; // must initialize all reference
#endif


    classify({
        "Well-Defined: binding a reference-to-const to a const or non-const object.",
        "Well-Defined: reading through a reference-to-const.",
        "Ill-formed: assigning through a reference-to-const."
    });

    rule({
        "A reference-to-const can bind to both const and non-const objects.",
        "A reference-to-const aliases its bound object, but does not allow modification through that reference.",
        "Binding a reference-to-const to a non-const object does not make the original object const."
    });
    return 0;
}
