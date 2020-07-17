//
// Created by Fedorov, Alex on 7/16/20.
//

#include <MoveResult.h>

MoveResult::MoveResult(MoveStatus status, TakenPiece takenPiece) {
}

bool MoveResult::operator==(const MoveResult &rhs) const {
    return status == rhs.status &&
           takenPiece == rhs.takenPiece;
}

bool MoveResult::operator!=(const MoveResult &rhs) const {
    return !(rhs == *this);
}

MoveResult::MoveResult(MoveStatus status) : status(status) {}
