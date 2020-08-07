//
// Created by Fedorov, Alex on 7/3/20.
//

#ifndef ANYWHERECHESS_PIECETOCHARMAPPER_H
#define ANYWHERECHESS_PIECETOCHARMAPPER_H

#include <Piece.h>
#include <PieceOptional.h>
#include <Column.h>
#include <Row.h>

char mapPositionToChar(const PieceOptional &position);

char mapPieceToChar(const Piece &piece);

#endif //ANYWHERECHESS_PIECETOCHARMAPPER_H