#ifndef ANYWHERECHESS_GAMECONTROLLERTEST_H
#define ANYWHERECHESS_GAMECONTROLLERTEST_H

#include <boost/test/unit_test.hpp>
#include <GameController.h>
#include <ChessGame.h>
#include <ChessCoreIO.h>
#include <Move.h>
#include <CmdMove.h>
#include <RectangleBoardRange.h>

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

    RectangleBoardRange startIterator;
    RectangleBoardRange endIterator;

    while (startIterator.hasNext()) {
        const Square &startSquare = startIterator.next();
        while (endIterator.hasNext()) {
            const Square &endSquare = endIterator.next();
            std::stringstream isstream;
            isstream << startSquare.column << startSquare.row << endSquare.column << endSquare.row << '\n';

            CmdMove cmdMove;
            isstream >> cmdMove;

            BOOST_CHECK(cmdMove.validFormat);
            const Move &expectedMove = Move{startSquare, endSquare};
            BOOST_CHECK_EQUAL(cmdMove.move, expectedMove);
        }
    }
}

BOOST_AUTO_TEST_CASE(give_up_move) {
    std::stringstream isstream;
    isstream << giveUpString << '\n';

    CmdMove cmdMove;
    isstream >> cmdMove;
    BOOST_CHECK(cmdMove.validFormat);
    BOOST_CHECK(cmdMove.giveUp);
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


void validPieceType(const char *input, PieceType expectedPieceType) {
    std::stringstream isstream;
    isstream << input << "\n";
    CmdPieceType cmdPieceType;
    isstream >> cmdPieceType;
    BOOST_CHECK(cmdPieceType.validFormat);
    BOOST_CHECK_EQUAL(cmdPieceType.pieceType, expectedPieceType);
}

BOOST_AUTO_TEST_CASE(read_piece_type) {
    validPieceType("pond", POND);
    validPieceType("bishop", BISHOP);
    validPieceType("rook", ROOK);
    validPieceType("knight", KNIGHT);
    validPieceType("king", KING);
    validPieceType("queen", QUEEN);
}

BOOST_AUTO_TEST_CASE(invalid_piece_type) {
    std::stringstream isstream;
    isstream << "HelloWorld" << "\n";
    CmdPieceType cmdPieceType;
    isstream >> cmdPieceType;
    BOOST_CHECK(!cmdPieceType.validFormat);
}


#endif //ANYWHERECHESS_GAMECONTROLLERTEST_H
