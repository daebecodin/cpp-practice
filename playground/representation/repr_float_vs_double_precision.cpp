/*
 * Created by Durand Dyer-Branch on 2/26/26.
 *
 * Comparing float vs double precision and showing where
*/
#include "report.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
using namespace rpt;

int main()
{
    cout << boolalpha;
    header(
        "Represent Float Precision vs Double",
        "Show that float have fewer precision digits than a double; precision limits what values are representable."

    );

    inputs({
        "Fixed values: test whether adding 1 a large float vs a large double",
        "Also print binary digits and max representable digits for float/double"
    });

    pipeline_begin();
    stage("Representation / Range");
    repr_range<float>("float");
    blank();
    repr_range<double>("double");
    blank();

    /*
     *  Were demonstrating a simple precision cliff.
     *  Around 2^24, float can no longer represent every integer.
     *  2^24 = 16777216
     */
    stage("Promotion");
    note("Operation are performed in float for float variables and in double for double variables (no mixed operands needed)");

    stage("Compute");
    note("Test: does x + 1 change x?");
    blank();

    float xf = 16777216.0f;
    float xf2 = 2e7f;
    float nextf = nextafterf(xf2, numeric_limits<float>::infinity());
    float gapf = nextf - xf2;


    double xd = 16777216.0; // same magnitude but double precision;
    double xd2 = 2e7;
    double nextd = nextafter(xd2, numeric_limits<double>::infinity());
    double gapd = nextd - xd2;

    cout << fixed << setprecision(0);
    kv("2e7f = ", xf2);
    kv("next = ", nextf);
    kv("gap = ", gapf);
    blank();

    cout << fixed << setprecision(0);
    kv("xf = ", xf);
    kv("xf + 1 = ", xf + 1.0f);
    kv("xf == xf + 1: ", (xf == xf + 1.0f));
    blank();

    cout << fixed << setprecision(17);
    kv("2e7 = ", xd2);
    kv("next = ", nextd);
    kv("gap = ", gapd);
    blank();

    cout << fixed << setprecision(17);
    kv("xd = ", xd);
    kv("xd + 1 = ", xd + 1.0);
    kv("xd == xd + 1: ", (xd == xd + 1.0));
    blank();

    stage("Conversion / Assignment");
    note("(n/a)");

    classify({
        "Floating-Point Arithmetic and Comparisons: well defined through precision and rounding",
        "nextafter/nextafterf: Reveals the gap between adjacent representable value at x (next float given the gap)",
        "Exact gap values depend on the implementation’s floating format (typically IEEE-754), so the observed gap is implementation-defined in detail."
    });
    rule({
        "Float: At 2^24, float spacing is 2; at 2^25, spacing is 4. In general, the gap depends on the exponent and doubles whenever the exponent increases by 1.",
        "Double: At 2^52, double spacing is 1; at 2^53, spacing is 2. In general, the gap depends on the exponent and doubles whenever the exponent increases by 1.",
        "Gaps are influenced by type and the exponent of x.",
        "If the local gap (ULP) near x—the spacing between adjacent representable floats around x—is less than the amount you add, then the stored result changes; "
        "if the gap is greater than or equal to the amount you add, the exact sum may round to the same representable value (often back to x)."
    });

    return 0;
}