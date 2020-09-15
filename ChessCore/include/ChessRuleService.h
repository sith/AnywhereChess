//
// Created by Fedorov, Alex on 7/15/20.
//

#ifndef ANYWHERECHESS_CHESSRULESERVICE_H
#define ANYWHERECHESS_CHESSRULESERVICE_H


#include <Square.h>
#include <Row.h>
#include <Board.h>
#include <Move.h>
#include <PieceColor.h>

class ChessRuleService {
    inline bool isValidPondMove(const Move &move, const PieceColor &pieceColor, const Board &board) const;

    inline bool isVerticalMove(const Move &move, const PieceColor &pieceColor) const;

    inline bool isValidRookMove(const Move &move, const Board &board) const;

    inline bool isValidKnightMove(const Move &move, const Board &board) const;

    inline bool isValidBishopMove(const Move &move, const Board &board) const;

    inline bool isValidKingMove(const Move &move, const Board &board) const;

    inline bool noJumpOverPiecesDiagonally(const Move &move, const Board &board) const;

    inline bool noJumpOverPiecesVertically(Column column, Row startRow, Row endRow, const Board &board) const;

    inline bool noJumpOverPiecesHorizontally(Row row, Column startColumn, Column endColumn, const Board &board) const;

    inline bool isProperVerticalMove(const Move &move, const Board &board) const;

    inline bool isProperHorizontalMove(const Move &move, const Board &board) const;

    inline bool destinationPositionIsEmpty(const Move &move, const Board &board) const;

    inline bool hasPieceOfDifferentColor(const Move &move, const Board &board) const;

    inline bool isValidMoveInternal(const Move &move, const Board &board) const;

    inline Optional<Square> findKing(const Board &board, PieceColor color) const;

    inline Column findStartColumnForKingMoveCheck(const Square &square) const;

    inline Column findEndColumnForKingMove(const Square &square) const;

    inline Row findStartRowForKingMoveCheck(const Square &square) const;

    inline Row findEndRowForKingMoveCheck(const Square &square) const;

    inline bool canMove(const Board &board, const Piece &piece, const Square &square) const;

public:

    [[nodiscard]] bool isValidMove(const Move &move, const Board &board) const;

    [[nodiscard]] bool isCheck(const Board &board, PieceColor kingColor) const;

    [[nodiscard]] bool isMate(const Board &board, PieceColor kingColor) const;

    [[nodiscard]] bool isStaleMate(const Board &board, PieceColor targetColor) const;

};


#endif //ANYWHERECHESS_CHESSRULESERVICE_H
