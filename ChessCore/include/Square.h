//
// Created by Fedorov, Alex on 8/22/20.
//

#ifndef ANYWHERECHESS_SQUARE_H
#define ANYWHERECHESS_SQUARE_H

#include <Column.h>
#include <Row.h>

struct Square {
    const Column column;
    const Row row;

    Square(const Column column, const Row row) : column(column), row(row) {}

    Square() : column{A}, row{_1} {}
};

#endif //ANYWHERECHESS_SQUARE_H
