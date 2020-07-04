//
// Created by Fedorov, Alex on 6/13/20.
//

#ifndef ANYWHERECHESS_BOARD_H
#define ANYWHERECHESS_BOARD_H


static const int size = 8;

#include <ostream>
#include "Position.h"

class Board {
    Piece *board[size][size] = {{nullptr}};

    [[nodiscard]] int toRowIndex(char rowLabel) const;

    [[nodiscard]] int toColumnIndex(char columnLabel) const;

public:
    [[nodiscard]] const Position get(char column, char row) const;

    Board();

    Board(const Board &board) = delete;

    ~Board();
};


#endif //ANYWHERECHESS_BOARD_H
