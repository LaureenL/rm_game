#include "Game.h"
#include "Globals.h"

void init (Node* nodes, int* state)
{
    int i = 0;
    for (i = 0; i < NSTATE; i++) {
        state[i] = 0;
    }
    state[S_ALL] = 1;
    
    /*_______ROOM__________*/
    nodes[0].name = "Your Room";
    nodes[0].desc = "A cool room you live in";
    nodes[0].nOpts = 2;
    
    nodes[0].opts[0] = "Go to lounge";
    nodes[0].optAct[0] = A_MOVE;
    nodes[0].optTarg[0] = 1;
    
    nodes[0].opts[1] = "Kill yourself";
    nodes[0].optAct[1] = A_SUICIDE;
    nodes[0].optTarg[1] = 0;
    
    /*_______LOUNGE__________*/
    nodes[1].name = "Lounge";
    nodes[1].desc = "The lounge where you watch tv";
    nodes[1].nOpts = 4;
    
    nodes[1].opts[0] = "Go to room";
    nodes[1].optAct[0] = A_MOVE;
    nodes[1].optTarg[0] = 0;
    
    nodes[1].opts[1] = "Go to Corridor";
    nodes[1].optAct[1] = A_MOVE;
    nodes[1].optTarg[1] = 2;
    
    nodes[1].opts[2] = "Turn on TV";
    nodes[1].optAct2[2] =  A_TON;
    nodes[1].optTarg2[2] = S_TV;
    nodes[1].optReq[2] = -S_TV;
    
    nodes[1].opts[3] = "Turn off TV";
    nodes[1].optAct2[3] =  A_TOFF;
    nodes[1].optTarg2[3] = S_TV;
    nodes[1].optReq[3] = S_TV;
    
    /*_______CORRIDOR__________*/
    nodes[2].name = "Corridor";
    nodes[2].desc = "The glue that holds this house together";
    nodes[2].nOpts = 7;
    
    nodes[2].opts[0] = "Go to lounge";
    nodes[2].optAct[0] = A_MOVE;
    nodes[2].optTarg[0] = 1;
    
    nodes[2].opts[1] = "Go to kitchen";
    nodes[2].optAct[1] = A_MOVE;
    nodes[2].optTarg[1] = 3;
    
    nodes[2].opts[2] = "Go outside";
    nodes[2].optAct[2] = A_MOVE;
    nodes[2].optTarg[2] = 6;
    
    nodes[2].opts[3] = "Go to Darren's room";
    nodes[2].optAct[3] = A_MOVE;
    nodes[2].optTarg[3] = 5;
    nodes[2].optReq[3] = -S_FAP;
    
    nodes[2].opts[4] = "Go to Darren's room";
    nodes[2].optAct[4] = A_MOVE;
    nodes[2].optTarg[4] = 8;
    nodes[2].optReq[4] = S_FAP;
    
    nodes[2].opts[5] = "Go to Pete's room";
    nodes[2].optAct[5] = A_MOVE;
    nodes[2].optTarg[5] = 4;
    nodes[2].optReq[5] = -S_FIGHT;
    
    nodes[2].opts[6] = "Go to Pete's room";
    nodes[2].optAct[6] = A_MOVE;
    nodes[2].optTarg[6] = 9;
    nodes[2].optReq[6] = S_FIGHT;
    
    /*_______KITCHEN__________*/
    nodes[3].name = "Kitchen";
    nodes[3].desc = "Somethings burning in the oven";
    nodes[3].nOpts = 3;
    
    nodes[3].opts[0] = "Go to Corridor";
    nodes[3].optAct[0] = A_MOVE;
    nodes[3].optTarg[0] = 2;
    
    nodes[3].opts[1] = "Go outside";
    nodes[3].optAct[1] = A_MOVE;
    nodes[3].optTarg[1] = 6;
    
    nodes[3].opts[2] = "Open Fridge";
    nodes[3].optAct[2] = A_MOVE;
    nodes[3].optTarg[2] = 7;
    
    /*_______FRIDGE__________*/
    nodes[7].name = "Fridge";
    nodes[7].desc = "It's cold";
    nodes[7].nOpts = 3;
    
    nodes[7].opts[0] = "Close Fridge";
    nodes[7].optAct[0] = A_MOVE;
    nodes[7].optTarg[0] = 3;
    
    nodes[7].opts[1] = "Drink beers";
    nodes[7].optAct2[1] = A_TON;
    nodes[7].optTarg2[1] = S_DRUNK;
    nodes[7].optReq[1] = -S_DRUNK;
    
    nodes[7].opts[2] = "Eat that pizza from the other night";
    nodes[7].optAct2[2] = A_TON;
    nodes[7].optTarg2[2] = S_PEATEN;
    nodes[7].optReq[2] = -S_PEATEN;
    
    /*_______DARREN__________*/
    nodes[5].name = "Darren's Room";
    nodes[5].desc = "Nobody's here";
    nodes[5].nOpts = 2;
    
    nodes[5].opts[0] = "Leave Room";
    nodes[5].optAct[0] = A_MOVE;
    nodes[5].optTarg[0] = 2;
    
    nodes[5].opts[1] = "Fap";
    nodes[5].optAct[1] = A_MOVE;
    nodes[5].optTarg[1] = 8;
    nodes[5].optAct2[1] = A_TON;
    nodes[5].optTarg2[1] = S_FAP;
    nodes[5].optReq[1] = S_DRUNK;
    
    /*_______DARRENF__________*/
    nodes[8].name = "Darren's Room";
    nodes[8].desc = "There's Semen everywhere. You are a dirty dirty boy.";
    nodes[8].nOpts = 1;
    
    nodes[8].opts[0] = "Leave Room";
    nodes[8].optAct[0] = A_MOVE;
    nodes[8].optTarg[0] = 2;
    
    /*_______PETE__________*/
    nodes[4].name = "Pete's Room";
    nodes[4].desc = "Pete's playing computer games";
    nodes[4].nOpts = 3;
    
    nodes[4].opts[0] = "Leave Room";
    nodes[4].optAct[0] = A_MOVE;
    nodes[4].optTarg[0] = 2;
    
    nodes[4].opts[1] = "Steal his beers";
    nodes[4].optAct2[1] = A_TON;
    nodes[4].optTarg2[1] = S_BSTOLE;
    nodes[4].optReq[1] = -S_BSTOLE;
    
    nodes[4].opts[2] = "Fuck up his game";
    nodes[4].optAct[2] = A_MOVE;
    nodes[4].optTarg[2] = 9;
    nodes[4].optReq[2] = S_TV;
    
    /*_______PETEBATTLE__________*/
    nodes[9].name = "Pete's Room";
    nodes[9].desc = "Pete's gonna beat you up";
    nodes[9].nOpts = 3;
    
    nodes[9].opts[0] = "Piss yourself";
    nodes[9].optAct[0] = A_TON;
    nodes[9].optTarg[0] = S_FIGHT;
    nodes[9].optReq[0] = -S_FIGHT;
    
    nodes[9].opts[1] = "Run away";
    nodes[9].optAct[1] = A_MOVE;
    nodes[9].optTarg[1] = 2;
    nodes[9].optReq[1] = S_FIGHT;
    
    nodes[9].opts[2] = "Fight him";
    nodes[9].optAct[2] = A_MOVE;
    nodes[9].optTarg[2] = 10;
    nodes[9].optReq[2] = S_FIGHT;
    
    /*_______BATTLE__________*/
    nodes[10].name = "Epic battle";
    nodes[10].desc = "You are so fucked";
    nodes[10].nOpts = 3;
    
    nodes[10].opts[0] = "Punch him";
    nodes[10].optAct[0] = A_MOVE;
    nodes[10].optTarg[0] = 11;
    
    nodes[10].opts[1] = "Kick him";
    nodes[10].optAct[1] = A_MOVE;
    nodes[10].optTarg[1] = 11;
    
    nodes[10].opts[2] = "Bottle him";
    nodes[10].optAct[2] = A_MOVE;
    nodes[10].optTarg[2] = 12;
    nodes[10].optReq[2] = S_BSTOLE;
    
    /*_______DEATH__________*/
    nodes[11].name = "You are dead";
    nodes[11].desc = "Shame";
    nodes[11].nOpts = 1;
    
    nodes[11].opts[0] = "I am displeased with this outcome";
    nodes[11].optAct[0] = A_SUICIDE;
    nodes[11].optTarg[0] = 12;
    
    /*_______WIN__________*/
    nodes[12].name = "Pete's dead";
    nodes[12].desc = "Nice one Cam. Maybe you should go to your room and think about what you did";
    nodes[12].nOpts = 2;
    
    nodes[12].opts[0] = "Okay";
    nodes[12].optAct2[0] = A_TON;
    nodes[12].optTarg2[0] = S_SUICIDE;
    nodes[12].optReq[0] = -S_SUICIDE;
    
    nodes[12].opts[1] = "Go back to your room";
    nodes[12].optAct[1] = A_MOVE;
    nodes[12].optTarg[1] = 0;
    nodes[12].optReq[1] = S_SUICIDE;
    
    /*_______Outside__________*/
    nodes[6].name = "Outside";
    nodes[6].desc = "It's very cold";
    nodes[6].nOpts = 1;
    
    nodes[6].opts[0] = "Go back inside";
    nodes[6].optAct[0] = A_MOVE;
    nodes[6].optTarg[0] = 2;
    
    
    return;
}
