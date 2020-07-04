#include <Board.h>
#include <PieceToCharMapper.h>
#include "ChessCmd.h"

ChessCmd::ChessCmd(std::istream &istream, std::ostream &ostream) : istream(istream), ostream(ostream) {}

void ChessCmd::run() {
    ChessGame chessGame{};
    ostream << chessGame;
}

std::ostream &operator<<(std::ostream &os, const ChessGame &chessGame) {

    const Board &board = chessGame.getBoard();
    os << " abcdefgh \n";

    for (char row = '8'; row >= '1'; row--) {
        os << row;
        for (char column = 'a'; column <= 'h'; column++) {
            const Position &position = board.get(column, row);
            os << mapPositionToChar(position);
        }
        os << row << '\n';
    }
    os << " abcdefgh \n";
    return os;
}

