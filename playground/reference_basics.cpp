/*
 * Created by imdem on 3/5/2026.
*/

#include <iostream>
#include <report.h>
using namespace std;
using namespace rpt;

int main()
{
    cout << boolalpha;
    header(
        "Reference Basics",
        "Show that a reference is an alias to an existing object: it must be initialized, shared the same address as the "
            "referent, cannot be reseated, and writing through it update the original object."
    );

    inputs({
        "No Inputs",
        "Objects Involved: {int x, int y, int &rx}"
    });

    pipeline_begin();
    stage("Pre-State");
    int x = 420;
    int y = 69;
    int &rx = x; // reference to x

    kv("x -> ", x); // value of x
    kv("y -> ", y); // value of y
    kv("rx -> ", rx); // value of rq
    kv("&x -> ", &x); // address of x
    kv("&y -> ", &y); // address of y
    kv("&rx -> ", &rx); // address of rx
    blank();

    stage("Pre-Comparisons");
    kv("&rx == &x -> ", &rx == &x); // true
    kv("rx == x -> ", rx == x); // true
    blank();

    stage("Operation");
    rx = 67;
    kv("writing through rx -> ", rx); // updates both x adn rx
    kv("now x is simultaneously -> ", x);
    x = 420;
    kv("writing through x -> ", x); // updates both x and rx
    kv("rx is now -> ", rx);
    blank();

    stage("Post-State");
    kv("x -> ", x); // value of x
    kv("y -> ", y); // value of y
    kv("rx -> ", rx); // value of x
    kv ("&x -> ", &x); // address of x
    kv("&rx -> ", &rx); // address of x
    blank();

    stage("Post_Comparisons");
    kv("rx == x -> ", rx == x); // true
    kv("&rx == &x -> ", &rx == &x); // true
    blank();

    stage("Compile-Time Checks");
#if 0
    int &bad; // references are not objects; must be initialized
#endif
#if 0
    rx = y; // cannot reseat references; assigns to refered object
#endif
    blank();

    classify({
        "Well-Defined: references bound to a live object; reading/writing through the object.",
        "Ill-formed: uninitialized reference",
        "Undefined: reference bound to a dead object (dangling reference) (yet to test)"
    });

    rule({
        "A reference must be initialized to an existing object.",
        "A reference is an alias: &rx = x and rx reads/writes the same object when bound to x.",
        "Assignment to rx assigns to the referred object."
        "rx = y doe snot reseat; it assigns y's value into the object rx refers to (x)."
    });
    return 0;
}