//
// Created by Fedorov, Alex on 7/13/20.
//

#ifndef ANYWHERECHESS_MOVE_H
#define ANYWHERECHESS_MOVE_H

#include "Row.h"
#include "Column.h"

struct Move {
    Column startColumn;
    Row startRow;
    Column endColumn;
    Row endRow;

    Move();

    Move(const Column startColumn, const Row startRow, const Column endColumn, const Row endRow);

    bool operator==(const Move &rhs) const;

    bool operator!=(const Move &rhs) const;

    bool operator<(const Move &rhs) const;

    bool isVerticalMove() const;

    bool isNoMove() const;

    bool isHorizontal() const;

    bool isDiagonal() const;
};


#endif //ANYWHERECHESS_MOVE_H
