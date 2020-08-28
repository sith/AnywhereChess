#ifndef ANYWHERECHESS_OPTIONAL_H
#define ANYWHERECHESS_OPTIONAL_H

#include "Piece.h"
#include "Column.h"

template<typename TYPE>
struct Optional {
    const TYPE value;
    const bool hasValue;

    Optional() : hasValue{false}, value{} {}

    explicit Optional(TYPE piece) : hasValue{true}, value{piece} {}

    bool operator==(const Optional &rhs) const {
        return value == rhs.value &&
               hasValue == rhs.hasValue;
    }

    bool operator!=(const Optional &rhs) const {
        return !(rhs == *this);
    }

    TYPE operator()() {
        return value;
    }

};


#endif //ANYWHERECHESS_OPTIONAL_H
