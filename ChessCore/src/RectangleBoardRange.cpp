//
// Created by Fedorov, Alex on 9/1/20.
//

#include <RectangleBoardRange.h>
#include <utils.h>

bool RectangleBoardRange::hasNext() {
    return hasMoreSquares;
}

Square RectangleBoardRange::next() {
    Square returnValue = currentSquare;

    if (currentSquare.column == endSquare.column) {
        currentSquare.column = startColumn;
        if (currentSquare.row == endSquare.row) {
            hasMoreSquares = false;
        } else {
            currentSquare.row = currentSquare.row + 1;
        }
    } else {
        currentSquare.column = currentSquare.column + 1;
    }

    return returnValue;
}


RectangleBoardRange::RectangleBoardRange() : RectangleBoardRange{{A, _1},
                                                                 {H, _8}} {
}

RectangleBoardRange::RectangleBoardRange(const Square &startSquare, const Square &endSquare) :
        currentSquare{utils::min(startSquare, endSquare)},
        endSquare{utils::max(startSquare, endSquare)} {
    startColumn = currentSquare.column;
}

