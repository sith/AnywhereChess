#ifndef ANYWHERECHESS_CMDMOVE_H
#define ANYWHERECHESS_CMDMOVE_H


#include <Move.h>
#include <ostream>

struct CmdMove {
    Move move;
    bool valid{false};
};
#endif //ANYWHERECHESS_CMDMOVE_H
