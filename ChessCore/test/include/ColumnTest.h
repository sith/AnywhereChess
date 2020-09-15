//
// Created by Fedorov, Alex on 9/8/20.
//

#ifndef ANYWHERECHESS_COLUMNTEST_H
#define ANYWHERECHESS_COLUMNTEST_H

#include <boost/test/unit_test.hpp>
#include <Column.h>

BOOST_AUTO_TEST_CASE(sum_with_int) {
    BOOST_CHECK_EQUAL(A + 1, B);
    BOOST_CHECK_EQUAL(A + 2, C);
    BOOST_CHECK_EQUAL(A + 7, H);
    BOOST_CHECK_EQUAL(A + 1000, H);
    BOOST_CHECK_EQUAL(H + 1, H);
}

BOOST_AUTO_TEST_CASE(substract_with_int) {
    BOOST_CHECK_EQUAL(H - 1, G);
    BOOST_CHECK_EQUAL(H - 2, F);
    BOOST_CHECK_EQUAL(H - 7, A);
    BOOST_CHECK_EQUAL(H - 1000, A);
    BOOST_CHECK_EQUAL(A - 1, A);
}

BOOST_AUTO_TEST_CASE(column_diff) {
    BOOST_CHECK_EQUAL(A - A, 0);
    BOOST_CHECK_EQUAL(A - B, -1);
    BOOST_CHECK_EQUAL(B - A, 1);
    BOOST_CHECK_EQUAL(A - H, -7);
    BOOST_CHECK_EQUAL(H - A, 7);
}


#endif //ANYWHERECHESS_COLUMNTEST_H
