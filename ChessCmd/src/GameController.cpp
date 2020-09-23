#include "Row.h"
#include <GameController.h>
#include <iostream>
#include <ChessCoreIO.h>


inline void setPiece(CmdPieceType &cmdPieceType, PieceType type);

std::istream &operator>>(std::istream &is, CmdMove &cmdMove) {

    std::string line;
    std::getline(is, line);

    if (line == giveUpString) {
        cmdMove.giveUp = true;
        cmdMove.validFormat = true;
        return is;
    }

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

std::istream &operator>>(std::istream &is, CmdPieceType &cmdPieceType) {
    std::string line;
    std::getline(is, line);
    if (line == "pond") {
        setPiece(cmdPieceType, POND);
    } else if (line == "rook") {
        setPiece(cmdPieceType, ROOK);
    } else if (line == "bishop") {
        setPiece(cmdPieceType, BISHOP);
    } else if (line == "knight") {
        setPiece(cmdPieceType, KNIGHT);
    } else if (line == "queen") {
        setPiece(cmdPieceType, QUEEN);
    } else if (line == "king") {
        setPiece(cmdPieceType, KING);
    } else {
        cmdPieceType.validFormat = false;
    }
    return is;
}

void setPiece(CmdPieceType &cmdPieceType, PieceType type) {
    cmdPieceType.pieceType = type;
    cmdPieceType.validFormat = true;
}

bool invalidRow(const char &startRowCharacter) {
    return startRowCharacter < '1' || startRowCharacter > '8';
}

bool invalidColumn(const char &startColumnCharacter) {
    return startColumnCharacter < 'a' || startColumnCharacter > 'h';
}


Column convertToColumn(char aChar) {
    return static_cast<Column>(aChar - 'a');
}

Row convertToRow(char aChar) {
    return static_cast<Row>(aChar - '1');
}
