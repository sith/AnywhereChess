//
// Created by Fedorov, Alex on 8/3/20.
//

#ifndef ANYWHERECHESS_UTILS_H
#define ANYWHERECHESS_UTILS_H
namespace utils {
    template<typename NUMBER>
    inline NUMBER abs(NUMBER number) {
        if (number < 0) {
            return number * -1;
        }
        return number;
    }

    template<typename TYPE>
    inline TYPE min(TYPE a, TYPE b) {
        if (a <= b) {
            return a;
        } else {
            return b;
        }
    }

    template<typename TYPE>
    inline TYPE max(TYPE a, TYPE b) {
        if (a >= b) {
            return a;
        } else {
            return b;
        }
    }

}
#endif //ANYWHERECHESS_UTILS_H
