//
// Created by Fedorov, Alex on 7/15/20.
//

#ifndef ANYWHERECHESS_ROW_H
#define ANYWHERECHESS_ROW_H

enum Row {
    _1,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
};

inline Row operator+(Row row, int value) {
    int result = (int) row + value;
    if (result > 7) {
        return _8;
    }

    return (Row) result;
}

inline Row operator-(Row row, int value) {
    int result = (int) row - value;
    if (result < 0) {
        return _1;
    }
    return (Row) result;
}

inline int operator-(Row lhs, Row rhs) {
    return (int) lhs - (int) rhs;
}


#endif //ANYWHERECHESS_ROW_H
