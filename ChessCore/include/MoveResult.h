//
// Created by Fedorov, Alex on 7/15/20.
//

#ifndef ANYWHERECHESS_MOVERESULT_H
#define ANYWHERECHESS_MOVERESULT_H

#include <Types.h>

enum class
MoveStatus {
    OK, ILLEGAL
};

struct MoveResult {
    MoveStatus status{};
    TakenPiece takenPiece{};

    explicit MoveResult(MoveStatus status);

    MoveResult(MoveStatus status, const TakenPiece &takenPiece);

    bool operator==(const MoveResult &rhs) const;

    bool operator!=(const MoveResult &rhs) const;
};

#endif //ANYWHERECHESS_MOVERESULT_H
