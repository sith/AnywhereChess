//
// Created by Fedorov, Alex on 9/7/20.
//

#ifndef ANYWHERECHESS_TESTUTILS_H
#define ANYWHERECHESS_TESTUTILS_H

#include <vector>

template<typename TYPE>
inline std::ostream &operator<<(std::ostream &os, const std::vector<TYPE> &vectorOfSquares) {
    os << '[';
    for (const auto &square : vectorOfSquares) {
        os << square << ", ";
    }
    os << ']';

    return os;
}


#endif //ANYWHERECHESS_TESTUTILS_H
