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
      "constexpr pointers",
      "Show that constexpr applied to a pointer makes the pointer itself constant (its value is known at compile time), "
            "but does not make the pointed-to object const."
    );

    inputs({
        "No Inputs",
        "Objects Involved: { int i, const int ci, constexpr int *p }"
    });

    pipeline_begin();
    stage("Pre-State");
    int i = 420;
    const int ci = 67;
#if 0
    constexpr int *p = &i;
#endif

    classify({
        "",
        "",
        ""
    });

    rule({
        "constexpr variables must be initialized with constant expressions.",
        "A constexpr pointer must be initialized with nullptr or the address of an object with static storage duration.",
        "Local variables do not have compile-time addresses, so &local_var cannot initialize to a constexpr pointer"
    });
    return 0;
}
