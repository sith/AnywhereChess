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

    inline void changeCurrentPlayer() {
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

        const Position &targetPiece = board.get(move.startColumn, move.startRow);

        if (targetPiece.value.pieceColor != expectedPieceColor) {
            return MoveResult(MoveStatus::ILLEGAL);
        }

        if (chessRuleService.isValidMove(move, board)) {
            TakenPiece takenPiece = board.move(move);

            MoveStatus status = MoveStatus::OK;
            PieceColor kingColor = opponentPieceColor(expectedPieceColor);
            if (chessRuleService.isCheck(board, kingColor)) {
                if (chessRuleService.isMate(board, kingColor)) {
                    return MoveResult(MoveStatus::CHECK_MATE, takenPiece);
                }

                status = MoveStatus::CHECK;
            }

            changeCurrentPlayer();
            return MoveResult(status, takenPiece);
        } else {
            return MoveResult(MoveStatus::ILLEGAL);
        }
    }
};


#endif //ANYWHERECHESS_CHESSGAME_H
