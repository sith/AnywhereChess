//
// Created by Fedorov, Alex on 7/18/20.
//

#ifndef ANYWHERECHESS_CHESSRULESERVICETEST_H
#define ANYWHERECHESS_CHESSRULESERVICETEST_H

#include <boost/test/unit_test.hpp>
#include <Move.h>

BOOST_AUTO_TEST_CASE(proper_white_pond_move_on_one_square) {
    Board board;
    ChessRuleService chessRuleService;

    BOOST_CHECK(chessRuleService.isValidMove(Move{E, _2, E, _3}, board));
}

BOOST_AUTO_TEST_CASE(proper_black_pond_move_on_one_square) {
    Board board;
    ChessRuleService chessRuleService;

    BOOST_CHECK(chessRuleService.isValidMove(Move{E, _7, E, _6}, board));
}


#endif //ANYWHERECHESS_CHESSRULESERVICETEST_H