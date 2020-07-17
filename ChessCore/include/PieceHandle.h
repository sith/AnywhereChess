//
// Created by Fedorov, Alex on 7/16/20.
//

#ifndef ANYWHERECHESS_PIECEHANDLE_H
#define ANYWHERECHESS_PIECEHANDLE_H

#include "Piece.h"

struct PieceHandle {
    Piece *value;

    Piece getValue() const {
        return *value;
    }

    PieceHandle() {}

    PieceHandle(Piece *value);

    PieceHandle(PieceHandle &pieceHandle) = delete;

    ~PieceHandle();

    bool operator==(const PieceHandle &rhs) const;

    bool operator!=(const PieceHandle &rhs) const;

};

#endif //ANYWHERECHESS_PIECEHANDLE_H
