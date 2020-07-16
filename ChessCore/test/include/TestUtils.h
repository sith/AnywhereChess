//
// Created by Fedorov, Alex on 7/3/20.
//

#ifndef ANYWHERECHESS_TESTUTILS_H
#define ANYWHERECHESS_TESTUTILS_H

#include <MoveResult.h>

std::ostream &operator<<(std::ostream &os, const Piece &piece);

std::ostream &operator<<(std::ostream &os, const Board &board);

std::ostream &operator<<(std::ostream &os, const MoveResult &moveResult);

#endif //ANYWHERECHESS_TESTUTILS_H
