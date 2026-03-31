#include <iostream>
using std::cout; using std::endl;

int main() {
int sum{}, val{1};

while (val <= 10) {
    sum += val;
    ++val;
}
cout << "Sum of 1-10 inclusive -> " << sum << endl;
return 0;
}
<LeftMouse>
