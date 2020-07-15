#ifndef ANYWHERECHESS_CHESSGAME_H
#define ANYWHERECHESS_CHESSGAME_H

#include "Board.h"
#include "Move.h"

template<typename PLAYER>
class ChessGame {
    const PLAYER &player1;
    const PLAYER &player2;
    PLAYER &currentPlayer;
    Board board;
public:
    ChessGame(PLAYER &player1, PLAYER &player2) : player1(player1), player2(player2),
                                                  currentPlayer(player1) {}

    [[nodiscard]] const Board &getBoard() const {
        return board;
    }

    const PLAYER &getCurrentPlayer() const {
        return currentPlayer;
    }

    void move(Move move) {

    }
};


#endif //ANYWHERECHESS_CHESSGAME_H
