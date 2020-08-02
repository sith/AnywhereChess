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

    if (move.isNoMove()) {
        return false;
    }

    switch (position.piece.pieceType) {
        case PieceType::POND:
            return isValidPondMove(move, position.piece.pieceColor, board);
        case PieceType::ROOK:
            return isValidRookMove(move, board);
        case PieceType::KNIGHT:
            return isValidKnightMove(move, board);
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
    if (
            (move.isVerticalMove() &&
             noJumpOverPiecesVertically(move.startColumn, move.startRow, move.endRow, board)) ||
            (move.isHorizontal() &&
             noJumpOverPiecesHorizontally(move.startRow, move.startColumn, move.endColumn, board))
            ) {
        return true;
    }
    return false;
}

bool ChessRuleService::noJumpOverPiecesVertically(Column column, Row startRow, Row endRow, const Board &board) {
    int delta = startRow <= endRow ? 1 : -1;
    for (int i = startRow + delta; i != endRow; i = i + delta) {
        Row row = (Row) i;
        if (board.hasPieceAt(column, row)) {
            return false;
        }
    }
    return true;
}

bool ChessRuleService::noJumpOverPiecesHorizontally(Row row, Column startColumn, Column endColumn, const Board &board) {
    int delta = startColumn <= endColumn ? 1 : -1;
    for (int i = startColumn + delta; i != endColumn; i = i + delta) {
        Column column = (Column) i;
        if (board.hasPieceAt(column, row)) {
            return false;
        }
    }
    return true;
}

bool ChessRuleService::isValidKnightMove(const Move &move, const Board &board) {
    int columnDiff = move.startColumn - move.endColumn;
    int rowDiff = move.startRow - move.endRow;

    if ((columnDiff == 2 || columnDiff == -2) && (rowDiff == 1 || rowDiff == -1)) {
        return true;
    }
    if ((columnDiff == 1 || columnDiff == -1) && (rowDiff == 2 || rowDiff == -2)) {
        return true;
    }

    return false;
}
