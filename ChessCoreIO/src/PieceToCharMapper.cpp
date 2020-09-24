#include <Piece.h>
#include <Types.h>
#include "PieceToCharMapper.h"

std::string mapWhitePiece(const Piece &piece);

std::string mapBlackPiece(const Piece &piece);

std::string mapPieceToChar(const Piece &piece) {
    switch (piece.pieceColor) {
        case PieceColor::WHITE:
            return mapWhitePiece(piece);
        case PieceColor::BLACK:
            return mapBlackPiece(piece);
    }
}

std::string mapBlackPiece(const Piece &piece) {
    switch (piece.pieceType) {
        case PieceType::POND:
            return "\u265F";
        case PieceType::ROOK:
            return "\u265C";
        case PieceType::KNIGHT:
            return "\u265E";
        case PieceType::BISHOP:
            return "\u265D";
        case PieceType::QUEEN:
            return "\u265B";
        case PieceType::KING:
            return "\u265A";
    }
}

std::string mapWhitePiece(const Piece &piece) {
    switch (piece.pieceType) {
        case PieceType::POND:
            return "\u2659";
        case PieceType::ROOK:
            return "\u2656";
        case PieceType::KNIGHT:
            return "\u2658";
        case PieceType::BISHOP:
            return "\u2657";
        case PieceType::QUEEN:
            return "\u2655";
        case PieceType::KING:
            return "\u2654";
    }
}

std::string mapPositionToChar(const Position &pieceOptional) {
    if (pieceOptional.hasValue) {
        return mapPieceToChar(pieceOptional.value);
    } else {
        return ".";
    }
}
