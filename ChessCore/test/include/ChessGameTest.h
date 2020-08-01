#ifndef ANYWHERECHESS_CHESSGAMETEST_H
#define ANYWHERECHESS_CHESSGAMETEST_H

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(proper_move_switches_player) {
    std::stringstream stringstream;

    std::string playerA = "playerA";
    std::string playerB = "playerB";

    ChessGame<std::string> chessGame{playerA, playerB};

    MoveResult resultOfPlayerAMove = chessGame.move(Move{E, _2, E, _3});
    BOOST_CHECK_EQUAL(resultOfPlayerAMove.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerB);

    MoveResult resultOfPlayerBMove = chessGame.move(Move{E, _7, E, _6});
    BOOST_CHECK_EQUAL(resultOfPlayerBMove.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerA);
}

BOOST_AUTO_TEST_CASE(inproper_move_does_not_swith_player) {
    std::stringstream stringstream;

    std::string playerA = "playerA";
    std::string playerB = "playerB";

    ChessGame<std::string> chessGame{playerA, playerB};

    MoveResult resultOfPlayerAMove = chessGame.move(Move{E, _2, E, _8});
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerA);
    BOOST_CHECK_EQUAL(resultOfPlayerAMove.status, MoveStatus::ILLEGAL);
}


#endif //ANYWHERECHESS_CHESSGAMETEST_H