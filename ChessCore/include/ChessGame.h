#ifndef ANYWHERECHESS_CHESSGAME_H
#define ANYWHERECHESS_CHESSGAME_H

#include "Board.h"
#include "Move.h"
#include "MoveResult.h"
#include "ChessRuleService.h"

template<typename PLAYER>
class ChessGame {
    const PLAYER &playerWithLightColoredPieces;
    const PLAYER &playerWithDarkColoredPieces;
    const PLAYER *currentPlayer;
    Board board;
    ChessRuleService chessRuleService;

    void changeCurrentPlayer() {
        if (*currentPlayer == playerWithLightColoredPieces) {
            currentPlayer = &playerWithDarkColoredPieces;
        } else {
            currentPlayer = &playerWithLightColoredPieces;
        }
    }

public:
    ChessGame(PLAYER &player1, PLAYER &player2) : playerWithLightColoredPieces(player1),
                                                  playerWithDarkColoredPieces(player2),
                                                  currentPlayer{&player1},
                                                  board{createStandardBoard()} {}

    ChessGame(const PLAYER &player1, const PLAYER &player2, Board &board) :
            playerWithLightColoredPieces(player1),
            playerWithDarkColoredPieces(player2),
            currentPlayer{&player1},
            board{board} {}

    [[nodiscard]] const Board &getBoard() const {
        return board;
    }

    const PLAYER &getCurrentPlayer() const {
        return *currentPlayer;
    }

    MoveResult move(const Move &move) {
        PieceColor expectedPieceColor = currentPlayer == &playerWithLightColoredPieces ? PieceColor::WHITE
                                                                                      : PieceColor::BLACK;
        if (chessRuleService.isValidMove(move, board, expectedPieceColor)) {
            TakenPiece takenPiece = board.move(move);
            changeCurrentPlayer();
            return MoveResult(MoveStatus::OK, takenPiece);
        } else {
            return MoveResult(MoveStatus::ILLEGAL);
        }
    }
};


#endif //ANYWHERECHESS_CHESSGAME_H
