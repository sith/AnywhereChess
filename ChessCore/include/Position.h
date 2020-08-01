#ifndef ANYWHERECHESS_POSITION_H
#define ANYWHERECHESS_POSITION_H

#include "Piece.h"

struct Position {
    const Piece piece;
    const bool hasPiece;

    Position(const Piece piece);

    Position();
};


#endif //ANYWHERECHESS_POSITION_H
