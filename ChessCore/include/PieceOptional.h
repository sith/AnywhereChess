#ifndef ANYWHERECHESS_PIECEOPTIONAL_H
#define ANYWHERECHESS_PIECEOPTIONAL_H

#include "Piece.h"
#include "Column.h"

struct PieceOptional {
    const Piece piece;
    const bool hasPiece;

    explicit PieceOptional(Piece piece);

    PieceOptional();

    bool operator==(const PieceOptional &rhs) const;

    bool operator!=(const PieceOptional &rhs) const;

};


#endif //ANYWHERECHESS_PIECEOPTIONAL_H
