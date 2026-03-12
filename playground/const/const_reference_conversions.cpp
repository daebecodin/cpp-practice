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
        "Objects Involved: { int i, }"
    });

    pipeline_begin();

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
