//
// Created by Fedorov, Alex on 8/30/20.
//

#ifndef ANYWHERECHESS_RECTANGLEBOARDRANGE_H
#define ANYWHERECHESS_RECTANGLEBOARDRANGE_H


#include "Board.h"
#include "Square.h"

class RectangleBoardRange {
    Column startColumn;
    Square currentSquare;
    Square endSquare;
    bool hasMoreSquares = true;
public:
    RectangleBoardRange(const Square &startSquare, const Square &endSquare);

    RectangleBoardRange();

public:
    bool hasNext();

    Square next();
};


#endif //ANYWHERECHESS_RECTANGLEBOARDRANGE_H
