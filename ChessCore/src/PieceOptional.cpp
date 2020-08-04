#include "PieceOptional.h"

PieceOptional::PieceOptional() : hasPiece{false} {}

PieceOptional::PieceOptional(Piece piece) : piece{piece}, hasPiece{true} {}
