#ifndef ANYWHERECHESS_CHESSGAME_H
#define ANYWHERECHESS_CHESSGAME_H

#include "Board.h"
#include "Move.h"
#include "MoveResult.h"
#include "ChessRuleService.h"
#include "PromotionResult .h"

enum class ChessGameState {
    IN_PROGRESS,
    PROMOTION,
    CHECK,
    CHECK_AND_MATE,
    STALE_MATE
};


template<typename PLAYER>
class ChessGame {
    const PLAYER &playerWithLightColoredPieces;
    const PLAYER &playerWithDarkColoredPieces;
    const PLAYER *currentPlayer;
    Board board;
    ChessRuleService chessRuleService;

    Square promotionSquare{A, _1};

    ChessGameState state = ChessGameState::IN_PROGRESS;


    inline void changeCurrentPlayer() {
        if (*currentPlayer == playerWithLightColoredPieces) {
            currentPlayer = &playerWithDarkColoredPieces;
        } else {
            currentPlayer = &playerWithLightColoredPieces;
        }
    }

    inline void updateGameState(PieceColor kingColor) {
        if (chessRuleService.isCheck(board, kingColor)) {
            if (chessRuleService.isMate(board, kingColor)) {
                state = ChessGameState::CHECK_AND_MATE;
            } else {
                state = ChessGameState::CHECK;
            }
            return;
        }

        if (chessRuleService.isStaleMate(board, kingColor)) {
            state = ChessGameState::STALE_MATE;
            return;
        }

        state = ChessGameState::IN_PROGRESS;
    }

    inline bool isReadyForPromotion(const Move &move, const Position &targetPiece) const {
        return (targetPiece.value == Piece{WHITE, POND} && move.endRow == _8) ||
               (targetPiece.value == Piece{BLACK, POND} && move.endRow == _1);
    }

    inline bool shouldChangePlayer() const {
        return state != ChessGameState::CHECK_AND_MATE && state != ChessGameState::STALE_MATE;
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

    [[nodiscard]] const ChessGameState &getState() const {
        return state;
    };


    PromotionResult promote(PieceType pieceType) {
        if (pieceType == POND || pieceType == KING || state != ChessGameState::PROMOTION) {
            return PromotionResult::FAILED;
        }

        const Position &position = board.get(promotionSquare);
        Piece newPiece{position.value.pieceColor, pieceType};
        board.set(promotionSquare, newPiece);
        changeCurrentPlayer();
        updateGameState(opponentPieceColor(position.value.pieceColor));
        return PromotionResult::SUCCESSFUL;
    };

    MoveResult move(const Move &move) {

        if (state == ChessGameState::CHECK_AND_MATE || state == ChessGameState::STALE_MATE) {
            return MoveResult{MoveStatus::NO_MOVE_GAME_OVER};
        }

        if (state == ChessGameState::PROMOTION) {
            return MoveResult{MoveStatus::ILLEGAL};
        }

        PieceColor expectedPieceColor = currentPlayer == &playerWithLightColoredPieces ? PieceColor::WHITE
                                                                                       : PieceColor::BLACK;
        const Position &targetPiece = board.get(move.startColumn, move.startRow);

        if (!targetPiece.hasValue || targetPiece.value.pieceColor != expectedPieceColor) {
            return MoveResult(MoveStatus::ILLEGAL);
        }

        if (!chessRuleService.isValidMove(move, board)) {
            return MoveResult(MoveStatus::ILLEGAL);
        }

        TakenPiece takenPiece = board.move(move);

        if (isReadyForPromotion(move, targetPiece)) {
            state = ChessGameState::PROMOTION;
            promotionSquare = {move.endColumn, move.endRow};
            return MoveResult{MoveStatus::OK};
        }
        updateGameState(opponentPieceColor(expectedPieceColor));

        if (shouldChangePlayer()) {
            changeCurrentPlayer();
        }
        return MoveResult(MoveStatus::OK, takenPiece);
    }
};


#endif //ANYWHERECHESS_CHESSGAME_H
