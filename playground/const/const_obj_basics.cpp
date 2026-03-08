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
      "Const Object Basics",
      "Show that `const` must be initialized, cannot be assigned though its own name after creation,"
      " but can still read and copied to another object"
    );

    inputs({
        "No Inputs",
        "Objects Involved: {int i, const int ci, int j}"
    });

    pipeline_begin();
    int i = 420;
    const int ci = i; // non-const copied to a const onj
    int j = ci; // const copied to a non-const object

    stage("Pre-State");
    kv("i -> ", i); // 420
    kv("ci -> ", ci); // 420
    kv("j -> ", j); // 420
    kv("&i -> ", &i); // address of i
    kv("&ci -> ", &ci); // address of ci
    kv("&j -> ", &j); // address of j
    blank();

    stage("Comparisons");
    kv("ci == i -> ", ci == i); // true, valued copied
    kv("j == ci -> ", j == ci); // true; valued copied
    blank();

    stage("Compile-Time Check");
#if 0
    const int bad; // must initialize
    kv("create -> ", bad);
#endif
#if 0
    ci = 99; // cannot reassign to a const
#endif
    blank();

    stage("Runtime Modifications");
    i = 69; // reassign i;
    j = 67; // 67;  its just has a copy, so ci not updated
    kv("i -> ", i); // 69 through reassignment
    kv("ci -> ", ci); // 420 bc it just receives a copy
    kv("j -> ", j); // 67 through reassignment

    classify({
        "Well-Defined: initializing a const object.",
        "Well-Defined: reading a const object.",
        "Well-Defined: copying a const object value to another object.",
        "Ill-Formed: uninitialized const object.",
        "Ill-Formed: reassignment to a const object."
    });

    rule({
        "A const object must be initialized.",
        "Assigning to a const object is il-formed",
        "If a non-const object is initialized from a const object, it gets a value copy; updating the non-const later does not change the const.",
        "If a const object is initializes from another object, it gets a value copy; updating the source later does not change the const."
    });
    return 0;
}
