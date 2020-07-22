#ifndef ANYWHERECHESS_GAMECONTROLLERTEST_H
#define ANYWHERECHESS_GAMECONTROLLERTEST_H

#include <boost/test/unit_test.hpp>
#include <GameController.h>
#include <ChessGame.h>
#include <TestUtils.h>
#include <Move.h>
#include <CmdMove.h>

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


BOOST_AUTO_TEST_CASE(read_move) {
    std::stringstream isstream;
    isstream << "e2e4\n";

    CmdMove cmdMove;
    isstream >> cmdMove;

    BOOST_CHECK(cmdMove.validFormat);
    Move expectedMove = Move{E, _2, E, _4};
    BOOST_CHECK_EQUAL(cmdMove.move, expectedMove);
}

BOOST_AUTO_TEST_CASE(read_all_valid_moves) {
    for (char startColumn = 'a'; startColumn <= 'h'; startColumn++) {
        for (char endColumn = 'a'; endColumn <= 'h'; endColumn++) {
            for (char startRow = '1'; startRow <= '8'; startRow++) {
                for (char endRow = '1'; endRow <= '8'; endRow++) {
                    std::stringstream isstream;
                    isstream << startColumn << startRow << endColumn << endRow << '\n';
                    std::string expected = isstream.str();

                    CmdMove cmdMove;
                    isstream >> cmdMove;

                    BOOST_CHECK(cmdMove.validFormat);
                    /*std::stringstream actualMove;

                    BOOST_CHECK_EQUAL(cmdMove.move, expected);*/
                }
            }
        }
    }
}


void assertInvalidMove(std::string move) {
    std::stringstream isstream;
    isstream << move;
    CmdMove cmdMove;
    isstream >> cmdMove;
    BOOST_CHECK(!cmdMove.validFormat);
}

BOOST_AUTO_TEST_CASE(all_invalid_moves) {
    assertInvalidMove("_1a1\n");
    assertInvalidMove("a_a1\n");
    assertInvalidMove("a1_1\n");
    assertInvalidMove("a1a_\n");
}

#endif //ANYWHERECHESS_GAMECONTROLLERTEST_H
