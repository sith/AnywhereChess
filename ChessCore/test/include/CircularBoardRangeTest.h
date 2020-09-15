#ifndef ANYWHERECHESS_CIRCULARBOARDRANGETEST_H
#define ANYWHERECHESS_CIRCULARBOARDRANGETEST_H

#include <boost/test/unit_test.hpp>
#include <CircularBoardRange.h>
#include <TestUtils.h>


BOOST_AUTO_TEST_CASE(iterate_in_the_middle) {
    CircularBoardRange circularBoardRange{Square{E, _4}};
    std::vector<Square> actualSquares;
    while (circularBoardRange.hasNext()) {
        actualSquares.push_back(circularBoardRange.next());
    }

    std::vector<Square> expectedSquares{
            {D, _3},
            {E, _3},
            {F, _3},
            {D, _4},
            {F, _4},
            {D, _5},
            {E, _5},
            {F, _5},
    };

    BOOST_CHECK_EQUAL(actualSquares, expectedSquares);
}

BOOST_AUTO_TEST_CASE(iterate_in_the_left_bottom_corner) {
    CircularBoardRange circularBoardRange{Square{A, _1}};
    std::vector<Square> actualSquares;
    while (circularBoardRange.hasNext()) {
        actualSquares.push_back(circularBoardRange.next());
    }

    std::vector<Square> expectedSquares{
            {B, _1},
            {A, _2},
            {B, _2},
    };

    BOOST_CHECK_EQUAL(actualSquares, expectedSquares);
}

BOOST_AUTO_TEST_CASE(iterate_in_the_left_upper_corner) {
    CircularBoardRange circularBoardRange{Square{A, _8}};
    std::vector<Square> actualSquares;
    while (circularBoardRange.hasNext()) {
        actualSquares.push_back(circularBoardRange.next());
    }

    std::vector<Square> expectedSquares{
            {A, _7},
            {B, _7},
            {B, _8},
    };

    BOOST_CHECK_EQUAL(actualSquares, expectedSquares);
}

BOOST_AUTO_TEST_CASE(iterate_in_the_right_upper_corner) {
    CircularBoardRange circularBoardRange{Square{H, _8}};
    std::vector<Square> actualSquares;
    while (circularBoardRange.hasNext()) {
        actualSquares.push_back(circularBoardRange.next());
    }

    std::vector<Square> expectedSquares{
            {G, _7},
            {H, _7},
            {G, _8},
    };

    BOOST_CHECK_EQUAL(actualSquares, expectedSquares);
}

BOOST_AUTO_TEST_CASE(iterate_in_the_right_lower_corner) {
    CircularBoardRange circularBoardRange{Square{H, _1}};
    std::vector<Square> actualSquares;
    while (circularBoardRange.hasNext()) {
        actualSquares.push_back(circularBoardRange.next());
    }

    std::vector<Square> expectedSquares{
            {G, _1},
            {G, _2},
            {H, _2},
    };

    BOOST_CHECK_EQUAL(actualSquares, expectedSquares);
}


#endif //ANYWHERECHESS_CIRCULARBOARDRANGETEST_H
