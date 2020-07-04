#include <boost/test/unit_test.hpp>
#include <Board.h>
#include "TestUtils.h"

void positionHas(Board &board, char column, char row, const Piece &expectedPiece);

BOOST_AUTO_TEST_CASE(initial_board) {
    Board board{};

    positionHas(board, 'a', '1', Piece(PieceColor::WHITE, PieceType::ROOK));
    positionHas(board, 'b', '1', Piece(PieceColor::WHITE, PieceType::KNIGHT));
    positionHas(board, 'c', '1', Piece(PieceColor::WHITE, PieceType::BISHOP));
    positionHas(board, 'd', '1', Piece(PieceColor::WHITE, PieceType::QUEEN));
    positionHas(board, 'e', '1', Piece(PieceColor::WHITE, PieceType::KING));
    positionHas(board, 'f', '1', Piece(PieceColor::WHITE, PieceType::BISHOP));
    positionHas(board, 'g', '1', Piece(PieceColor::WHITE, PieceType::KNIGHT));
    positionHas(board, 'h', '1', Piece(PieceColor::WHITE, PieceType::ROOK));

    positionHas(board, 'a', '2', Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, 'b', '2', Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, 'c', '2', Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, 'd', '2', Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, 'e', '2', Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, 'f', '2', Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, 'g', '2', Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, 'h', '2', Piece(PieceColor::WHITE, PieceType::POND));

    positionHas(board, 'a', '7', Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, 'b', '7', Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, 'c', '7', Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, 'd', '7', Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, 'e', '7', Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, 'f', '7', Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, 'g', '7', Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, 'h', '7', Piece(PieceColor::BLACK, PieceType::POND));

    positionHas(board, 'a', '8', Piece(PieceColor::BLACK, PieceType::ROOK));
    positionHas(board, 'b', '8', Piece(PieceColor::BLACK, PieceType::KNIGHT));
    positionHas(board, 'c', '8', Piece(PieceColor::BLACK, PieceType::BISHOP));
    positionHas(board, 'd', '8', Piece(PieceColor::BLACK, PieceType::QUEEN));
    positionHas(board, 'e', '8', Piece(PieceColor::BLACK, PieceType::KING));
    positionHas(board, 'f', '8', Piece(PieceColor::BLACK, PieceType::BISHOP));
    positionHas(board, 'g', '8', Piece(PieceColor::BLACK, PieceType::KNIGHT));
    positionHas(board, 'h', '8', Piece(PieceColor::BLACK, PieceType::ROOK));

    for (char column = 'a'; column <='h'; column++) {
        for (char row = '3'; row <= '6'; row++) {
            BOOST_TEST(!board.get(column, row).hasPiece);
        }
    }
}

void positionHas(Board &board, char column, char row, const Piece &expectedPiece) {
    const Position &position = board.get(column, row);
    BOOST_TEST(position.hasPiece);
    BOOST_CHECK_EQUAL(position.getPiece(), expectedPiece);

    std::cout << board;

}



