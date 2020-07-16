#ifndef ANYWHERECHESS_BOARD_H
#define ANYWHERECHESS_BOARD_H

constexpr int boardSize = 8;
constexpr int arraySize = boardSize * boardSize;

#include <ostream>
#include "Position.h"
#include "Move.h"
#include "Row.h"
#include "Column.h"


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

    void move(const Move &move);
};


#endif //ANYWHERECHESS_BOARD_H
