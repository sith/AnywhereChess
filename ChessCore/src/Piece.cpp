//
// Created by Fedorov, Alex on 7/3/20.
//

#include "Piece.h"

Piece::Piece(PieceColor pieceColor, PieceType pieceType) : pieceType(pieceType), pieceColor(pieceColor) {}

bool Piece::operator==(const Piece &rhs) const {
    return pieceColor == rhs.pieceColor &&
           pieceType == rhs.pieceType;
}

bool Piece::operator!=(const Piece &rhs) const {
    return !(rhs == *this);
}

Piece::Piece() : pieceColor{PieceColor::WHITE}, pieceType{PieceType::POND} {}
