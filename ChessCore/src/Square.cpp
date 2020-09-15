//
// Created by Fedorov, Alex on 8/30/20.
//
#include <Square.h>

Square::Square(Column column, Row row) : column(column), row(row) {}

Square::Square() : column{A}, row{_1} {}

bool Square::operator==(const Square &rhs) const {
    return column == rhs.column &&
           row == rhs.row;
}

bool Square::operator!=(const Square &rhs) const {
    return !(rhs == *this);
}

bool Square::operator<(const Square &rhs) const {
    if (column < rhs.column)
        return true;
    if (rhs.column < column)
        return false;
    return row < rhs.row;
}

bool Square::operator>(const Square &rhs) const {
    return rhs < *this;
}

bool Square::operator<=(const Square &rhs) const {
    return !(rhs < *this);
}

bool Square::operator>=(const Square &rhs) const {
    return !(*this < rhs);
}

