//
// Created by Fedorov, Alex on 7/13/20.
//

#ifndef ANYWHERECHESS_PONDMOVETEST_H
#define ANYWHERECHESS_PONDMOVETEST_H

#include <boost/test/unit_test.hpp>
#include <GameController.h>
#include <ChessGame.h>
#include <Move.h>

BOOST_AUTO_TEST_CASE(pond_moves_to_one_square) {
    std::stringstream stringstream;

    std::string playerA = "playerA";
    std::string playerB = "playerB";

    ChessGame<std::string> chessGame{playerA, playerB};
    Move move{'e','2','e','4'};
    chessGame.move(move);

    stringstream << chessGame;
    BOOST_CHECK(stringstream.str() ==
                " abcdefgh \n"
                "8rnbqkbnr8\n"
                "7pppppppp7\n"
                "6........6\n"
                "5........5\n"
                "4........4\n"
                "3....P...3\n"
                "2PPPP.PPP2\n"
                "1RNBQKBNR1\n"
                " abcdefgh \n"
                "playerA>"
    );
}


#endif //ANYWHERECHESS_PONDMOVETEST_H
