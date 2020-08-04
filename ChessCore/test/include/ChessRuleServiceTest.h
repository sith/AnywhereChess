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

void assertMoves(Board &board, std::set<Move> validMoves, Column startColumn, Row startRow);


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

BOOST_AUTO_TEST_CASE(white_pond_moves_from_starting_postition) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _2, E, _3},
            Move{E, _2, E, _4},
    };
    board.set(E, _2, Piece{PieceColor::WHITE, PieceType::POND});

    assertMoves(board, validMoves, E, _2);
}

BOOST_AUTO_TEST_CASE(black_pond_moves_from_starting_postition) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _7, E, _6},
            Move{E, _7, E, _5},
    };
    board.set(E, _7, Piece{PieceColor::BLACK, PieceType::POND});

    assertMoves(board, validMoves, E, _7);
}

BOOST_AUTO_TEST_CASE(white_pond_moves_from_non_starting_postition) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _3, E, _4},
    };
    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::POND});

    assertMoves(board, validMoves, E, _3);
}

BOOST_AUTO_TEST_CASE(white_pond_can_make_forward_diagonal_move_when_taking_piece) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _3, E, _4},
            Move{E, _3, D, _4},
            Move{E, _3, F, _4},
    };
    board.set(D, _4, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _4, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(D, _2, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _1, Piece{PieceColor::BLACK, PieceType::POND});

    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::POND});
    assertMoves(board, validMoves, E, _3);
}

BOOST_AUTO_TEST_CASE(white_pond_can_not_make_diagonal_move_when_taking_same_color_piece) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _3, E, _4},
    };
    board.set(D, _4, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _5, Piece{PieceColor::WHITE, PieceType::POND});

    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::POND});
    assertMoves(board, validMoves, E, _3);
}


BOOST_AUTO_TEST_CASE(black_pond_moves_from_non_starting_postition) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _6, E, _5},
    };
    board.set(E, _6, Piece{PieceColor::BLACK, PieceType::POND});

    assertMoves(board, validMoves, E, _6);
}

BOOST_AUTO_TEST_CASE(black_pond_can_make_forward_diagonal_move_when_taking_piece) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _6, E, _5},
            Move{E, _6, D, _5},
            Move{E, _6, F, _5},
    };
    board.set(D, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(D, _7, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _7, Piece{PieceColor::WHITE, PieceType::POND});

    board.set(E, _6, Piece{PieceColor::BLACK, PieceType::POND});
    assertMoves(board, validMoves, E, _6);
}

BOOST_AUTO_TEST_CASE(black_pond_can_not_make_diagonal_move_when_taking_same_color_piece) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _6, E, _5},
    };
    board.set(D, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _5, Piece{PieceColor::BLACK, PieceType::POND});

    board.set(E, _6, Piece{PieceColor::BLACK, PieceType::POND});
    assertMoves(board, validMoves, E, _6);
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
    assertMoves(board, validMoves, E, _4);

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::ROOK});
    assertMoves(board, validMoves, E, _4);
}

BOOST_AUTO_TEST_CASE(rook_cannot_jump_over_pieces) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _4, E, _3},
            Move{E, _4, E, _5},
            Move{E, _4, D, _4},
            Move{E, _4, F, _4},
    };

    board.set(E, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(E, _3, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(D, _4, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _4, Piece{PieceColor::BLACK, PieceType::POND});

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::ROOK});
    assertMoves(board, validMoves, E, _4);


    board.set(E, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(D, _4, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _4, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::ROOK});
    assertMoves(board, validMoves, E, _4);
}

BOOST_AUTO_TEST_CASE(rook_cannot_take_a_same_color_piece) {
    Board board;
    std::set<Move> validMoves{};

    board.set(E, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(D, _4, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _4, Piece{PieceColor::WHITE, PieceType::POND});

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::ROOK});
    assertMoves(board, validMoves, E, _4);


    board.set(E, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(E, _3, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(D, _4, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _4, Piece{PieceColor::BLACK, PieceType::POND});

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::ROOK});
    assertMoves(board, validMoves, E, _4);
}



/*------------------------*/


/*---- Knight moves -----*/
BOOST_AUTO_TEST_CASE(knight_moves) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _4, D, _6},
            Move{E, _4, F, _6},
            Move{E, _4, G, _5},
            Move{E, _4, G, _3},
            Move{E, _4, F, _2},
            Move{E, _4, D, _2},
            Move{E, _4, C, _3},
            Move{E, _4, C, _5},
    };

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    assertMoves(board, validMoves, E, _4);

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    assertMoves(board, validMoves, E, _4);
}

BOOST_AUTO_TEST_CASE(knight_can_take_piece) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _4, D, _6},
            Move{E, _4, F, _6},
            Move{E, _4, G, _5},
            Move{E, _4, G, _3},
            Move{E, _4, F, _2},
            Move{E, _4, D, _2},
            Move{E, _4, C, _3},
            Move{E, _4, C, _5},
    };

    board.set(D, _6, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(F, _6, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(G, _5, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(G, _3, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(F, _2, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(D, _2, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(C, _3, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(C, _5, Piece{PieceColor::BLACK, PieceType::KNIGHT});

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    assertMoves(board, validMoves, E, _4);

    board.set(D, _6, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(F, _6, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(G, _5, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(G, _3, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(F, _2, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(D, _2, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(C, _3, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(C, _5, Piece{PieceColor::WHITE, PieceType::KNIGHT});

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    assertMoves(board, validMoves, E, _4);
}

BOOST_AUTO_TEST_CASE(knight_cannot_take_piece) {
    Board board;
    std::set<Move> validMoves{
    };

    board.set(D, _6, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(F, _6, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(G, _5, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(G, _3, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(F, _2, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(D, _2, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(C, _3, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    board.set(C, _5, Piece{PieceColor::WHITE, PieceType::KNIGHT});

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::KNIGHT});
    assertMoves(board, validMoves, E, _4);

    board.set(D, _6, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(F, _6, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(G, _5, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(G, _3, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(F, _2, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(D, _2, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(C, _3, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    board.set(C, _5, Piece{PieceColor::BLACK, PieceType::KNIGHT});

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::KNIGHT});
    assertMoves(board, validMoves, E, _4);
}



/*------------------------*/

/*--- Bishop Moves ----*/

BOOST_AUTO_TEST_CASE(bishop_moves) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _4, A, _8},
            Move{E, _4, B, _7},
            Move{E, _4, C, _6},
            Move{E, _4, D, _5},
            Move{E, _4, F, _3},
            Move{E, _4, G, _2},
            Move{E, _4, H, _1},

            Move{E, _4, B, _1},
            Move{E, _4, C, _2},
            Move{E, _4, D, _3},
            Move{E, _4, F, _5},
            Move{E, _4, G, _6},
            Move{E, _4, H, _7},
    };

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::BISHOP});
    assertMoves(board, validMoves, E, _4);

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::BISHOP});
    assertMoves(board, validMoves, E, _4);
}

BOOST_AUTO_TEST_CASE(bishop_cannot_jump_over_pieces_moves) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _4, F, _5},
            Move{E, _4, D, _5},
            Move{E, _4, F, _3},
            Move{E, _4, D, _3},
    };

    board.set(D, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(D, _3, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _3, Piece{PieceColor::BLACK, PieceType::POND});

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::BISHOP});
    assertMoves(board, validMoves, E, _4);

    board.set(D, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(D, _3, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _3, Piece{PieceColor::WHITE, PieceType::POND});


    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::BISHOP});
    assertMoves(board, validMoves, E, _4);
}

BOOST_AUTO_TEST_CASE(bishop_cannot_take_same_color_piece) {
    Board board;
    std::set<Move> validMoves{};

    board.set(D, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(D, _3, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _3, Piece{PieceColor::WHITE, PieceType::POND});

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::BISHOP});
    assertMoves(board, validMoves, E, _4);

    board.set(D, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(D, _3, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _3, Piece{PieceColor::BLACK, PieceType::POND});


    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::BISHOP});
    assertMoves(board, validMoves, E, _4);
}

/*------------------------*/


/*---- Queen moves ----*/
BOOST_AUTO_TEST_CASE(queen_moves) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _4, A, _8},
            Move{E, _4, B, _7},
            Move{E, _4, C, _6},
            Move{E, _4, D, _5},
            Move{E, _4, F, _3},
            Move{E, _4, G, _2},
            Move{E, _4, H, _1},

            Move{E, _4, B, _1},
            Move{E, _4, C, _2},
            Move{E, _4, D, _3},
            Move{E, _4, F, _5},
            Move{E, _4, G, _6},
            Move{E, _4, H, _7},

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

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::QUEEN});
    assertMoves(board, validMoves, E, _4);

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::QUEEN});
    assertMoves(board, validMoves, E, _4);
}

BOOST_AUTO_TEST_CASE(queen_cannot_jump_over_pieces_moves) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _4, F, _5},
            Move{E, _4, D, _5},
            Move{E, _4, F, _3},
            Move{E, _4, D, _3},

            Move{E, _4, E, _3},
            Move{E, _4, E, _5},
            Move{E, _4, D, _4},
            Move{E, _4, F, _4},
    };

    board.set(D, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(D, _3, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _3, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(E, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(E, _3, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(D, _4, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _4, Piece{PieceColor::BLACK, PieceType::POND});

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::QUEEN});
    assertMoves(board, validMoves, E, _4);

    board.set(D, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(D, _3, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _3, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(E, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(D, _4, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _4, Piece{PieceColor::WHITE, PieceType::POND});

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::QUEEN});
    assertMoves(board, validMoves, E, _4);
}

BOOST_AUTO_TEST_CASE(queen_cannot_take_same_color_pieces) {
    Board board;
    std::set<Move> validMoves{
    };

    board.set(D, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(D, _3, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _3, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(E, _5, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(D, _4, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(F, _4, Piece{PieceColor::WHITE, PieceType::POND});

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::QUEEN});
    assertMoves(board, validMoves, E, _4);

    board.set(D, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(D, _3, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _3, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(E, _5, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(E, _3, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(D, _4, Piece{PieceColor::BLACK, PieceType::POND});
    board.set(F, _4, Piece{PieceColor::BLACK, PieceType::POND});

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::QUEEN});
    assertMoves(board, validMoves, E, _4);
}



/*------------------------*/

/*---- King moves -----*/
BOOST_AUTO_TEST_CASE(king_moves_and_takes_pieces_arround) {
    Board board;
    std::set<Move> validMoves{
            Move{E, _4, F, _5},
            Move{E, _4, D, _5},
            Move{E, _4, F, _3},
            Move{E, _4, D, _3},
            Move{E, _4, E, _3},
            Move{E, _4, E, _5},
            Move{E, _4, D, _4},
            Move{E, _4, F, _4},
    };

    board.set(F, _5, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(D, _5, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(F, _3, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(D, _3, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(E, _3, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(E, _5, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(D, _4, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(F, _4, Piece{PieceColor::BLACK, PieceType::KING});

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::KING});
    assertMoves(board, validMoves, E, _4);

    board.set(F, _5, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(D, _5, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(F, _3, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(D, _3, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(E, _5, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(D, _4, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(F, _4, Piece{PieceColor::WHITE, PieceType::KING});

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::KING});
    assertMoves(board, validMoves, E, _4);
}

BOOST_AUTO_TEST_CASE(king_cannot_take_same_color_pieces) {
    Board board;
    std::set<Move> validMoves{
    };

    board.set(F, _5, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(D, _5, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(F, _3, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(D, _3, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(E, _3, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(E, _5, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(D, _4, Piece{PieceColor::WHITE, PieceType::KING});
    board.set(F, _4, Piece{PieceColor::WHITE, PieceType::KING});

    board.set(E, _4, Piece{PieceColor::WHITE, PieceType::KING});
    assertMoves(board, validMoves, E, _4);

    board.set(F, _5, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(D, _5, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(F, _3, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(D, _3, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(E, _3, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(E, _5, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(D, _4, Piece{PieceColor::BLACK, PieceType::KING});
    board.set(F, _4, Piece{PieceColor::BLACK, PieceType::KING});

    board.set(E, _4, Piece{PieceColor::BLACK, PieceType::KING});
    assertMoves(board, validMoves, E, _4);
}


/*------------------------*/
void assertMoves(Board &board, std::set<Move> validMoves, Column startColumn, Row startRow) {
    ChessRuleService chessRuleService;
    for (int i = Row::_1; i <= Row::_8; i++) {
        for (int j = Column::A; j <= Column::H; j++) {
            auto row = (Row) i;
            auto column = (Column) j;

            Move move{startColumn, startRow, column, row};
            if (validMoves.count(move) > 0) {
                BOOST_CHECK_MESSAGE(chessRuleService.isValidMove(move, board),
                                    boost::format("Move %1%") % move);
                validMoves.erase(move);
            } else {
                BOOST_CHECK_MESSAGE(!chessRuleService.isValidMove(move, board),
                                    boost::format("Move %1%") % move);
            }
        }
    }
    BOOST_CHECK_MESSAGE(validMoves.empty(), "All valid moves must be checked");
}


#endif //ANYWHERECHESS_CHESSRULESERVICETEST_H
