//
// Created by Fedorov, Alex on 7/2/20.
//

#ifndef ANYWHERECHESS_CHESSGAME_H
#define ANYWHERECHESS_CHESSGAME_H


#include "Board.h"

class ChessGame {
    Board board;
public:

    [[nodiscard]] const Board & getBoard() const;


};


#endif //ANYWHERECHESS_CHESSGAME_H
