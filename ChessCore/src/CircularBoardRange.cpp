//
// Created by Fedorov, Alex on 9/7/20.
//

#include "CircularBoardRange.h"

CircularBoardRange::CircularBoardRange(const Square &square) : centerSquare(square) {
    Square startSquare{square.column - 1, square.row - 1};
    Square endSquare{square.column + 1, square.row + 1};

    rectangleBoardRange = RectangleBoardRange{startSquare, endSquare};
}

bool CircularBoardRange::hasNext() {
    if (centerSquare == Square{H, _8} && currentSquare == Square{G, _8}) {
        return false;
    }
    return rectangleBoardRange.hasNext();
}

Square CircularBoardRange::next() {
    currentSquare = rectangleBoardRange.next();
    if (currentSquare == centerSquare) {
        return rectangleBoardRange.next();
    } else {
        return currentSquare;
    }
}
