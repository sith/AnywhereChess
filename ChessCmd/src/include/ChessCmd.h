//
// Created by Fedorov, Alex on 6/30/20.
//

#ifndef ANYWHERECHESS_CHESSCMD_H
#define ANYWHERECHESS_CHESSCMD_H

#include <ChessGame.h>
#include <iostream>

class ChessCmd {
private:
    std::istream &istream;
    std::ostream &ostream;
public:

    ChessCmd(std::istream &istream, std::ostream &ostream);

    void run();
};

std::ostream &operator<<(std::ostream &os, const ChessGame &chessGame);

#endif //ANYWHERECHESS_CHESSCMD_H
