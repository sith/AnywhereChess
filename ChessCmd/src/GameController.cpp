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

Column convertToColumn(char aChar) {
    return static_cast<Column>(aChar - 'a');
}

Row convertToRow(char aChar) {
    return static_cast<Row>(aChar - '1');
}


std::istream &operator>>(std::istream &is, CmdMove &cmdMove) {

    std::string line;
    std::getline(is, line);

    char &startColumnCharacter = line.at(0);
    char &startRowCharacter = line.at(1);
    char &endColumnCharacter = line.at(2);
    char &endRowCharacter = line.at(3);

    if (invalidColumn(startColumnCharacter)
        || invalidColumn(endColumnCharacter)
        || invalidRow(startRowCharacter)
        || invalidRow(endRowCharacter)) {
        return is;
    }

    cmdMove.validFormat = true;
    cmdMove.move = Move{convertToColumn(startColumnCharacter),
                        convertToRow(startRowCharacter),
                        convertToColumn(endColumnCharacter),
                        convertToRow(endRowCharacter)};

    return is;
}

bool invalidRow(const char &startRowCharacter) {
    return startRowCharacter < '1' || startRowCharacter > '8';
}

bool invalidColumn(const char &startColumnCharacter) {
    return startColumnCharacter < 'a' || startColumnCharacter > 'h';
}
