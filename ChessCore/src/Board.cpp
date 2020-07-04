#include <Position.h>
#include <Board.h>

const Position Board::get(char column, char row) const {
    Piece *piece = board[toColumnIndex(column)][toRowIndex(row)];
    return Position(piece);
}

Board::Board() {
    board[toColumnIndex('a')][toRowIndex('1')] = new Piece(PieceColor::WHITE, PieceType::ROOK);
    board[toColumnIndex('b')][toRowIndex('1')] = new Piece(PieceColor::WHITE, PieceType::KNIGHT);
    board[toColumnIndex('c')][toRowIndex('1')] = new Piece(PieceColor::WHITE, PieceType::BISHOP);
    board[toColumnIndex('d')][toRowIndex('1')] = new Piece(PieceColor::WHITE, PieceType::QUEEN);
    board[toColumnIndex('e')][toRowIndex('1')] = new Piece(PieceColor::WHITE, PieceType::KING);
    board[toColumnIndex('f')][toRowIndex('1')] = new Piece(PieceColor::WHITE, PieceType::BISHOP);
    board[toColumnIndex('g')][toRowIndex('1')] = new Piece(PieceColor::WHITE, PieceType::KNIGHT);
    board[toColumnIndex('h')][toRowIndex('1')] = new Piece(PieceColor::WHITE, PieceType::ROOK);

    board[toColumnIndex('a')][toRowIndex('2')] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toColumnIndex('b')][toRowIndex('2')] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toColumnIndex('c')][toRowIndex('2')] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toColumnIndex('d')][toRowIndex('2')] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toColumnIndex('e')][toRowIndex('2')] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toColumnIndex('f')][toRowIndex('2')] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toColumnIndex('g')][toRowIndex('2')] = new Piece(PieceColor::WHITE, PieceType::POND);
    board[toColumnIndex('h')][toRowIndex('2')] = new Piece(PieceColor::WHITE, PieceType::POND);

    board[toColumnIndex('a')][toRowIndex('8')] = new Piece(PieceColor::BLACK, PieceType::ROOK);
    board[toColumnIndex('b')][toRowIndex('8')] = new Piece(PieceColor::BLACK, PieceType::KNIGHT);
    board[toColumnIndex('c')][toRowIndex('8')] = new Piece(PieceColor::BLACK, PieceType::BISHOP);
    board[toColumnIndex('d')][toRowIndex('8')] = new Piece(PieceColor::BLACK, PieceType::QUEEN);
    board[toColumnIndex('e')][toRowIndex('8')] = new Piece(PieceColor::BLACK, PieceType::KING);
    board[toColumnIndex('f')][toRowIndex('8')] = new Piece(PieceColor::BLACK, PieceType::BISHOP);
    board[toColumnIndex('g')][toRowIndex('8')] = new Piece(PieceColor::BLACK, PieceType::KNIGHT);
    board[toColumnIndex('h')][toRowIndex('8')] = new Piece(PieceColor::BLACK, PieceType::ROOK);

    board[toColumnIndex('a')][toRowIndex('7')] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toColumnIndex('b')][toRowIndex('7')] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toColumnIndex('c')][toRowIndex('7')] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toColumnIndex('d')][toRowIndex('7')] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toColumnIndex('e')][toRowIndex('7')] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toColumnIndex('f')][toRowIndex('7')] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toColumnIndex('g')][toRowIndex('7')] = new Piece(PieceColor::BLACK, PieceType::POND);
    board[toColumnIndex('h')][toRowIndex('7')] = new Piece(PieceColor::BLACK, PieceType::POND);
}

int Board::toRowIndex(char rowLabel) const {
    return rowLabel - '1';
}

int Board::toColumnIndex(char columnLabel) const {
    return columnLabel - 'a';
}

Board::~Board() {
    for (const auto &row : board) {
        for (const auto &piece : row) {
            delete piece;
        }
    }
}
