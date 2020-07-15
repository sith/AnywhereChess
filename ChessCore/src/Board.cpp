#include <Position.h>
#include <Board.h>

const Position Board::get(Column column, Row row) const {
    Piece *piece = board[toIndex(column, row)];
    return Position(piece);
}

Board::Board() {

    for (int i = 0; i < arraySize; i++) {
        board[i] = nullptr;
    }

    board[toIndex(Column::A, Row::_1)] = new Piece(PieceColor::WHITE, PieceType::ROOK);
    board[toIndex(Column::B, Row::_1)] = new Piece(PieceColor::WHITE, PieceType::KNIGHT);
    board[toIndex(Column::C, Row::_1)] = new Piece(PieceColor::WHITE, PieceType::BISHOP);
    board[toIndex(Column::D, Row::_1)] = new Piece(PieceColor::WHITE, PieceType::QUEEN);
    board[toIndex(Column::E, Row::_1)] = new Piece(PieceColor::WHITE, PieceType::KING);
    board[toIndex(Column::F, Row::_1)] = new Piece(PieceColor::WHITE, PieceType::BISHOP);
    board[toIndex(Column::G, Row::_1)] = new Piece(PieceColor::WHITE, PieceType::KNIGHT);
    board[toIndex(Column::H, Row::_1)] = new Piece(PieceColor::WHITE, PieceType::ROOK);

    board[toIndex(Column::A, Row::_2)] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toIndex(Column::B, Row::_2)] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toIndex(Column::C, Row::_2)] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toIndex(Column::D, Row::_2)] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toIndex(Column::E, Row::_2)] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toIndex(Column::F, Row::_2)] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toIndex(Column::G, Row::_2)] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toIndex(Column::H, Row::_2)] = new Piece(PieceColor::WHITE, PieceType::POND);

    board[toIndex(Column::A, Row::_7)] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toIndex(Column::B, Row::_7)] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toIndex(Column::C, Row::_7)] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toIndex(Column::D, Row::_7)] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toIndex(Column::E, Row::_7)] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toIndex(Column::F, Row::_7)] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toIndex(Column::G, Row::_7)] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toIndex(Column::H, Row::_7)] = new Piece(PieceColor::BLACK, PieceType::POND);

    board[toIndex(Column::A, Row::_8)] = new Piece(PieceColor::BLACK, PieceType::ROOK);
    board[toIndex(Column::B, Row::_8)] = new Piece(PieceColor::BLACK, PieceType::KNIGHT);
    board[toIndex(Column::C, Row::_8)] = new Piece(PieceColor::BLACK, PieceType::BISHOP);
    board[toIndex(Column::D, Row::_8)] = new Piece(PieceColor::BLACK, PieceType::QUEEN);
    board[toIndex(Column::E, Row::_8)] = new Piece(PieceColor::BLACK, PieceType::KING);
    board[toIndex(Column::F, Row::_8)] = new Piece(PieceColor::BLACK, PieceType::BISHOP);
    board[toIndex(Column::G, Row::_8)] = new Piece(PieceColor::BLACK, PieceType::KNIGHT);
    board[toIndex(Column::H, Row::_8)] = new Piece(PieceColor::BLACK, PieceType::ROOK);
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

Board::Board(Board &&newBoard) {
    Piece **tmp = newBoard.board;
    newBoard.board = nullptr;
    board = tmp;
}

int Board::toIndex(Column column, Row row) const {
    return row * boardSize + column;
}
