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

    if (position.piece.pieceType == PieceType::POND) {
        return isValidPondMove(move, position.piece.pieceColor, board);
    }
    return false;
}

bool ChessRuleService::isValidPondMove(const Move &move, const PieceColor &pieceColor, const Board &board) {
    bool moveALongTheSameColumn = move.startColumn == move.endColumn;
    bool verticalMove = isVerticalMove(move, pieceColor);

    if (moveALongTheSameColumn && verticalMove && !board.get(move.endColumn, move.endRow).hasPiece) {
        return true;
    }

    return false;
}

bool ChessRuleService::isVerticalMove(const Move &move, const PieceColor &pieceColor) {
    bool verticalMove;
    if (pieceColor == PieceColor::WHITE) {
        verticalMove =
                move.endRow - move.startRow == 1 || (move.startRow == _2 && move.endRow - move.startRow == 2);
    } else {
        verticalMove =
                move.startRow - move.endRow == 1 || (move.startRow == _7 && move.startRow - move.endRow == 2);
    }
    return verticalMove;
}
