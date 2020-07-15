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
    int argc;
    char **argv;

    void playGame(ChessGame<std::string> &game);

public:
    ChessCmd(std::istream &istream, std::ostream &ostream, int argc, char **argv);

    void run();
};

#endif //ANYWHERECHESS_CHESSCMD_H
