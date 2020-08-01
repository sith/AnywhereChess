#include <Position.h>
#include <Board.h>
#include <iostream>
#include "Row.h"
#include "Column.h"

Position Board::get(Column column, Row row) const {
    Piece *piece = board[toIndex(column, row)];
    if (piece != nullptr) {
        return Position(*piece);
    } else {
        return Position();
    }
}

void Board::set(Column column, Row row, Piece piece) {
    board[toIndex(column, row)] = new Piece{piece};
}

Board::Board() {
    for (int i = 0; i < arraySize; i++) {
        board[i] = nullptr;
    }
}

Board::~Board() {
    if (board == nullptr) {
        return;
    }
    for (int i = 0; i < arraySize; i++) {
        delete board[i];
    }
    delete[] board;
}

int Board::toIndex(Column column, Row row) {
    return row * boardSize + column;
}

TakenPiece Board::move(const Move &move) {
    TakenPiece takenPiece = get(move.endColumn, move.endRow);

    Piece *piece = board[toIndex(move.endColumn, move.endRow)];

    delete piece;
    board[toIndex(move.endColumn, move.endRow)] = board[toIndex(move.startColumn, move.startRow)];
    board[toIndex(move.startColumn, move.startRow)] = nullptr;

    return takenPiece;
}

Board::Board(Board &&newBoard) {
    board = newBoard.board;
    newBoard.board = nullptr;
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