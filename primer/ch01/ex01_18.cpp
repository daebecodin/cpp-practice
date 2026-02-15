/*
* Created by Durand Dyer-Branch on 2/14/26.
*
*/

#include <iostream>

int main()
{
    int currVal = 0, val = 0;

    if (std::cin >> currVal) { // looks for valid input from first input
        int cnt = 1;

        while (std::cin >> val) { // reads next input value and stores in val
            if (val == currVal) { // if same then
                ++cnt; // increment count
            } else { // if the match chain ends
                std::cout << currVal << " occurs " << cnt << " times" << std::endl; // print out occurrence
                currVal = val; // make the new current the next in the line of inputs
                cnt = 1; //reset count
            }

        }
        std::cout << currVal << " occurs " << cnt << " times" << std::endl; // when we reach eof since we need to print the last groups
    }

    return 0;
}