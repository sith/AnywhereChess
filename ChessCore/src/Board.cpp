#include <PieceOptional.h>
#include <Board.h>
#include <iostream>
#include "Row.h"
#include "Column.h"

PieceOptional Board::get(Column column, Row row) const {
    Piece *piece = array[toIndex(column, row)];
    if (piece != nullptr) {
        return PieceOptional(*piece);
    } else {
        return PieceOptional();
    }
}

void Board::set(Column column, Row row, Piece piece) {
    array[toIndex(column, row)] = new Piece{piece};
}

Board::Board() {
}

void Board::clearArray() const {
    for (int i = 0; i < arraySize; i++) {
        if (array[i] != nullptr) {
            delete array[i];
            array[i] = nullptr;
        }
    }
}

Board::~Board() {
    if (array == nullptr) {
        return;
    }
    clearArray();
    delete[] array;
}

int Board::toIndex(Column column, Row row) {
    return row * boardSize + column;
}

TakenPiece Board::move(const Move &move) {
    PieceOptional takenPiece = get(move.endColumn, move.endRow);

    Piece *piece = array[toIndex(move.endColumn, move.endRow)];

    delete piece;
    array[toIndex(move.endColumn, move.endRow)] = array[toIndex(move.startColumn, move.startRow)];
    array[toIndex(move.startColumn, move.startRow)] = nullptr;

    return takenPiece;
}

Board::Board(Board &&newBoard) noexcept {
    array = newBoard.array;
    newBoard.array = nullptr;
}

bool Board::hasPieceAt(Column column, Row row) const {
    return array[toIndex(column, row)] != nullptr;
}

Board::Board(const Board &board) {
    *this = board;
}

Board &Board::operator=(const Board &other) {
    if (this == &other) {
        return *this;
    }

    if (other.array == nullptr) {
        return *this;
    }

    clearArray();

    for (int i = 0; i < arraySize; i++) {
        if (other.array[i] != nullptr) {
            this->array[i] = new Piece{*other.array[i]};
        }
    }
    return *this;
}

void Board::remove(Column column, Row row) {
    delete array[toIndex(column, row)];
    array[toIndex(column, row)] = nullptr;
}

Board createStandardBoard() {
    Board board{};

    board.set(Column::A, Row::_1, Piece{PieceColor::WHITE, PieceType::ROOK});
    board.set(Column::B, Row::_1, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(Column::C, Row::_1, Piece{PieceColor::WHITE, PieceType::BISHOP});
    board.set(Column::D, Row::_1, Piece{PieceColor::WHITE, PieceType::QUEEN});
    board.set(Column::E, Row::_1, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(Column::F, Row::_1, Piece{PieceColor::WHITE, PieceType::BISHOP});
    board.set(Column::G, Row::_1, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(Column::H, Row::_1, Piece{PieceColor::WHITE, PieceType::ROOK});

    board.set(Column::A, Row::_2, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(Column::B, Row::_2, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(Column::C, Row::_2, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(Column::D, Row::_2, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(Column::E, Row::_2, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(Column::F, Row::_2, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(Column::G, Row::_2, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(Column::H, Row::_2, Piece{PieceColor::WHITE, PieceType::POND});

    board.set(Column::A, Row::_7, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(Column::B, Row::_7, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(Column::C, Row::_7, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(Column::D, Row::_7, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(Column::E, Row::_7, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(Column::F, Row::_7, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(Column::G, Row::_7, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(Column::H, Row::_7, Piece{PieceColor::BLACK, PieceType::POND});

    board.set(Column::A, Row::_8, Piece{PieceColor::BLACK, PieceType::ROOK});
    board.set(Column::B, Row::_8, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(Column::C, Row::_8, Piece{PieceColor::BLACK, PieceType::BISHOP});
    board.set(Column::D, Row::_8, Piece{PieceColor::BLACK, PieceType::QUEEN});
    board.set(Column::E, Row::_8, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(Column::F, Row::_8, Piece{PieceColor::BLACK, PieceType::BISHOP});
    board.set(Column::G, Row::_8, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(Column::H, Row::_8, Piece{PieceColor::BLACK, PieceType::ROOK});
    return board;
}