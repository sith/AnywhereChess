#ifndef ANYWHERECHESS_GAMECONTROLLERTEST_H
#define ANYWHERECHESS_GAMECONTROLLERTEST_H

#include <boost/test/unit_test.hpp>
#include <GameController.h>
#include <ChessGame.h>

BOOST_AUTO_TEST_CASE(displays_provided_board_with_next_user) {
    std::stringstream stringstream;

    std::string playerA = "playerA";
    std::string playerB = "playerB";

    ChessGame<std::string> chessGame{playerA, playerB};

    stringstream << chessGame;
    BOOST_CHECK_EQUAL(stringstream.str(),
                      " abcdefgh \n"
                      "8rnbqkbnr8\n"
                      "7pppppppp7\n"
                      "6........6\n"
                      "5........5\n"
                      "4........4\n"
                      "3........3\n"
                      "2PPPPPPPP2\n"
                      "1RNBQKBNR1\n"
                      " abcdefgh \n"
                      "playerA>"
    );
}


BOOST_AUTO_TEST_CASE(displays_error_message_in_case_of_illigal_move) {
    std::stringstream stringstream;

    std::string playerA = "playerA";
    std::string playerB = "playerB";

    ChessGame<std::string> chessGame{playerA, playerB};

    chessGame.move(Move{E, _2, C, _5});

    stringstream << chessGame;
    BOOST_CHECK_EQUAL(stringstream.str(),
                      " abcdefgh \n"
                      "8rnbqkbnr8\n"
                      "7pppppppp7\n"
                      "6........6\n"
                      "5........5\n"
                      "4........4\n"
                      "3........3\n"
                      "2PPPPPPPP2\n"
                      "1RNBQKBNR1\n"
                      " abcdefgh \n"
                      "error>Illegal move\n"
                      "playerA>"
    );
}

/*

BOOST_AUTO_TEST_CASE(reads_move_) {
    std::stringstream stringstream;

    std::string playerA = "playerA";
    std::string playerB = "playerB";

    ChessGame<std::string> chessGame{playerA, playerB};

    stringstream << chessGame;
    BOOST_CHECK(stringstream.str() ==
                " abcdefgh \n"
                "8rnbqkbnr8\n"
                "7pppppppp7\n"
                "6........6\n"
                "5........5\n"
                "4........4\n"
                "3........3\n"
                "2PPPPPPPP2\n"
                "1RNBQKBNR1\n"
                " abcdefgh \n"
                "playerA>"
    );
}
*/


#endif //ANYWHERECHESS_GAMECONTROLLERTEST_H
