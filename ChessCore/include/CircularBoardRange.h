//
// Created by Fedorov, Alex on 9/7/20.
//

#ifndef ANYWHERECHESS_CIRCULARBOARDRANGE_H
#define ANYWHERECHESS_CIRCULARBOARDRANGE_H


#include <Square.h>
#include <RectangleBoardRange.h>

class CircularBoardRange {
    Square centerSquare;
    Square currentSquare;

    RectangleBoardRange rectangleBoardRange;
public:

    explicit CircularBoardRange(const Square &square);

    bool hasNext();

    Square next();
};


#endif //ANYWHERECHESS_CIRCULARBOARDRANGE_H
