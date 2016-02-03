//  Node.h

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <string>
const unsigned int M_OPT = 7;
const int A_NULL = 0;
const int A_MOVE = 1;
const int A_SUICIDE = 2;
const int A_TON = 3;
const int A_TOFF = 4;

class Node
{
private:
    int index;
public:
    std::string name;
    std::string desc;
    int nOpts;
    std::string opts[M_OPT];
    int optAct[M_OPT];
    int optTarg[M_OPT];
    int optAct2[M_OPT];
    int optTarg2[M_OPT];
    int optReq[M_OPT];
    
public:
    Node(void);
    void play(int, int*, int*);
};


#endif // NODE_H_INCLUDED
