//
// Created by Fedorov, Alex on 7/18/20.
//

#ifndef ANYWHERECHESS_CHESSRULESERVICETEST_H
#define ANYWHERECHESS_CHESSRULESERVICETEST_H

#include <boost/test/unit_test.hpp>
#include <Move.h>


/*----General move rules----*/
BOOST_AUTO_TEST_CASE(move_to_the_same_square_is_illigal) {
    Board board = createStandardBoard();
    ChessRuleService chessRuleService;

    BOOST_CHECK(!chessRuleService.isValidMove(Move{E, _2, E, _2}, board));
}

BOOST_AUTO_TEST_CASE(improper_move_when_there_is_no_piece) {
    Board board = createStandardBoard();
    ChessRuleService chessRuleService;

    BOOST_CHECK(!chessRuleService.isValidMove(Move{E, _4, E, _5}, board));
}

/*----Pond rules----*/
BOOST_AUTO_TEST_CASE(proper_white_pond_move_on_one_square) {
    Board board = createStandardBoard();
    ChessRuleService chessRuleService;

    BOOST_CHECK(chessRuleService.isValidMove(Move{E, _2, E, _3}, board));
}

BOOST_AUTO_TEST_CASE(proper_white_pond_move_on_two_squares_for_starting_position) {
    Board board = createStandardBoard();
    ChessRuleService chessRuleService;

    BOOST_CHECK(chessRuleService.isValidMove(Move{E, _2, E, _4}, board));
}

BOOST_AUTO_TEST_CASE(proper_black_pond_move_on_one_square) {
    Board board = createStandardBoard();
    ChessRuleService chessRuleService;

    BOOST_CHECK(chessRuleService.isValidMove(Move{E, _7, E, _6}, board));
}

BOOST_AUTO_TEST_CASE(proper_black_pond_move_on_two_squares_for_starting_position) {
    Board board;
    board.set(A, _1, Piece{PieceColor::WHITE, PieceType::ROOK});
    ChessRuleService chessRuleService;

    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _1, A, _1}, board));
}


BOOST_AUTO_TEST_CASE(white_pond_cannot_move_forward_if_there_is_an_other_piece) {
    Board board;

    board.set(E, _2, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::POND});

    ChessRuleService chessRuleService;

    BOOST_CHECK(!chessRuleService.isValidMove(Move{E, _2, E, _3}, board));
}

BOOST_AUTO_TEST_CASE(black_pond_cannot_move_forward_if_there_is_an_other_piece) {
    Board board;

    board.set(E, _7, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(E, _6, Piece{PieceColor::BLACK, PieceType::POND});

    ChessRuleService chessRuleService;

    BOOST_CHECK(!chessRuleService.isValidMove(Move{E, _7, E, _6}, board));
}


BOOST_AUTO_TEST_CASE(white_pond_cannot_move_backwards) {
    Board board;
    board.set(E, _2, Piece{PieceColor::WHITE, PieceType::POND});
    ChessRuleService chessRuleService;

    BOOST_CHECK(!chessRuleService.isValidMove(Move{E, _2, E, _1}, board));
}

BOOST_AUTO_TEST_CASE(black_pond_cannot_move_backwards) {
    Board board;
    board.set(E, _7, Piece{PieceColor::BLACK, PieceType::POND});
    ChessRuleService chessRuleService;

    BOOST_CHECK(!chessRuleService.isValidMove(Move{E, _7, E, _8}, board));
}

BOOST_AUTO_TEST_CASE(white_pond_cannot_move_by_diagaonal) {
    Board board;
    board.set(E, _2, Piece{PieceColor::WHITE, PieceType::POND});
    ChessRuleService chessRuleService;

    BOOST_CHECK(!chessRuleService.isValidMove(Move{E, _2, F, _3}, board));
}

BOOST_AUTO_TEST_CASE(black_pond_cannot_move_by_diagonal) {
    Board board;
    board.set(E, _7, Piece{PieceColor::BLACK, PieceType::POND});
    ChessRuleService chessRuleService;

    BOOST_CHECK(!chessRuleService.isValidMove(Move{E, _7, F, _6}, board));
}

BOOST_AUTO_TEST_CASE(white_pond_cannot_move_on_two_squares_if_not_on_a_starting_position) {
    Board board;
    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::POND});
    ChessRuleService chessRuleService;

    BOOST_CHECK(!chessRuleService.isValidMove(Move{E, _3, E, _5}, board));
}

BOOST_AUTO_TEST_CASE(black_pond_cannot_move_on_two_squares_if_not_on_a_starting_position) {
    Board board;
    board.set(E, _6, Piece{PieceColor::BLACK, PieceType::POND});
    ChessRuleService chessRuleService;

    BOOST_CHECK(!chessRuleService.isValidMove(Move{E, _6, E, _4}, board));
}

/*------------------------*/

/*----Rook rules-----*/




/*------------------------*/

#endif //ANYWHERECHESS_CHESSRULESERVICETEST_H
