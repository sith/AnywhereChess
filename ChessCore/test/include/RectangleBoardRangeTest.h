#include <boost/test/unit_test.hpp>
#include <RectangleBoardRange.h>
#include <vector>

std::vector<Square> expectedSquares{
        {A, _1},
        {B, _1},
        {C, _1},
        {D, _1},
        {E, _1},
        {F, _1},
        {G, _1},
        {H, _1},
        {A, _2},
        {B, _2},
        {C, _2},
        {D, _2},
        {E, _2},
        {F, _2},
        {G, _2},
        {H, _2},
        {A, _3},
        {B, _3},
        {C, _3},
        {D, _3},
        {E, _3},
        {F, _3},
        {G, _3},
        {H, _3},
        {A, _4},
        {B, _4},
        {C, _4},
        {D, _4},
        {E, _4},
        {F, _4},
        {G, _4},
        {H, _4},
        {A, _5},
        {B, _5},
        {C, _5},
        {D, _5},
        {E, _5},
        {F, _5},
        {G, _5},
        {H, _5},
        {A, _6},
        {B, _6},
        {C, _6},
        {D, _6},
        {E, _6},
        {F, _6},
        {G, _6},
        {H, _6},
        {A, _7},
        {B, _7},
        {C, _7},
        {D, _7},
        {E, _7},
        {F, _7},
        {G, _7},
        {H, _7},
        {A, _8},
        {B, _8},
        {C, _8},
        {D, _8},
        {E, _8},
        {F, _8},
        {G, _8},
        {H, _8},
};

std::ostream &operator<<(std::ostream &os, const std::vector<Square> &vectorOfSquares);


BOOST_AUTO_TEST_CASE(iterate_over_the_whole_board) {

    RectangleBoardRange squareRange{};

    std::vector<Square> actualSquares;
    while (squareRange.hasNext()) {
        actualSquares.push_back(squareRange.next());
    }
    BOOST_CHECK_EQUAL(expectedSquares, actualSquares);
}


BOOST_AUTO_TEST_CASE(properly_starts_from_lower_left_end_of_the_range) {

    RectangleBoardRange squareRange{{H, _8},
                                    {A, _1}};

    std::vector<Square> actualSquares;
    while (squareRange.hasNext()) {
        actualSquares.push_back(squareRange.next());
    }
    BOOST_CHECK_EQUAL(expectedSquares, actualSquares);
}


BOOST_AUTO_TEST_CASE(iterate_over_one_square) {
    const Square &expectedSquare = Square{A, _1};
    RectangleBoardRange squareRange{expectedSquare,
                                    expectedSquare};

    BOOST_CHECK(squareRange.hasNext());
    BOOST_CHECK_EQUAL(squareRange.next(), expectedSquare);
    BOOST_CHECK(!squareRange.hasNext());
}


std::ostream &operator<<(std::ostream &os, const std::vector<Square> &vectorOfSquares) {
    os << '[';
    for (const auto &square : vectorOfSquares) {
        os << square << ", ";
    }
    os << ']';

    return os;
}
