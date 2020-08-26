//
// Created by Fedorov, Alex on 7/3/20.
//

#ifndef ANYWHERECHESS_PIECECOLOR_H
#define ANYWHERECHESS_PIECECOLOR_H
enum PieceColor {
    WHITE,
    BLACK
};

inline PieceColor opponentPieceColor(PieceColor pieceColor) {
    switch (pieceColor) {
        case PieceColor::WHITE:
            return PieceColor::BLACK;
        case PieceColor::BLACK:
            return PieceColor::WHITE;
    }
}

#endif //ANYWHERECHESS_PIECECOLOR_H
