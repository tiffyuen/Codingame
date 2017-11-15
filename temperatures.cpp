#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int n; // the number of temperatures to analyse
    int closeInt = 5527;
    int closeDist = 5527;
    cin >> n; cin.ignore();
    
    if (n == 0) {
        closeInt = 0;
    } else {
        for (int i = 0; i < n; i++) {
            int t; // a temperature expressed as an integer ranging from -273 to 5526
            cin >> t; cin.ignore();
        
            if ((t > 0) && ((t-0) <= closeDist)) { // if t is positive and closer to 0
                closeInt = t;
                closeDist = t;
            } else if ((t < 0) && ((0-t) < closeDist)) { // t is negative and closer to 0
                closeInt = t;
                closeDist = -t;
            } else if (t == 0) {
                closeInt = 0;
                break; // exit program as 0 is the closest possible
            }// if
        } // for
    } // if
    cout << closeInt << endl;
}
