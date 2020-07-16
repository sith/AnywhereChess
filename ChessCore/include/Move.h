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

    Move(const Column startColumn, const Row startRow, const Column endColumn, const Row endRow);
};


#endif //ANYWHERECHESS_MOVE_H
