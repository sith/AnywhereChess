//
// Created by Fedorov, Alex on 7/2/20.
//

#include "Position.h"

Position::Position(const Piece *piece) : piece(piece), hasPiece(piece != nullptr) {}

const Piece &Position::getPiece() const {
    return *piece;
}
