//
// Created by Fedorov, Alex on 7/3/20.
//

#ifndef ANYWHERECHESS_TESTUTILS_H
#define ANYWHERECHESS_TESTUTILS_H

#include <MoveResult.h>

std::ostream &operator<<(std::ostream &os, const Piece &piece);

std::ostream &operator<<(std::ostream &os, const Board &board);

std::ostream &operator<<(std::ostream &os, const MoveResult &moveResult);

std::ostream &operator<<(std::ostream &os, const MoveStatus &moveStatus);

std::ostream &operator<<(std::ostream &os, const Move &moveStatus);

std::ostream &operator<<(std::ostream &os, const Column &column);

std::ostream &operator<<(std::ostream &os, const Row &row);


#endif //ANYWHERECHESS_TESTUTILS_H
