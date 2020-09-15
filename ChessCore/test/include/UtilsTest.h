
#ifndef ANYWHERECHESS_UTILSTEST_H
#define ANYWHERECHESS_UTILSTEST_H

#include <boost/test/unit_test.hpp>
#include <utils.h>

BOOST_AUTO_TEST_CASE(absolute_value) {
    BOOST_CHECK_EQUAL(utils::abs(1), 1);
    BOOST_CHECK_EQUAL(utils::abs(-1), 1);
}

BOOST_AUTO_TEST_CASE(min_max) {
    BOOST_CHECK_EQUAL(utils::max(1, 2), 2);
    BOOST_CHECK_EQUAL(utils::min(1, 2), 1);
}


#endif //ANYWHERECHESS_UTILSTEST_H
