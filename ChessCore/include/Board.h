#ifndef ANYWHERECHESS_BOARD_H
#define ANYWHERECHESS_BOARD_H

constexpr int boardSize = 8;
constexpr int arraySize = boardSize * boardSize;

#include <ostream>
#include "Optional.h"
#include "Move.h"
#include "Row.h"
#include "Column.h"
#include "Square.h"
#include <Types.h>

class Board {
    Piece **array = new Piece *[arraySize]{nullptr};

    [[nodiscard]] static int toIndex(Column column, Row row);

    friend bool test(const Board &board);

    inline void clearArray() const;

public:

    [[nodiscard]] Position get(Column column, Row row) const;

    [[nodiscard]] Position get(Square square) const;

    void set(Column column, Row row, Piece piece);

    void set(Square square, Piece piece);

    void remove(Column column, Row row);

    void remove(Square square);

    Board();

    Board(const Board &board);

    Board &operator=(const Board &other);

    Board(Board &&newBoard) noexcept;

    Board &operator=(Board &&other) = delete;

    ~Board();

    TakenPiece move(const Move &move);

    [[nodiscard]] bool hasPieceAt(Column column, Row row) const;

    bool operator==(const Board &rhs) const;

    bool operator!=(const Board &rhs) const;

};

Board createStandardBoard();

#endif //ANYWHERECHESS_BOARD_H
