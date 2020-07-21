#include <Board.h>
#include <ChessGame.h>
#include <PieceToCharMapper.h>
#include "Row.h"
#include "Column.h"
#include <GameController.h>
#include <iostream>

constexpr std::initializer_list<Column> columns = {A, B, C, D, E, F, G, H};
constexpr std::initializer_list<Row> rows = {_1, _2, _3, _4, _5, _6, _7, _8};


std::ostream &operator<<(std::ostream &os, const ChessGame<std::string> &chessGame) {
    const Board &board = chessGame.getBoard();
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
    const std::string &currentPlayer = chessGame.getCurrentPlayer();
    os << currentPlayer << '>';
    return os;
}

inline Column convertToColumn(char aChar) {
    return static_cast<Column>(aChar - 'A' + 1);
}

inline Row convertToRow(char aChar) {
    return static_cast<Row>(aChar - '1' + 1);
}

std::istream &operator>>(std::istream &is, CmdMove &cmdMove) {

    std::string line;
    std::getline(is, line);

    cmdMove.valid = true;
    cmdMove.move = Move{convertToColumn(line.at(0)),
                        convertToRow(line.at(1)),
                        convertToColumn(line.at(2)),
                        convertToRow(line.at(3))};

    return is;
}
