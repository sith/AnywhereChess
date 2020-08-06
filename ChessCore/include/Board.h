#ifndef ANYWHERECHESS_BOARD_H
#define ANYWHERECHESS_BOARD_H

constexpr int boardSize = 8;
constexpr int arraySize = boardSize * boardSize;

#include <ostream>
#include "PieceOptional.h"
#include "Move.h"
#include "Row.h"
#include "Column.h"

typedef PieceOptional TakenPiece;
typedef PieceOptional Position;

class Board {
    Piece **array = new Piece *[boardSize * boardSize]{nullptr};

    [[nodiscard]] static int toIndex(Column column, Row row);

    friend bool test(const Board &board);

    inline void clearArray() const;

public:

    [[nodiscard]] Position get(Column column, Row row) const;

    void set(Column column, Row row, Piece);

    Board();

    Board(const Board &board);

    Board &operator=(const Board &other);

    Board(Board &&newBoard) noexcept;

    Board &operator=(Board &&other) = delete;

    ~Board();

    TakenPiece move(const Move &move);

    [[nodiscard]] bool hasPieceAt(Column column, Row row) const;

};

Board createStandardBoard();

#endif //ANYWHERECHESS_BOARD_H
