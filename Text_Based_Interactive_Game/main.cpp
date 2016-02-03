#include <iostream>
#include <stdlib.h>
#include "Globals.h"
#include "Node.h"
#include "Text.h"
#include "Game.h"

using namespace std;

int main()
{
    Node nodes[N_NDS];
    int currN = 0;          //The current node
    int state[NSTATE];      //The state flags
    int comd[4] = {A_MOVE,0,A_NULL,0}; //{Action, Target, Action2, Target2}
    
    init(nodes,state);
    
    while (1) {
        cout << "Run" << endl;
        switch (comd[2]) {        //Perform Action2 first. This is the auxiliary action used to set variables etc. Usually nothing.
            case A_NULL: break;
            case A_TON:
                state[comd[3]] = 1;     //Turn a state flag on
                break;
            case A_TOFF:
                state[comd[3]] = 0;     //Turn a state flag off
                break;
            default:
                cout << "Error: Invalid Action2: " << comd[3] << endl;
        }
        switch (comd[0]) {
            case A_NULL:                            //If we aren't moving, just play the current node again
                nodes[currN].play(0,comd,state);
                break;
            case A_MOVE:                            //If the action is to move, then store the new node (currN) and play the new node.
                currN = comd[1];
                nodes[currN].play(0,comd,state);    //Play the new node
                break;
            case A_SUICIDE:
                cout << "You lose" << endl;         //Because suicide is bad
                flush(3);
                break;
            default:
                cout << "Error: Invalid Action" << endl;
        }
    }
    
    return EXIT_SUCCESS;
}

