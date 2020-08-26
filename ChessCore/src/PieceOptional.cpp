#include "PieceOptional.h"

PieceOptional::PieceOptional() : hasPiece{false}, piece{WHITE, POND} {}

PieceOptional::PieceOptional(Piece piece) : hasPiece{true}, piece{piece} {}

bool PieceOptional::operator==(const PieceOptional &rhs) const {
    return hasPiece == rhs.hasPiece && piece == rhs.piece;
}

bool PieceOptional::operator!=(const PieceOptional &rhs) const {
    return !(rhs == *this);
}