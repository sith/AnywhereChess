//
// Created by Fedorov, Alex on 7/18/20.
//

#ifndef ANYWHERECHESS_CHESSRULESERVICETEST_H
#define ANYWHERECHESS_CHESSRULESERVICETEST_H

#include <boost/test/unit_test.hpp>
#include <Move.h>
#include <set>
#include <boost/format.hpp>
#include <iostream>
#include <TestUtils.h>

void assertMoves(Board &board, const std::set<Move> &validMoves);


/*----General move rules----*/

BOOST_AUTO_TEST_CASE(move_to_same_squeare_is_illigal) {
    Board board;
    ChessRuleService chessRuleService;

    board.set(A, _3, Piece{PieceColor::WHITE, PieceType::POND});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));

    board.set(A, _3, Piece{PieceColor::WHITE, PieceType::ROOK});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));

    board.set(A, _3, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));

    board.set(A, _3, Piece{PieceColor::WHITE, PieceType::BISHOP});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));

    board.set(A, _3, Piece{PieceColor::WHITE, PieceType::QUEEN});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));

    board.set(A, _3, Piece{PieceColor::WHITE, PieceType::KING});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));

    board.set(A, _3, Piece{PieceColor::BLACK, PieceType::POND});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));

    board.set(A, _3, Piece{PieceColor::BLACK, PieceType::ROOK});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));

    board.set(A, _3, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));

    board.set(A, _3, Piece{PieceColor::BLACK, PieceType::BISHOP});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));

    board.set(A, _3, Piece{PieceColor::BLACK, PieceType::QUEEN});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));

    board.set(A, _3, Piece{PieceColor::BLACK, PieceType::KING});
    BOOST_CHECK(!chessRuleService.isValidMove(Move{A, _3, A, _3}, board));
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

BOOST_AUTO_TEST_CASE(rook_valid_moves) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _4, E, _1},
            Move{E, _4, E, _2},
            Move{E, _4, E, _3},
            Move{E, _4, E, _5},
            Move{E, _4, E, _6},
            Move{E, _4, E, _7},
            Move{E, _4, E, _8},

            Move{E, _4, A, _4},
            Move{E, _4, B, _4},
            Move{E, _4, C, _4},
            Move{E, _4, D, _4},
            Move{E, _4, F, _4},
            Move{E, _4, G, _4},
            Move{E, _4, H, _4},
    };

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::ROOK});
    assertMoves(board, validMoves);

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::ROOK});
    assertMoves(board, validMoves);
}

BOOST_AUTO_TEST_CASE(rook_cannot_jump_over_pieces) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _4, E, _3},
            Move{E, _4, E, _5},
            Move{E, _4, D, _4},
            Move{E, _4, F, _4},
    };

    board.set(E, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(D, _4, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _4, Piece{PieceColor::WHITE, PieceType::POND});

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::ROOK});
    assertMoves(board, validMoves);

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::ROOK});
    assertMoves(board, validMoves);
}


/*------------------------*/


void assertMoves(Board &board, const std::set<Move> &validMoves) {
    ChessRuleService chessRuleService;
    for (int i = Row::_1; i <= Row::_8; i++) {
        for (int j = Column::A; j <= Column::H; j++) {
            auto row = (Row) i;
            auto column = (Column) j;

            Move move{E, _4, column, row};
            if (validMoves.count(move) > 0) {
                BOOST_CHECK_MESSAGE(chessRuleService.isValidMove(move, board),
                                    boost::format("Move %1%") % move);
            } else {
                BOOST_CHECK_MESSAGE(!chessRuleService.isValidMove(move, board),
                                    boost::format("Move %1%") % move);
            }
        }
    }
}


#endif //ANYWHERECHESS_CHESSRULESERVICETEST_H
