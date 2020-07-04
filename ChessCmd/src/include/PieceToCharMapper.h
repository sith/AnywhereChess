//
// Created by Fedorov, Alex on 7/3/20.
//

#ifndef ANYWHERECHESS_PIECETOCHARMAPPER_H
#define ANYWHERECHESS_PIECETOCHARMAPPER_H

#include <Piece.h>
#include <Position.h>

char mapPositionToChar(const Position &position);

char mapPieceToChar(const Piece &piece);

#endif //ANYWHERECHESS_PIECETOCHARMAPPER_H
