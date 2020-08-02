#ifndef ANYWHERECHESS_BOARD_H
#define ANYWHERECHESS_BOARD_H

constexpr int boardSize = 8;
constexpr int arraySize = boardSize * boardSize;

#include <ostream>
#include "Position.h"
#include "Move.h"
#include "Row.h"
#include "Column.h"

typedef Position TakenPiece;

class Board {
    Piece **board = new Piece *[boardSize * boardSize];

    [[nodiscard]] static int toIndex(Column column, Row row);

    friend bool test(const Board &board);

public:

    [[nodiscard]] Position get(Column column, Row row) const;

    void set(Column column, Row row, Piece);

    Board();

    Board(const Board &board) = delete;

    Board &operator=(Board &other) = delete;

    Board &operator=(Board &&other) = delete;

    Board(Board &&newBoard);

    ~Board();

    TakenPiece move(const Move &move);

    [[nodiscard]] bool hasPieceAt(Column column, Row row) const;
};

Board createStandardBoard();

#endif //ANYWHERECHESS_BOARD_H
