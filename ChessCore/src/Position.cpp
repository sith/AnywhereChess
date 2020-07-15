#include "Position.h"

Position::Position(const Piece *piece) : piece(piece), hasPiece(piece != nullptr) {}

const Piece &Position::getPiece() const {
    return *piece;
}
