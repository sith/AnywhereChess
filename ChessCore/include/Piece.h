//
// Created by Fedorov, Alex on 7/3/20.
//

#ifndef ANYWHERECHESS_PIECE_H
#define ANYWHERECHESS_PIECE_H


#include <ostream>
#include "PieceType.h"
#include "PieceColor.h"

struct Piece {
    const PieceColor pieceColor;
    const PieceType pieceType;

    Piece();

    Piece(PieceColor pieceColor, PieceType pieceType);

    bool operator==(const Piece &rhs) const;

    bool operator!=(const Piece &rhs) const;

    friend std::ostream &operator<<(std::ostream &os, const Piece &piece);

};


#endif //ANYWHERECHESS_PIECE_H
