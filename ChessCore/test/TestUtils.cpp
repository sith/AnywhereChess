//
// Created by Fedorov, Alex on 7/3/20.
//

#include <iosfwd>
#include <Piece.h>
#include <Board.h>
#include "TestUtils.h"
#include <boost/format.hpp>

std::ostream &operator<<(std::ostream &os, const Piece &piece) {
//    os << "pieceColor: " << static_cast<int>(piece.pieceColor) << " pieceType: " << static_cast<int>(piece.pieceType);
    throw "not implemented";
    return os;
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
    throw "not implemented";
    return os;
}

std::ostream &operator<<(std::ostream &os, const MoveResult &moveResult) {
    os << moveResult.status;
    return os;
}

std::ostream &operator<<(std::ostream &os, const MoveStatus &moveStatus) {
    switch (moveStatus) {
        case MoveStatus::OK:
            os << "OK";
            break;
        case MoveStatus::ILLEGAL:
            os << "ILLEGAL";
            break;
        default:
            os << "Not supported enum. Please debug to see value";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Column &column) {
    switch (column) {
        case A:
            os << 'a';
            break;
        case B:
            os << 'b';
            break;
        case C:
            os << 'c';
            break;
        case D:
            os << 'd';
            break;
        case E:
            os << 'e';
            break;
        case F:
            os << 'f';
            break;
        case G:
            os << 'g';
            break;
        case H:
            os << 'h';
            break;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Row &row) {
    switch (row) {
        case _1:
            os << '1';
            break;
        case _2:
            os << '2';
            break;
        case _3:
            os << '3';
            break;
        case _4:
            os << '4';
            break;
        case _5:
            os << '5';
            break;
        case _6:
            os << '6';
            break;
        case _7:
            os << '7';
            break;
        case _8:
            os << '8';
            break;
    }


    return os;
}

std::ostream &operator<<(std::ostream &os, const Move &move) {
    os << boost::format("%1%%2%-%3%%4%") % move.startColumn % move.startRow % move.endColumn % move.endRow;
    return os;
}
