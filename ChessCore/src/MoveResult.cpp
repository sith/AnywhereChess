//
// Created by Fedorov, Alex on 7/16/20.
//

#include <MoveResult.h>

MoveResult::MoveResult(MoveStatus status) : status{status} {
}

bool MoveResult::operator==(const MoveResult &rhs) const {
    return status == rhs.status;
}

bool MoveResult::operator!=(const MoveResult &rhs) const {
    return !(rhs == *this);
}
