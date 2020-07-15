//
// Created by Fedorov, Alex on 6/13/20.
//

#ifndef ANYWHERECHESS_BOARD_H
#define ANYWHERECHESS_BOARD_H

constexpr int boardSize = 8;
constexpr int arraySize = boardSize * boardSize;

#include <ostream>
#include "Position.h"


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

class Board {
    Piece **board = new Piece *[boardSize * boardSize];

    int toIndex(Column column, Row row) const;

    friend bool test(const Board &board);

public:

    [[nodiscard]] const Position get(Column column, Row row) const;

    Board();

    Board(const Board &board) = delete;

    Board(Board &&newBoard);

    ~Board();


};


#endif //ANYWHERECHESS_BOARD_H
