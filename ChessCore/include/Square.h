//
// Created by Fedorov, Alex on 8/22/20.
//

#ifndef ANYWHERECHESS_SQUARE_H
#define ANYWHERECHESS_SQUARE_H

#include <Column.h>
#include <Row.h>

struct Square {
    Column column;
    Row row;

    Square(Column column, Row row);

    Square();

    bool operator==(const Square &rhs) const;

    bool operator!=(const Square &rhs) const;

    bool operator<(const Square &rhs) const;

    bool operator>(const Square &rhs) const;

    bool operator<=(const Square &rhs) const;

    bool operator>=(const Square &rhs) const;


};

#endif //ANYWHERECHESS_SQUARE_H
