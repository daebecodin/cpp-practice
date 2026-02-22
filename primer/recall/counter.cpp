/*
 * Created by Durand Dyer-Branch on 2/21/26.
 * This is a counter program that reads a stream of consecutive integers and prints the count of those integers.
 * When that group is over the count is printed, and we move over to the next group to count.
 * At the final group we manually print the count
*/

#include <iostream>
using namespace std;

void v1()
{
    int firstNum;
    int cnt = 1;

    if (cin >> firstNum) {
        int nextNum;
        while (cin >> nextNum) {
            if (firstNum == nextNum) {
                cnt++;
            } else {
                cout << firstNum << " occurs " << cnt << " times" << '\n';
                firstNum = nextNum;
                cnt = 1;
            }
        }
        cout << firstNum << " occurs " << cnt << " times" << '\n';
    } else {
        cout << "no valid numbers found" << '\n';
    }
}

int main()
{
    v1();
    return 0;
}