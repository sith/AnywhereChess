//
// Created by Fedorov, Alex on 7/3/20.
//

#include <iosfwd>
#include <Piece.h>
#include <Board.h>
#include "TestUtils.h"

std::ostream &operator<<(std::ostream &os, const Piece &piece) {
//    os << "pieceColor: " << static_cast<int>(piece.pieceColor) << " pieceType: " << static_cast<int>(piece.pieceType);
    throw "not implemented";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
    throw "not implemented";
    return os;
}

