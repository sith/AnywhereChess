#ifndef ANYWHERECHESS_CHESSGAME_H
#define ANYWHERECHESS_CHESSGAME_H

#include "Board.h"
#include "Move.h"
#include "MoveResult.h"
#include "ChessRuleService.h"

template<typename PLAYER>
class ChessGame {
    const PLAYER &player1;
    const PLAYER &player2;
    const PLAYER *currentPlayer;
    Board board;
    ChessRuleService chessRuleService;

    void changeCurrentPlayer() {
        if (*currentPlayer == player1) {
            currentPlayer = &player2;
        } else {
            currentPlayer = &player1;
        }
    }

public:
    ChessGame(PLAYER &player1, PLAYER &player2) :
            player1{player1},
            player2{player2},
            currentPlayer{&player1},
            board{createStandardBoard()} {
    }

    ChessGame(const PLAYER &player1, const PLAYER &player2, Board &board) :
            player1(player1),
            player2(player2),
            board{board} {}


    [[nodiscard]] const Board &getBoard() const {
        return board;
    }

    const PLAYER &getCurrentPlayer() const {
        return *currentPlayer;
    }

    MoveResult move(const Move &move) {
        if (chessRuleService.isValidMove(move, board)) {
            board.move(move);
            changeCurrentPlayer();
            return MoveResult(MoveStatus::OK);
        } else {
            return MoveResult(MoveStatus::ILLEGAL);
        }
    }
};


#endif //ANYWHERECHESS_CHESSGAME_H
