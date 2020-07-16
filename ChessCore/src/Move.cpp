//
// Created by Fedorov, Alex on 7/13/20.
//

#include "Move.h"
#include "Row.h"
#include "Column.h"

Move::Move(const Column startColumn, const Row startRow, const Column endColumn, const Row endRow) : startColumn(
        startColumn), startRow(startRow), endColumn(endColumn), endRow(endRow) {}
