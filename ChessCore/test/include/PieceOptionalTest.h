//
// Created by Fedorov, Alex on 8/22/20.
//

#ifndef ANYWHERECHESS_PIECEOPTIONALTEST_H
#define ANYWHERECHESS_PIECEOPTIONALTEST_H

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(equal) {

    BOOST_CHECK_EQUAL(Optional<Piece>{}, Optional<Piece>{});

    Optional<Piece> blackPond1{{BLACK, POND}};
    Optional<Piece> blackPond2{{BLACK, POND}};
    BOOST_CHECK_EQUAL(blackPond2, blackPond1);

    Optional<Piece> whitePond{{WHITE, POND}};
    BOOST_CHECK_NE(blackPond1, whitePond);
}


#endif //ANYWHERECHESS_PIECEOPTIONALTEST_H
