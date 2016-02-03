// Node.cpp

#include <iostream>
#include "Node.h"
#include "Globals.h"
#include "Text.h"

Node::Node(void)
{
    unsigned int i = 0;
    
    index = FAIL;
    name = "Default";
    desc = "Default";
    nOpts = 0;
    for (i = 0; i < M_OPT; ++i) {
        opts[i] = "Empty";
        optAct[i] = A_NULL;
        optTarg[i] = FAIL;
        optAct2[i] = A_NULL;
        optTarg2[i] = FAIL;
        optReq[i] = S_ALL;  //Everybody wins with the S_ALL state flag
    }
}

void Node::play(int action, int *comd, int* state)  //The play function takes 3 arguments: Action - what action you are doing in the room
//Action - What action you are doing in the room
//*comd  - A pointer to the command array (which is filled in by picking an option to be processed later)
//*state - A pointer to the state array. This is an array where each index in the array is a state flag set to either 1 or 0.
//         Some actions require a state flag to be 1 or 0 before it will be available.
{
    int i = 0;;
    int rPrompt = 0;
    std::string prompt = desc;
    int choice = FAIL;
    int optsA[M_OPT];
    int nOptsA = 0;
    
    while (1) {     //Stay at the node until we place a legal command
        std::cout << name << std::endl << std::endl;
        rPrompt = wrap(&prompt);
        std::cout << prompt << std::endl;
        nOptsA = 0;
        for (i = 0; i < nOpts; i++) {   //Cycle through options and creates a list noptsA long of possible options based of the required states of each option
            if (optReq[i] >= 0) {       //If the optreq is positive, it means the corresponding state flag must be 1 (true) to meet the requirement.
                if (state[optReq[i]] == 1) {
                    optsA[nOptsA++] = i;
                }
            }
            else {                      //If the optreq is negative, it means the corresponding state flag must be zero (false) to meet the requirement.
                if (state[-optReq[i]] == 0) {
                    optsA[nOptsA++] = i;
                }
            }
        }
        for (i = 0; i < nOptsA; i++) {  //Print all the possible options
            std::cout << i+1 << ". " << opts[optsA[i]] << std::endl;
        }
        
        flush(rPrompt + nOptsA + 2);    //Fill in some space
        choice = getInt(nOpts);
        
        if (choice != FAIL) {
            comd[0] = optAct[optsA[choice - 1]];
            comd[1] = optTarg[optsA[choice - 1]];
            comd[2] = optAct2[optsA[choice - 1]];
            comd[3] = optTarg2[optsA[choice - 1]];  //Set the command
            return;
        }
    }
}
