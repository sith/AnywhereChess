//
// Created by Fedorov, Alex on 7/20/20.
//

#include <TestUtils.h>
#include <boost/format.hpp>

std::ostream &operator<<(std::ostream &os, const Move &move) {
    os << boost::format("%1%%2%-%3%%4%") % move.startColumn % move.startRow % move.endColumn % move.endRow;
    return os;
}
