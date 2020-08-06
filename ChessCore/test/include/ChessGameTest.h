#ifndef ANYWHERECHESS_CHESSGAMETEST_H
#define ANYWHERECHESS_CHESSGAMETEST_H

#include <boost/test/unit_test.hpp>
#include <ChessGame.h>
#include <PieceColor.h>
#include <PieceType.h>

std::string playerA = "playerA";
std::string playerB = "playerB";

BOOST_AUTO_TEST_CASE(proper_move_switches_player) {
    std::stringstream stringstream;

    ChessGame<std::string> chessGame{playerA, playerB};

    MoveResult resultOfPlayerAMove = chessGame.move(Move{E, _2, E, _3});
    BOOST_CHECK_EQUAL(resultOfPlayerAMove.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerB);

    MoveResult resultOfPlayerBMove = chessGame.move(Move{E, _7, E, _6});
    BOOST_CHECK_EQUAL(resultOfPlayerBMove.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerA);
}

BOOST_AUTO_TEST_CASE(inproper_move_does_not_switch_player) {
    std::stringstream stringstream;

    ChessGame<std::string> chessGame{playerA, playerB};

    MoveResult resultOfPlayerAMove = chessGame.move(Move{E, _2, E, _8});
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerA);
    BOOST_CHECK_EQUAL(resultOfPlayerAMove.status, MoveStatus::ILLEGAL);
}


BOOST_AUTO_TEST_CASE(return_taken_piece) {
    Board board;

    const Piece &whitePond = Piece{PieceColor::WHITE, PieceType::POND};
    board.set(A, _1, whitePond);
    const Piece &blackPond = Piece{PieceColor::BLACK, PieceType::POND};
    board.set(B, _2, blackPond);

    ChessGame<std::string> chessGame{playerA, playerB, board};

    const MoveResult &result = chessGame.move(Move{A, _1, B, _2});
    BOOST_CHECK_EQUAL(result.status, MoveStatus::OK);
    BOOST_CHECK_MESSAGE(result.takenPiece.hasPiece, "Taken piece must exist");
    BOOST_CHECK_EQUAL(result.takenPiece.piece, blackPond);
}

BOOST_AUTO_TEST_CASE(player_can_move_piece_only_of_its_own_color) {
    Board board;

    const Piece &whitePond = Piece{PieceColor::WHITE, PieceType::POND};
    board.set(A, _1, whitePond);

    const Piece &blackPond = Piece{PieceColor::BLACK, PieceType::POND};
    board.set(B, _2, blackPond);

    ChessGame<std::string> chessGame{playerA, playerB, board};
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerA);
    BOOST_CHECK_EQUAL(chessGame.move(Move{B, _2, B, _1}).status, MoveStatus::ILLEGAL);
    BOOST_CHECK_EQUAL(chessGame.move(Move{A, _1, A, _2}).status, MoveStatus::OK);

    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerB);
    BOOST_CHECK_EQUAL(chessGame.move(Move{A, _2, A, _3}).status, MoveStatus::ILLEGAL);
}


#endif //ANYWHERECHESS_CHESSGAMETEST_H
