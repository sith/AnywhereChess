#ifndef ANYWHERECHESS_PIECEOPTIONAL_H
#define ANYWHERECHESS_PIECEOPTIONAL_H

#include "Piece.h"

struct PieceOptional {
    const Piece piece;
    const bool hasPiece;

    explicit PieceOptional(Piece piece);

    PieceOptional();
};


#endif //ANYWHERECHESS_PIECEOPTIONAL_H
