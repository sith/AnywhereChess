//
// Created by Fedorov, Alex on 7/15/20.
//

#ifndef ANYWHERECHESS_MOVERESULT_H
#define ANYWHERECHESS_MOVERESULT_H

#include "PieceHandle.h"

//using TakenPiece = PieceHandle;

enum class
        MoveStatus {
    OK, ILLEGAL
};

struct MoveResult {
    MoveStatus status;
//    PieceHandle takenPiece;


    explicit MoveResult(MoveStatus status);

    bool operator==(const MoveResult &rhs) const;

    bool operator!=(const MoveResult &rhs) const;

};

#endif //ANYWHERECHESS_MOVERESULT_H
