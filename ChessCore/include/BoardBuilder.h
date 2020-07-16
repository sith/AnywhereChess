//
// Created by Fedorov, Alex on 7/13/20.
//

#ifndef ANYWHERECHESS_BOARDBUILDER_H
#define ANYWHERECHESS_BOARDBUILDER_H


#include "Piece.h"
#include "Board.h"
#include "Row.h"
#include "Column.h"

class BoardBuilder {



public:
    BoardBuilder &withPiece(Piece piece, Column column, Row row);

};


#endif //ANYWHERECHESS_BOARDBUILDER_H
