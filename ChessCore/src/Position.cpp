#include "Position.h"

Position::Position() : hasPiece{false} {}

Position::Position(Piece piece) : piece{piece}, hasPiece{true} {}
