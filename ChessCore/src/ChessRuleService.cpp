#include "ChessRuleService.h"

#include <Move.h>
#include <Board.h>
#include <utils.h>
#include <Square.h>
#include <Optional.h>
#include <RectangleBoardRange.h>
#include <CircularBoardRange.h>

bool ChessRuleService::isValidMove(const Move &move, const Board &board) const {
    if (isValidMoveInternal(move, board)) {
        Board tmpBoard = board;
        tmpBoard.move(move);
        return !isCheck(tmpBoard, board.get(move.startColumn, move.startRow).value.pieceColor);
    }

    return false;
}

bool ChessRuleService::isCheck(const Board &board, const PieceColor kingColor) const {
    Optional<Square> king = findKing(board, kingColor);

    if (!king.hasValue) {
        return false;
    }

    RectangleBoardRange rectangleBoardRange;

    while (rectangleBoardRange.hasNext()) {
        const Square &square = rectangleBoardRange.next();
        const Move &checkMove = Move{square.column, square.row, king().column, king().row};
        if (isValidMoveInternal(checkMove, board)) {
            return true;
        }
    }
    return false;
}


bool ChessRuleService::isValidMoveInternal(const Move &move, const Board &board) const {
    const Position &startPosition = board.get(move.startColumn, move.startRow);

    if (!startPosition.hasValue) {
        return false;
    }

    if (move.isNoMove()) {
        return false;
    }

    switch (startPosition.value.pieceType) {
        case POND:
            return isValidPondMove(move, startPosition.value.pieceColor, board);
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

bool ChessRuleService::isValidPondMove(const Move &move, const PieceColor &pieceColor, const Board &board) const {
    bool verticalMove = isVerticalMove(move, pieceColor);

    const Position &position = board.get(move.endColumn, move.endRow);
    if (verticalMove && !position.hasValue) {
        return true;
    }
    if (move.isDiagonalOfSize(1)) {
        switch (pieceColor) {
            case PieceColor::WHITE:
                if (move.endRow > move.startRow
                    && position.hasValue
                    && position.value.pieceColor != PieceColor::WHITE) {
                    return true;
                }
                break;
            case PieceColor::BLACK:
                if (move.endRow < move.startRow
                    && position.hasValue
                    && position.value.pieceColor != PieceColor::BLACK) {
                    return true;
                }
                break;
        }
    }

    return false;
}

bool ChessRuleService::isVerticalMove(const Move &move, const PieceColor &pieceColor) const {

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

bool ChessRuleService::isValidRookMove(const Move &move, const Board &board) const {
    if ((isProperVerticalMove(move, board) || isProperHorizontalMove(move, board))
        && (destinationPositionIsEmpty(move, board) || hasPieceOfDifferentColor(move, board))) {
        return true;
    }
    return false;
}

bool ChessRuleService::isProperHorizontalMove(const Move &move, const Board &board) const {
    return (move.isHorizontal() &&
            noJumpOverPiecesHorizontally(
                    move.startRow,
                    move.startColumn,
                    move.endColumn,
                    board));
}

bool ChessRuleService::isProperVerticalMove(const Move &move, const Board &board) const {
    return (move.isVerticalMove() &&
            noJumpOverPiecesVertically(
                    move.startColumn,
                    move.startRow,
                    move.endRow,
                    board));
}

bool ChessRuleService::noJumpOverPiecesVertically(Column column, Row startRow, Row endRow, const Board &board) const {
    int delta = startRow <= endRow ? 1 : -1;
    for (int i = startRow + delta; i != endRow; i = i + delta) {
        Row row = (Row) i;
        if (board.hasPieceAt(column, row)) {
            return false;
        }
    }
    return true;
}

bool ChessRuleService::noJumpOverPiecesHorizontally(Row row, Column startColumn, Column endColumn,
                                                    const Board &board) const {
    int delta = startColumn <= endColumn ? 1 : -1;
    for (int i = startColumn + delta; i != endColumn; i = i + delta) {
        Column column = (Column) i;
        if (board.hasPieceAt(column, row)) {
            return false;
        }
    }
    return true;
}

bool ChessRuleService::isValidKnightMove(const Move &move, const Board &board) const {
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

bool ChessRuleService::isValidBishopMove(const Move &move, const Board &board) const {
    if (move.isDiagonal() && noJumpOverPiecesDiagonally(move, board) &&
        (destinationPositionIsEmpty(move, board) || hasPieceOfDifferentColor(move, board))) {
        return true;
    }
    return false;
}

bool ChessRuleService::noJumpOverPiecesDiagonally(const Move &move, const Board &board) const {

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

bool ChessRuleService::isValidKingMove(const Move &move, const Board &board) const {
    int columnDiff = move.startColumn - move.endColumn;
    int rowDiff = move.startRow - move.endRow;

    return (columnDiff <= 1 && columnDiff >= -1) && (rowDiff <= 1 && rowDiff >= -1) &&
           (destinationPositionIsEmpty(move, board) || hasPieceOfDifferentColor(move, board));
}

bool ChessRuleService::destinationPositionIsEmpty(const Move &move, const Board &board) const {
    return !board.hasPieceAt(move.endColumn, move.endRow);
}

bool ChessRuleService::hasPieceOfDifferentColor(const Move &move, const Board &board) const {
    const Position &startPosition = board.get(move.startColumn, move.startRow);
    const Position &endPosition = board.get(move.endColumn, move.endRow);
    if (startPosition.hasValue
        && endPosition.hasValue
        && endPosition.value.pieceColor == startPosition.value.pieceColor) {
        return false;
    }
    return true;
}

Optional<Square> ChessRuleService::findKing(const Board &board, PieceColor color) const {

    RectangleBoardRange rectangleBoardRange;
    while (rectangleBoardRange.hasNext()) {
        const Square &square = rectangleBoardRange.next();

        const Position &pieceOptional = board.get(square);
        if (pieceOptional.hasValue && pieceOptional.value == Piece{color, KING}) {
            return Optional<Square>{square};
        }

    }
    return Optional<Square>{};
}

bool ChessRuleService::isMate(const Board &board, PieceColor kingColor) const {
    Optional<Square> king = findKing(board, kingColor);

    const Square &kingSquare = king();
    Column startColumn = findStartColumnForKingMoveCheck(kingSquare);
    Column endColumn = findEndColumnForKingMove(kingSquare);
    Row startRow = findStartRowForKingMoveCheck(kingSquare);
    Row endRow = findEndRowForKingMoveCheck(kingSquare);

    RectangleBoardRange rectangleBoardRange{{startColumn, startRow},
                                            {endColumn,   endRow}};

    while (rectangleBoardRange.hasNext()) {
        const Square &square = rectangleBoardRange.next();
        if (isValidMove({kingSquare.column, kingSquare.row, square.column, square.row}, board)) {
            return false;
        }
    }
    return true;
}

Row ChessRuleService::findEndRowForKingMoveCheck(const Square &square) const {
    Row endRow;
    if (square.row == _8) {
        endRow = _8;
    } else {
        endRow = (Row) (square.row + 1);
    }
    return endRow;
}

Row ChessRuleService::findStartRowForKingMoveCheck(const Square &square) const {
    Row startRow;
    if (square.row == _1) {
        startRow = _1;
    } else {
        startRow = (Row) (square.row - 1);
    }
    return startRow;
}

Column ChessRuleService::findEndColumnForKingMove(const Square &square) const {
    if (square.column == H) {
        return H;
    } else {
        return (Column) (square.column + 1);
    }
}

Column ChessRuleService::findStartColumnForKingMoveCheck(const Square &square) const {
    if (square.column == A) {
        return A;
    } else {
        return (Column) (square.column - 1);
    }
}

bool ChessRuleService::isStaleMate(const Board &board, PieceColor targetColor) const {
    if (isCheck(board, targetColor)) {
        return false;
    }

    RectangleBoardRange rectangleBoardRange;

    while (rectangleBoardRange.hasNext()) {
        const Square &square = rectangleBoardRange.next();
        Position position = board.get(square);
        if (position.hasValue
            && position().pieceColor == targetColor
            && canMove(board, position(), square)) {
            return false;
        }
    }

    return true;
}

bool ChessRuleService::canMove(const Board &board, const Piece &piece, const Square &square) const {
    CircularBoardRange circularBoardRange{square};
    while (circularBoardRange.hasNext()) {
        if (isValidMove(Move{square, circularBoardRange.next()}, board)) {
            return true;
        }
    }
    return false;
}

