#include <boost/test/unit_test.hpp>
#include <Board.h>
#include "Row.h"
#include "Column.h"
#include <TestUtils.h>

void positionHas(Board &board, Column column, Row row, const Piece &expectedPiece);

bool test(const Board &board) {
    return board.board == nullptr;
}

const auto isReferenceClean = test;

void assertBasePiecePositions(Board &board);

BOOST_AUTO_TEST_CASE(standard_board) {
    Board board = createStandardBoard();
    assertBasePiecePositions(board);
}

BOOST_AUTO_TEST_CASE(move_board_instance) {
    Board boardA = createStandardBoard();
    Board boardB = std::move(boardA);
    BOOST_TEST(isReferenceClean(boardA));
    assertBasePiecePositions(boardB);
}

BOOST_AUTO_TEST_CASE(move_piece) {
    Board board;
    const Piece &expectedPiece = Piece{PieceColor::WHITE, PieceType::KNIGHT};
    board.set(Column::A, Row::_1, expectedPiece);

    const TakenPiece &takenPiece = board.move(Move{Column::A, Row::_1, Column::H, Row::_8});
    positionHas(board, Column::H, Row::_8, expectedPiece);
    BOOST_CHECK(!board.get(Column::A, Row::_1).hasPiece);
    BOOST_CHECK(!takenPiece.hasPiece);
}

BOOST_AUTO_TEST_CASE(take_piece) {
    Board board;
    const Piece &whiteRook = Piece{PieceColor::WHITE, PieceType::ROOK};
    board.set(Column::A, Row::_1, whiteRook);
    const Piece &blackPond = Piece{PieceColor::BLACK, PieceType::POND};
    board.set(Column::A, Row::_8, blackPond);

    TakenPiece takenPiece = board.move(Move{Column::A, Row::_1, Column::A, Row::_8});
    positionHas(board, Column::A, Row::_8, whiteRook);
    BOOST_CHECK(!board.get(Column::A, Row::_1).hasPiece);

    BOOST_CHECK(takenPiece.hasPiece);
    BOOST_CHECK_EQUAL(takenPiece.piece, blackPond);
}

void positionHas(Board &board, Column column, Row row, const Piece &expectedPiece) {
    const Position &position = board.get(column, row);
    BOOST_TEST(position.hasPiece);
    BOOST_CHECK_EQUAL(position.piece, expectedPiece);
}

void assertBasePiecePositions(Board &board) {
    positionHas(board, A, _1, Piece(PieceColor::WHITE, PieceType::ROOK));
    positionHas(board, B, _1, Piece(PieceColor::WHITE, PieceType::KNIGHT));
    positionHas(board, C, _1, Piece(PieceColor::WHITE, PieceType::BISHOP));
    positionHas(board, D, _1, Piece(PieceColor::WHITE, PieceType::QUEEN));
    positionHas(board, E, _1, Piece(PieceColor::WHITE, PieceType::KING));
    positionHas(board, F, _1, Piece(PieceColor::WHITE, PieceType::BISHOP));
    positionHas(board, G, _1, Piece(PieceColor::WHITE, PieceType::KNIGHT));
    positionHas(board, H, _1, Piece(PieceColor::WHITE, PieceType::ROOK));

    positionHas(board, A, _2, Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, B, _2, Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, C, _2, Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, D, _2, Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, E, _2, Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, F, _2, Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, G, _2, Piece(PieceColor::WHITE, PieceType::POND));
    positionHas(board, H, _2, Piece(PieceColor::WHITE, PieceType::POND));

    positionHas(board, A, _7, Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, B, _7, Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, C, _7, Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, D, _7, Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, E, _7, Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, F, _7, Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, G, _7, Piece(PieceColor::BLACK, PieceType::POND));
    positionHas(board, H, _7, Piece(PieceColor::BLACK, PieceType::POND));

    positionHas(board, A, _8, Piece(PieceColor::BLACK, PieceType::ROOK));
    positionHas(board, B, _8, Piece(PieceColor::BLACK, PieceType::KNIGHT));
    positionHas(board, C, _8, Piece(PieceColor::BLACK, PieceType::BISHOP));
    positionHas(board, D, _8, Piece(PieceColor::BLACK, PieceType::QUEEN));
    positionHas(board, E, _8, Piece(PieceColor::BLACK, PieceType::KING));
    positionHas(board, F, _8, Piece(PieceColor::BLACK, PieceType::BISHOP));
    positionHas(board, G, _8, Piece(PieceColor::BLACK, PieceType::KNIGHT));
    positionHas(board, H, _8, Piece(PieceColor::BLACK, PieceType::ROOK));

    std::initializer_list<Column> allColumns = {A, B, C, D, E, F, G, H};
    std::initializer_list<Row> emptyRows = {_3, _4, _5, _6};

    for (const auto &column : allColumns) {
        for (const auto &row : emptyRows) {
            const Position &position = board.get(column, row);
            BOOST_TEST(!position.hasPiece);
        }
    }
}



