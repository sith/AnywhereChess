//
// Created by Fedorov, Alex on 7/15/20.
//

#ifndef ANYWHERECHESS_CHESSRULESERVICE_H
#define ANYWHERECHESS_CHESSRULESERVICE_H


class ChessRuleService {
    inline bool isValidPondMove(const Move &move, const PieceColor &pieceColor, const Board &board);

    inline bool isVerticalMove(const Move &move, const PieceColor &pieceColor);

    inline bool isValidRookMove(const Move &move, const Board &board);

    inline bool isValidKnightMove(const Move &move, const Board &board);

    inline bool isValidBishopMove(const Move &move, const Board &board);

    inline bool isValidKingMove(const Move &move, const Board &board);

    inline bool noJumpOverPiecesDiagonally(const Move &move, const Board &board);

    inline bool noJumpOverPiecesVertically(Column column, Row startRow, Row endRow, const Board &board);

    inline bool noJumpOverPiecesHorizontally(Row row, Column startColumn, Column endColumn, const Board &board);

    inline bool isProperVerticalMove(const Move &move, const Board &board);

    inline bool isProperHorizontalMove(const Move &move, const Board &board);

    inline bool destinationPositionIsEmpty(const Move &move, const Board &board);

    inline bool hasPieceOfDifferentColor(const Move &move, const Board &board);

public:

    bool isValidMove(const Move &move, const Board &board);
};


#endif //ANYWHERECHESS_CHESSRULESERVICE_H
