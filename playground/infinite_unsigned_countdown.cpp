/*
* Created by Durand Dyer-Branch on 2/28/26.
*/

#include <iostream>
#include "report.h"
using namespace std;
using namespace rpt;

int main()
{
    header(
        "Infinite Unsigned Countdown",
        "Demonstrate how loop conditions with unsigned numbers break with unsigned wraparound"
    );

    inputs({
        "Where to start decrementing from -> start",
        "Suggested: {10-25}"
    });

    pipeline_begin();
    repr_range<unsigned int>("unsigned int");
    blank();

    stage("Promotion");
    note("(n/a) no mixed-type expression/conversions");

    stage("Compute");
    note("(n/a) no arithmetic to follow; program is control-flow & decrement");

    stage("Convert / Assign");
    unsigned int start{};
    cout << "Where do you want to start decrementing from?: ";
    if (!(cin >> start)) {
        note("input validation error");
        return 1;
    }
    unsigned int i = start;
    note("Demo: while (i >= 0) will always be true for unsigned");
    note("We will manually break once unsigned wrap occurs (i becomes very large)");

    while (i >= 0) {
        kv("i = ", i);

        if (i == 0) {
            cout << "now we decrement from 0\x0a";
        }

        --i;

        if (i > start) {
            kv("0 when wrapped = ", i);
            kv("UINT_MAX = ", UINT_MAX);
            note("Breaking to avoid ∞ loop.");
            break;
        }
    }

    classify({
        "Unsigned Wraparound is well-defined by mod 2^n",
        "N is the number of bit of the unsigned type",
        "Loop condition i >= 0 is always true, so it never terminates"
    });

    rule({
        "For unsigned i, the condition i >= 0 will always be true, so a countdown loop like for (unsigned i; i >= 0; --i) never terminates",
        "When i reaches 0 and decrements, it wraps to UINT_MAX (mod 2^n)"
    });
    return 0;
}