#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();
        
        if ((lightX == initialTX) && (lightY != initialTY)) { // if same x-axis
            if (lightY > initialTY) { // south
                cout << "S" << endl;
                initialTY += 1;
            } else { // north
                cout << "N" << endl;
                initialTY -= 1;
            } // if
        } else if((lightX != initialTX) && (lightY == initialTY)) { // if same y-axis
            if (lightX > initialTX) { // east
                cout << "E" << endl;
                initialTX += 1;
            } else { // west
                cout << "W" << endl;
                initialTX -= 1;
            } // if
        } else if ((lightX > initialTX) && (lightY > initialTY)) { // south-east
            cout << "SE" << endl;
            initialTX += 1;
            initialTY += 1;
        } else if ((lightX > initialTX) && (lightY < initialTY)) { // north-east
            cout << "NE" << endl;
            initialTX += 1;
            initialTY -= 1;
        } else if ((lightX < initialTX) && (lightY < initialTY)) { // north-west
            cout << "NW" << endl;
            initialTX -= 1;
            initialTY -= 1;
        } else if ((lightX < initialTX) && (lightY > initialTY)) { // south-west
            cout << "SW" << endl;
            initialTX -= 1;
            initialTY += 1;
        } // if
    } // while
}
