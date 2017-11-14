#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/
int main()
{
    int mVal;
    int mIndex;
    vector<int> mountainVec;
    
    // game loop
    while (1) {
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain.
            cin >> mountainH; cin.ignore();
            mountainVec.push_back(mountainH); // add height to vector
        }
        
        // find max height and its corresponding index
        mVal = *max_element(mountainVec.begin(), mountainVec.end());
        mIndex = find(mountainVec.begin(), mountainVec.end(), mVal) - mountainVec.begin();
        //cerr << "mval = " << mVal << endl;
        //cerr << "mInt = " << mIndex << endl;

        cout << mIndex << endl; // The index of the mountain to fire on.
        mountainVec.clear(); // clear vector for next turn
    }
}