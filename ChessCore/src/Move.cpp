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
