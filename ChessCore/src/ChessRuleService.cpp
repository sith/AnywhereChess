//
// Created by Fedorov, Alex on 7/15/20.
//

#include <Move.h>
#include <Board.h>
#include "ChessRuleService.h"

bool ChessRuleService::isValidMove(const Move &move, const Board &board) {

    const Position &position = board.get(move.startColumn, move.startRow);

    if (position.piece.pieceType == PieceType::POND) {
        if (position.piece.pieceColor == PieceColor::WHITE) {
            if (move.startColumn == move.endColumn && move.endRow - move.startRow == 1) {
                return true;
            }
        } else {
            if (move.startColumn == move.endColumn && move.startRow - move.endRow == 1) {
                return true;
            }
        }
    }
    return false;
}
