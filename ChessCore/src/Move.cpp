//
// Created by Fedorov, Alex on 7/13/20.
//

#include "Move.h"
#include "Row.h"
#include "Column.h"

Move::Move(const Column startColumn, const Row startRow, const Column endColumn, const Row endRow) : startColumn(
        startColumn), startRow(startRow), endColumn(endColumn), endRow(endRow) {}

Move::Move() {}

bool Move::operator==(const Move &rhs) const {
    return startColumn == rhs.startColumn &&
           startRow == rhs.startRow &&
           endColumn == rhs.endColumn &&
           endRow == rhs.endRow;
}

bool Move::operator!=(const Move &rhs) const {
    return !(rhs == *this);
}

bool Move::isVerticalMove() const {
    return startColumn == endColumn;
}

bool Move::isHorizontal() const {
    return startRow == endRow;
}

bool Move::isNoMove() const {
    return startColumn == endColumn && startRow == endRow;
}

bool Move::operator<(const Move &rhs) const {
    if (startColumn < rhs.startColumn)
        return true;
    if (rhs.startColumn < startColumn)
        return false;
    if (startRow < rhs.startRow)
        return true;
    if (rhs.startRow < startRow)
        return false;
    if (endColumn < rhs.endColumn)
        return true;
    if (rhs.endColumn < endColumn)
        return false;
    return endRow < rhs.endRow;
}

bool Move::isDiagonal() const {
    int rowDiff = startRow - endRow;
    if (rowDiff < 0) {
        rowDiff *= -1;
    }
    int columnDiff = startColumn - endColumn;
    if (columnDiff < 0) {
        columnDiff *= -1;
    }

    return rowDiff == columnDiff;
}

