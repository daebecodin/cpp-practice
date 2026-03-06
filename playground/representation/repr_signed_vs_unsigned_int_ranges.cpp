/*
 * Created by Durand Dyer-Branch on 2/26/26.
 * Demonstrates that signed and unsigned types have same sizes but different limits
*/

#include "report.h"
#include <climits>
#include <iostream>
using namespace std;
using namespace rpt;

int main() {
    cout << boolalpha;
    header(
        "Represent Signed vs Unsigned Integer Ranges",
        "Show that signed and unsigned Integer types have same sizes but different ranges"
        );
    inputs({
        "No runtime inputs: inspect representable ranges via std::numeric_limits",
        "Types: short/unsigned short, int/unsigned int, long/unsigned long",
    });

    pipeline_begin();

    stage("Representation / Range");
    repr_range<int>("int");
    blank();
    repr_range<unsigned int>("unsigned int");
    blank();
    //TODO - Add more types


    note("Key Observations");
    kv("  Same size: ", sizeof(int) == sizeof(unsigned int));
    note("  Signed: half negative, half non-negative");
    note("  Unsigned: all non-negative, 2x signed positive range");
    blank();

    note("Promote - (n/a)");
    note("Compute - (n/a)");
    note("Convert / Assign - (n/a)");

    classify({
        "sizeof and numeric_limits: well-defined",
        "Exact ranges: implementation-defined (minimums guaranteed)"
    });

    rule({
        "Signed and unsigned types of same size have the same number of bits",
        "Signed ranges: ~ -2^2(n-1) to 2^(n-1)-1",
        "Unsigned ranges: 0 to 2^n-1",
        "Use signed for general arithmetic and unsigned for modulo semantics"
    });

    return 0;
}
