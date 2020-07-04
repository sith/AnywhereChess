//
// Created by Fedorov, Alex on 7/3/20.
//

#include <iosfwd>
#include <Piece.h>
#include <Board.h>
#include "TestUtils.h"
std::ostream &operator<<(std::ostream &os, const Piece &piece) {
//    os << "pieceColor: " << piece.pieceColor << " pieceType: " << piece.pieceType;
    return os;
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
//    os << "pieceColor: " << piece.pieceColor << " pieceType: " << piece.pieceType;
    return os;
}

