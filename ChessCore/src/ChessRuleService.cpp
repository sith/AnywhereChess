//
// Created by Fedorov, Alex on 7/15/20.
//

#include <Move.h>
#include <Board.h>
#include "ChessRuleService.h"

bool ChessRuleService::isValidMove(const Move &move, const Board &board) {
    const Position &position = board.get(move.startColumn, move.startRow);

    if (!position.hasPiece) {
        return false;
    }

    switch (position.piece.pieceType) {
        case PieceType::POND:
            return isValidPondMove(move, position.piece.pieceColor, board);
        case PieceType::ROOK:
            return isValidRookMove(move, board);
        default:
            return false;
    }
}

bool ChessRuleService::isValidPondMove(const Move &move, const PieceColor &pieceColor, const Board &board) {
    bool verticalMove = isVerticalMove(move, pieceColor);

    if (verticalMove && !board.get(move.endColumn, move.endRow).hasPiece) {
        return true;
    }

    return false;
}

bool ChessRuleService::isVerticalMove(const Move &move, const PieceColor &pieceColor) {

    if (!move.isVerticalMove()) {
        return false;
    }

    bool properMoveLength;
    if (pieceColor == PieceColor::WHITE) {
        properMoveLength =
                move.endRow - move.startRow == 1 || (move.startRow == _2 && move.endRow - move.startRow == 2);
    } else {
        properMoveLength =
                move.startRow - move.endRow == 1 || (move.startRow == _7 && move.startRow - move.endRow == 2);
    }
    return properMoveLength;
}

bool ChessRuleService::isValidRookMove(const Move &move, const Board &board) {

    if (move.isVerticalMove()) {
        return true;
    }

    return false;
}
