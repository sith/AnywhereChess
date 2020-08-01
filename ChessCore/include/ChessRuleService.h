//
// Created by Fedorov, Alex on 7/15/20.
//

#ifndef ANYWHERECHESS_CHESSRULESERVICE_H
#define ANYWHERECHESS_CHESSRULESERVICE_H


class ChessRuleService {
    inline bool isValidPondMove(const Move &move, const PieceColor &pieceColor, const Board &board);

    inline bool isVerticalMove(const Move &move, const PieceColor &pieceColor);

public:
    bool isValidMove(const Move &move, const Board &board);

};


#endif //ANYWHERECHESS_CHESSRULESERVICE_H
