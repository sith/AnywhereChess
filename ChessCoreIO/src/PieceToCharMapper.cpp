#include <Piece.h>
#include "PieceToCharMapper.h"

char mapWhitePiece(const Piece &piece);

char mapBlackPiece(const Piece &piece);

char mapPieceToChar(const Piece &piece) {
    switch (piece.pieceColor) {
        case PieceColor::WHITE:
            return mapWhitePiece(piece);
        case PieceColor::BLACK:
            return mapBlackPiece(piece);
    }
}

char mapBlackPiece(const Piece &piece) {
    switch (piece.pieceType) {
        case PieceType::POND:
            return 'p';
        case PieceType::ROOK:
            return 'r';
        case PieceType::KNIGHT:
            return 'n';
        case PieceType::BISHOP:
            return 'b';
        case PieceType::QUEEN:
            return 'q';
        case PieceType::KING:
            return 'k';
    }
}

char mapWhitePiece(const Piece &piece) {
    switch (piece.pieceType) {
        case PieceType::POND:
            return 'P';
        case PieceType::ROOK:
            return 'R';
        case PieceType::KNIGHT:
            return 'N';
        case PieceType::BISHOP:
            return 'B';
        case PieceType::QUEEN:
            return 'Q';
        case PieceType::KING:
            return 'K';
    }
}

char mapPositionToChar(const PieceOptional &pieceOptional) {
    if (pieceOptional.hasPiece) {
        return mapPieceToChar(pieceOptional.piece);
    } else {
        return '.';
    }
}