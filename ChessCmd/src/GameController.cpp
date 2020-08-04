#include "Row.h"
#include <GameController.h>
#include <iostream>
#include <ChessCoreIO.h>


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


Column convertToColumn(char aChar) {
    return static_cast<Column>(aChar - 'a');
}

Row convertToRow(char aChar) {
    return static_cast<Row>(aChar - '1');
}
