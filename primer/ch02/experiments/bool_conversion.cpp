/*
 * Created by Durand Dyer-Branch on 2/20/26.
 * Boolean conversion
 * When converting a non-bool arithmetic value to a bool object,
 * the result will be false if the value is 0 and true otherwise
*/

#include <iostream>
using namespace std;

int main() {

    cout << boolalpha;
    // Integers
    cout << "Integers\n";
    int n1 = 47;
    bool result = n1;
    cout << n1 << " -> " << result << "\n";

    int n2 = -47;
    result = n2;
    cout << n2 << " -> " << result << "\n";

    int n3 = 0;
    result = n3;
    cout << n3 << " -> " << result << "\n";
    cout << endl;


    // Doubles
    cout << "Doubles\n";
    double d1 = 53.14;
    result = d1;
    cout << d1 << " -> " << result << "\n";

    double d2 = 0.0;
    result = d2;
    cout << d2 << " -> " << result << "\n";
    cout << endl;

    // Unsigned Integers
    cout << "Unsigned Integers\n";
    unsigned int ui1 = 0;
    result = ui1;
    cout << ui1 << " -> " << result << "\n";

    unsigned int ui2 = 100;
    result = ui2;
    cout << ui2 << " -> " << result << "\n";
    cout << endl;

    return 0;
}