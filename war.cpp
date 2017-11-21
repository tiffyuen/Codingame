#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int getInt(queue<string>& a);
void addToQ(int battle, queue<string>& big, queue<string>& small, queue<string>& nQueue, queue<string>& mQueue, queue<string>& batNQ, queue<string>& batMQ);
void getNM(int& n, int& m, int& battle, queue<string>& nQueue, queue<string>& mQueue, queue<string>& batNQ, queue<string>& batMQ);

int main()
{
    int rounds = 0;
    int n;
    int m;
    int i;
    queue<string> nQueue;
    queue<string> mQueue;
    queue<string> batNQ;
    queue<string> batMQ;
    int battle = 0;

    // read in player 1 cards and add to queue
    cin >> n; cin.ignore();
    
    for (i = 0; i < n; i++) {
        string cardp1;
        cin >> cardp1; cin.ignore();
        nQueue.push(cardp1);
    }
    
    // read in player 2 cards and add to queue
    cin >> m; cin.ignore();
    
    for (i = 0; i < m; i++) {
        string cardp2;
        cin >> cardp2; cin.ignore();
        mQueue.push(cardp2);
    }

    // Compare cards while both players has > 0 cards
    while ((n > 0) && (m > 0))
    {
        getNM(n, m, battle, nQueue, mQueue, batNQ, batMQ);
        rounds += 1;
    } // while

    // output result
    if ((battle == 0) && (n <= 0)) // player 1 has no cards
        cout << 2 << " " << rounds << endl; // player 2 wins
    else if ((battle == 0) && (m <= 0))// player 2 has no cards
        cout << 1 << " " << rounds << endl; // player 1 wins
    else if (battle == 1) // one player has no cards during a war
        cout << "PAT" << endl; // tie
    return 0;
} // main

/* convert card number/alphabet to interger */
int getInt(queue<string>& a)
{
    int nInt;
    
    string nStr = (a.front()).substr(0, (a.front()).size()-1); // trim last char of n

    if (nStr == "J")
        nInt = 11;
    else if (nStr == "Q")
        nInt = 12;
    else if (nStr == "K")
        nInt = 13;
    else if (nStr == "A")
        nInt = 14;
    else
        nInt = stoi(nStr);
    
    return nInt;
} // getInt

/* Add/ Subtract cards from queue dependings on who is the winner/ if it is a war */
void addToQ(int battle, queue<string>& big, queue<string>& small, queue<string>& nQueue, queue<string>& mQueue, queue<string>& batNQ, queue<string>& batMQ)
{
    int i;
    int nSize = batNQ.size();
    int mSize = batMQ.size();
    
    // if war, add all cards facing down to winner's pile
    if (battle == 1)
    {
        for (i = 0; i < nSize; i++)
        {
            big.push(batNQ.front());
            batNQ.pop();
        }
    }
    
    // add cards to winner's pile
    big.push(nQueue.front());
    nQueue.pop();
   
    if (battle == 1) // battle
    {
        for (i = 0; i < mSize; i++)
        {
            big.push(batMQ.front());
            batMQ.pop();
        }
    }
    
    big.push(mQueue.front());
    mQueue.pop();
} // addToQ

/* get the value of n and m, use recursion for war */
void getNM(int& n, int& m, int& battle, queue<string>& nQueue, queue<string>& mQueue, queue<string>& batNQ, queue<string>& batMQ)
{
    int nInt = getInt(nQueue);
    int mInt = getInt(mQueue);
    int i;

    if (nInt > mInt) // player 1 gets the cards
    {
        addToQ(battle, nQueue, mQueue, nQueue, mQueue, batNQ, batMQ);
        
        if (battle == 1)
            n += 9; // add 4 cards from self, 4 cards from opponent, and 2 cards from current comparison
        else
            n += 1;
            
        m -= 1;
    } else if (nInt < mInt)
    {
        addToQ(battle, mQueue, nQueue, nQueue, mQueue, batNQ, batMQ);
        
        if (battle == 1)
            m += 9;
        else 
            m += 1;
        n -= 1;
    }
    else // war
    {
        battle = 1; // set battle to true
        
        // exit function if one player will have no cards after putting out 3 extra cards
        if ((n <= 4) || (m <= 4))
        {
            n = 0;
            m = 0;
            return;
        }    
        
        for (i = 0; i < 4; i++) // pop current and next 3 cards
        {
            batNQ.push(nQueue.front());
            nQueue.pop();
        }
        
        for (i = 0; i < 4; i++) // pop current and next 3 cards
        {
            batMQ.push(mQueue.front());
            mQueue.pop();
        }

        n -= 4;
        m -= 4;
        getNM(n, m, battle, nQueue, mQueue, batNQ, batMQ); // compare next 2 cards and see who the pile belongs to
        battle = 0; // end of war, reset battle to false
    }
    
    return;
} // getNM
