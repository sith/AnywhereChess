
#ifndef ANYWHERECHESS_CMDPIECETYPE_H
#define ANYWHERECHESS_CMDPIECETYPE_H

#include <PieceType.h>

struct CmdPieceType {
    PieceType pieceType{POND};
    bool validFormat{false};
};

#endif //ANYWHERECHESS_CMDPIECETYPE_H
