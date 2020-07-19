//
// Created by Fedorov, Alex on 7/16/20.
//

#ifndef ANYWHERECHESS_PIECEHANDLE_H
#define ANYWHERECHESS_PIECEHANDLE_H

#include "Piece.h"

class PieceHandle {
    Piece *value;
public:
    explicit PieceHandle(Piece *value);

    PieceHandle(PieceHandle &pieceHandle) = delete;

    PieceHandle(PieceHandle &&pieceHandle) noexcept;

    ~PieceHandle();

    [[nodiscard]] Piece getValue() const;

    bool hasValue();

    bool operator==(const PieceHandle &rhs) const;

    bool operator!=(const PieceHandle &rhs) const;

};

#endif //ANYWHERECHESS_PIECEHANDLE_H
