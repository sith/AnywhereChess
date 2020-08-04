//
// Created by Fedorov, Alex on 7/15/20.
//

#ifndef ANYWHERECHESS_MOVERESULT_H
#define ANYWHERECHESS_MOVERESULT_H

enum class
        MoveStatus {
    OK, ILLEGAL
};

struct MoveResult {
    MoveStatus status;

    explicit MoveResult(MoveStatus status);

    bool operator==(const MoveResult &rhs) const;

    bool operator!=(const MoveResult &rhs) const;

};

#endif //ANYWHERECHESS_MOVERESULT_H
