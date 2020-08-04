#include <ChessCoreIO.h>
#include <boost/format.hpp>
#include <PieceToCharMapper.h>

std::ostream &operator<<(std::ostream &os, const Piece &piece) {
    os << boost::format("Piece:%1%:%2%") % piece.pieceColor % piece.pieceType;
    return os;
}


constexpr std::initializer_list<Column> columns = {A, B, C, D, E, F, G, H};
constexpr std::initializer_list<Row> rows = {_1, _2, _3, _4, _5, _6, _7, _8};

std::ostream &operator<<(std::ostream &os, const Board &board) {
    os << " abcdefgh \n";
    for (auto row = std::rbegin(rows); row != std::rend(rows); ++row) {
        char rowNumber = (char) (*row + '1');
        os << rowNumber;
        for (auto column = std::begin(columns); column != std::end(columns); ++column) {
            const Position &position = board.get(*column, *row);
            os << mapPositionToChar(position);
        }
        os << rowNumber << '\n';
    }
    os << " abcdefgh \n";
    return os;
}

std::ostream &operator<<(std::ostream &os, const ChessGame<std::string> &chessGame) {
    const Board &board = chessGame.getBoard();
    os << board;
    os << chessGame.getCurrentPlayer() << '>';
    return os;
}

std::ostream &operator<<(std::ostream &os, const MoveResult &moveResult) {
    os << "Move has status: " << moveResult.status;
    return os;
}

std::ostream &operator<<(std::ostream &os, const MoveStatus &moveStatus) {
    switch (moveStatus) {
        case MoveStatus::OK:
            os << "OK";
            break;
        case MoveStatus::ILLEGAL:
            os << "ILLEGAL";
            break;
        default:
            os << "Not supported enum. Please debug to see value";
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Column &column) {
    switch (column) {
        case A:
            os << 'a';
            break;
        case B:
            os << 'b';
            break;
        case C:
            os << 'c';
            break;
        case D:
            os << 'd';
            break;
        case E:
            os << 'e';
            break;
        case F:
            os << 'f';
            break;
        case G:
            os << 'g';
            break;
        case H:
            os << 'h';
            break;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const Row &row) {
    switch (row) {
        case _1:
            os << '1';
            break;
        case _2:
            os << '2';
            break;
        case _3:
            os << '3';
            break;
        case _4:
            os << '4';
            break;
        case _5:
            os << '5';
            break;
        case _6:
            os << '6';
            break;
        case _7:
            os << '7';
            break;
        case _8:
            os << '8';
            break;
    }


    return os;
}

std::ostream &operator<<(std::ostream &os, const Move &move) {
    os << boost::format("%1%%2%-%3%%4%") % move.startColumn % move.startRow % move.endColumn % move.endRow;
    return os;
}

std::ostream &operator<<(std::ostream &os, const PieceType &pieceType) {
    switch (pieceType) {
        case PieceType::POND:
            os << "pond";
            break;
        case PieceType::ROOK:
            os << "rook";
            break;
        case PieceType::KNIGHT:
            os << "knight";
            break;
        case PieceType::BISHOP:
            os << "bishop";
            break;
        case PieceType::QUEEN:
            os << "queen";
            break;
        case PieceType::KING:
            os << "king";
            break;
    }
    return os;
}

std::ostream &operator<<(std::ostream &os, const PieceColor &pieceColor) {
    switch (pieceColor) {
        case PieceColor::WHITE:
            os << "white";
            break;
        case PieceColor::BLACK:
            os << "black";
            break;
    }
    return os;
}
