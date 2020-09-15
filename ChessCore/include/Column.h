//
// Created by Fedorov, Alex on 7/15/20.
//

#ifndef ANYWHERECHESS_COLUMN_H
#define ANYWHERECHESS_COLUMN_H

enum Column {
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
};


inline Column operator+(Column column, int value) {
    int result = (int) column + value;
    if (result > 7) {
        return H;
    }

    return (Column) result;
}

inline Column operator-(Column column, int value) {
    int result = (int) column - value;
    if (result < 0) {
        return A;
    }
    return (Column) result;
}

inline int operator-(Column lhs, Column rhs) {
    return (int) lhs - (int) rhs;
}

#endif //ANYWHERECHESS_COLUMN_H
