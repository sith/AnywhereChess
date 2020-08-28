//
// Created by Fedorov, Alex on 7/3/20.
//

#ifndef ANYWHERECHESS_PIECETOCHARMAPPER_H
#define ANYWHERECHESS_PIECETOCHARMAPPER_H

#include <Piece.h>
#include <Types.h>
#include <Optional.h>
#include <Column.h>
#include <Row.h>

char mapPositionToChar(const Position &pieceOptional);

char mapPieceToChar(const Piece &piece);

#endif //ANYWHERECHESS_PIECETOCHARMAPPER_H
