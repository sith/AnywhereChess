//
// Created by Fedorov, Alex on 7/15/20.
//

#include <Move.h>
#include <Board.h>
#include "ChessRuleService.h"
#include <utils.h>
#include <Square.h>

bool ChessRuleService::isValidMove(const Move &move, const Board &board) {
    return isValidMoveInternal(move, board);

}

bool ChessRuleService::isValidMoveInternal(const Move &move, const Board &board) {
    const Position &startPosition = board.get(move.startColumn, move.startRow);

    if (!startPosition.hasPiece) {
        return false;
    }

    if (move.isNoMove()) {
        return false;
    }

    switch (startPosition.piece.pieceType) {
        case POND:
            return isValidPondMove(move, startPosition.piece.pieceColor, board);
        case ROOK:
            return isValidRookMove(move, board);
        case KNIGHT:
            return isValidKnightMove(move, board);
        case BISHOP:
            return isValidBishopMove(move, board);
        case QUEEN:
            return isValidBishopMove(move, board) || isValidRookMove(move, board);
        case KING:
            return isValidKingMove(move, board);
        default:
            return false;
    }
}

bool ChessRuleService::isValidPondMove(const Move &move, const PieceColor &pieceColor, const Board &board) {
    bool verticalMove = isVerticalMove(move, pieceColor);

    const Position &position = board.get(move.endColumn, move.endRow);
    if (verticalMove && !position.hasPiece) {
        return true;
    }
    if (move.isDiagonalOfSize(1)) {
        switch (pieceColor) {
            case PieceColor::WHITE:
                if (move.endRow > move.startRow
                    && position.hasPiece
                    && position.piece.pieceColor != PieceColor::WHITE) {
                    return true;
                }
                break;
            case PieceColor::BLACK:
                if (move.endRow < move.startRow
                    && position.hasPiece
                    && position.piece.pieceColor != PieceColor::BLACK) {
                    return true;
                }
                break;
        }
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
    if ((isProperVerticalMove(move, board) || isProperHorizontalMove(move, board))
        && (destinationPositionIsEmpty(move, board) || hasPieceOfDifferentColor(move, board))) {
        return true;
    }
    return false;
}

bool ChessRuleService::isProperHorizontalMove(const Move &move, const Board &board) {
    return (move.isHorizontal() &&
            noJumpOverPiecesHorizontally(
                    move.startRow,
                    move.startColumn,
                    move.endColumn,
                    board));
}

bool ChessRuleService::isProperVerticalMove(const Move &move, const Board &board) {
    return (move.isVerticalMove() &&
            noJumpOverPiecesVertically(
                    move.startColumn,
                    move.startRow,
                    move.endRow,
                    board));
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
    int columnDiff = utils::abs(move.startColumn - move.endColumn);
    int rowDiff = utils::abs(move.startRow - move.endRow);

    if (columnDiff == 2 && rowDiff == 1 &&
        (destinationPositionIsEmpty(move, board) || hasPieceOfDifferentColor(move, board))) {
        return true;
    }

    if (columnDiff == 1 && rowDiff == 2 &&
        (destinationPositionIsEmpty(move, board) || hasPieceOfDifferentColor(move, board))) {
        return true;
    }

    return false;
}

bool ChessRuleService::isValidBishopMove(const Move &move, const Board &board) {
    if (move.isDiagonal() && noJumpOverPiecesDiagonally(move, board) &&
        (destinationPositionIsEmpty(move, board) || hasPieceOfDifferentColor(move, board))) {
        return true;
    }
    return false;
}

bool ChessRuleService::noJumpOverPiecesDiagonally(const Move &move, const Board &board) {

    Column column = move.startColumn;
    Row row = move.startRow;

    int columnDelta = move.startColumn <= move.endColumn ? 1 : -1;
    int rowDelta = move.startRow <= move.endRow ? 1 : -1;

    while (column - move.endColumn + columnDelta != 0 && row - move.endRow + rowDelta != 0) {
        column = (Column) (column + columnDelta);
        row = (Row) (row + rowDelta);

        if (board.hasPieceAt(column, row)) {
            return false;
        }
    }
    return true;
}

bool ChessRuleService::isValidKingMove(const Move &move, const Board &board) {
    int columnDiff = move.startColumn - move.endColumn;
    int rowDiff = move.startRow - move.endRow;

    return (columnDiff <= 1 && columnDiff >= -1) && (rowDiff <= 1 && rowDiff >= -1) &&
           (destinationPositionIsEmpty(move, board) || hasPieceOfDifferentColor(move, board));
}

bool ChessRuleService::destinationPositionIsEmpty(const Move &move, const Board &board) {
    return !board.hasPieceAt(move.endColumn, move.endRow);
}

bool ChessRuleService::hasPieceOfDifferentColor(const Move &move, const Board &board) {
    const Position &startPosition = board.get(move.startColumn, move.startRow);
    const Position &endPosition = board.get(move.endColumn, move.endRow);
    if (startPosition.hasPiece
        && endPosition.hasPiece
        && endPosition.piece.pieceColor == startPosition.piece.pieceColor) {
        return false;
    }
    return true;
}

bool ChessRuleService::isCheck(const Board &board, const PieceColor kingColor) {
    Square king = findKing(board, kingColor);

    for (int i = Row::_1; i <= Row::_8; i++) {
        for (int j = Column::A; j <= Column::H; j++) {
            auto row = (Row) i;
            auto column = (Column) j;

            const Move &checkMove = Move{column, row, king.column, king.row};
            if (isValidMoveInternal(checkMove, board)) {
                return true;
            }
        }
    }
    return false;
}

Square ChessRuleService::findKing(const Board &board, PieceColor color) {
    for (int i = Row::_1; i <= Row::_8; i++) {
        for (int j = Column::A; j <= Column::H; j++) {
            auto row = (Row) i;
            auto column = (Column) j;
            const Position &pieceOptional = board.get(column, row);
            if (pieceOptional.hasPiece && pieceOptional.piece == Piece{color, KING}) {
                return {column, row};
            }
        }
    }

}
