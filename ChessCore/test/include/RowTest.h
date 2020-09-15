//
// Created by Fedorov, Alex on 9/8/20.
//

#ifndef ANYWHERECHESS_ROWTEST_H
#define ANYWHERECHESS_ROWTEST_H

#include <boost/test/unit_test.hpp>
#include <Row.h>

BOOST_AUTO_TEST_CASE(row_sum_with_int) {
    BOOST_CHECK_EQUAL(_1 + 1, _2);
    BOOST_CHECK_EQUAL(_1 + 2, _3);
    BOOST_CHECK_EQUAL(_1 + 7, _8);
    BOOST_CHECK_EQUAL(_1 + 1000, _8);
    BOOST_CHECK_EQUAL(_8 + 1, _8);
}

BOOST_AUTO_TEST_CASE(row_substract_with_int) {
    BOOST_CHECK_EQUAL(_8 - 1, _7);
    BOOST_CHECK_EQUAL(_8 - 2, _6);
    BOOST_CHECK_EQUAL(_8 - 7, _1);
    BOOST_CHECK_EQUAL(_8 - 1000, _1);
    BOOST_CHECK_EQUAL(_1 - 1, _1);
}

BOOST_AUTO_TEST_CASE(row_diff) {
    BOOST_CHECK_EQUAL(_1 - _1, 0);
    BOOST_CHECK_EQUAL(_1 - _2, -1);
    BOOST_CHECK_EQUAL(_2 - _1, 1);
    BOOST_CHECK_EQUAL(_1 - _8, -7);
    BOOST_CHECK_EQUAL(_8 - _1, 7);
}


#endif //ANYWHERECHESS_ROWTEST_H
