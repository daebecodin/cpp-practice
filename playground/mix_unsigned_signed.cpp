/*
 * Created by Durand Dyer-Branch on 2/27/26.
*/

#include <iostream>
#include <iomanip>
#include "report.h"

using namespace std;
using namespace rpt;

int main()
{
    header(
        "Mixing Signed and Unsigned in a single expression",
        "Demonstrate the behavior of signed types when used in arithmetic or comparison with an unsigned type"
    );

    inputs({
        "Default: {unsigned int 10, signed int -42}",
        "User-Defined: {unsigned int u, signed int s}"
    });

    cout << "Would you like to run the static program or dynamic version? (s / d): ";
    string answer;
    if (!(cin >> answer)) {
        note("Input validation error. Try again.");
        return 1;
    }

    int s{};
    unsigned int u{};
    if (answer == "s" || answer == "S" ) {
        s = -42;
        u = 10;
    } else if (answer == "d" || answer == "D") {
        cout << "Enter your signed value: ";
        if (!(cin >> s)) {
            note("input validation error");
            return 1;
        }
        cout << "Enter your unsigned value: ";
        if (!(cin >> u)) {
            note("input validation error");
            return 1;
        }
    }

    pipeline_begin();
    repr_range<signed int>(" signed int");
    blank();
    repr_range<unsigned int>("unsigned int");
    blank();

    stage("Promotion");
    note("(n/a)");

    stage("Compute");
    note("(n/a)");

    stage("Convert / Assign");
    cout << boolalpha;
    kv("signed int s = ", s);
    kv("unsigned int u = ", u);
    unsigned int ui = static_cast<unsigned>(s);
    kv("s when converted to unsigned -> ", ui);
    kv("s < u -> ", s < u);
    kv("s > u -> ", s > u);

    classify({
        "Signed -> Unsigned: well-defined.",
        "Mixed signed and unsigned comparisons/expressions use the usual arithmetic conversions."
    });

    rule({
        "In expression mixed with signed/unsigned, the signed operand may be converted to unsigned.",
        "Negative signed values usually become large unsigned, which can flip comparisons."
    });




    return 0;
}