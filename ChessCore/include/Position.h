//
// Created by Fedorov, Alex on 7/2/20.
//

#ifndef ANYWHERECHESS_POSITION_H
#define ANYWHERECHESS_POSITION_H


#include "Piece.h"

class Position {
   const Piece *piece;
public:
    const bool hasPiece;

    explicit Position(const Piece *piece);

    [[nodiscard]] const Piece &getPiece() const;

};


#endif //ANYWHERECHESS_POSITION_H
