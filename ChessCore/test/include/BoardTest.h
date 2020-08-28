#include <boost/test/unit_test.hpp>
#include <Board.h>
#include "Row.h"
#include "Column.h"
#include <ChessCoreIO.h>
#include <MemoryManagmentUtils.h>
#include <boost/format.hpp>

void positionHas(Board &board, Column column, Row row, const Piece &expectedPiece);

bool test(const Board &board) {
    return board.array == nullptr;
}

const auto isReferenceClean = test;

void assertBasePiecePositions(Board &board);

void assertCopiedPieces(Board &boardA, Board &boardB);

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


BOOST_AUTO_TEST_CASE(copy_board_instance) {
    Board boardA = createStandardBoard();
    Board boardB = Board{boardA};

    assertBasePiecePositions(boardA);
    assertBasePiecePositions(boardB);
    assertCopiedPieces(boardA, boardB);
}

BOOST_AUTO_TEST_CASE(copy_assignment_board_instance) {
    {
        countOfAllocatedObjectsInFreeSpace = 0;
        Board boardA = createStandardBoard();
        Board boardB = createStandardBoard();
        boardA = boardB;

        assertBasePiecePositions(boardA);
        assertBasePiecePositions(boardB);
        assertCopiedPieces(boardA, boardB);
    }

    BOOST_CHECK_EQUAL(countOfAllocatedObjectsInFreeSpace, 0);
}

BOOST_AUTO_TEST_CASE(no_self_copy_assignment_of_the_board) {
    Board boardA = createStandardBoard();
    boardA = boardA;

    assertBasePiecePositions(boardA);
}

BOOST_AUTO_TEST_CASE(move_piece) {
    Board board;
    const Piece &expectedPiece = Piece{PieceColor::WHITE, PieceType::KNIGHT};
    board.set(Column::A, Row::_1, expectedPiece);

    const TakenPiece &takenPiece = board.move(Move{Column::A, Row::_1, Column::H, Row::_8});
    positionHas(board, Column::H, Row::_8, expectedPiece);
    BOOST_CHECK(!board.get(Column::A, Row::_1).hasValue);
    BOOST_CHECK(!takenPiece.hasValue);
}

BOOST_AUTO_TEST_CASE(take_piece) {
    countOfAllocatedObjectsInFreeSpace = 0;
    {
        Board board;
        const Piece &whiteRook = Piece{PieceColor::WHITE, PieceType::ROOK};
        board.set(Column::A, Row::_1, whiteRook);
        const Piece &blackPond = Piece{PieceColor::BLACK, PieceType::POND};
        board.set(Column::A, Row::_8, blackPond);


        TakenPiece takenPiece = board.move(Move{Column::A, Row::_1, Column::A, Row::_8});
        positionHas(board, Column::A, Row::_8, whiteRook);
        BOOST_CHECK(!board.get(Column::A, Row::_1).hasValue);

        BOOST_CHECK(takenPiece.hasValue);
        BOOST_CHECK_EQUAL(takenPiece.value, blackPond);
    }
    BOOST_CHECK_EQUAL(countOfAllocatedObjectsInFreeSpace, 0);
}

BOOST_AUTO_TEST_CASE(has_piece) {
    Board board = createStandardBoard();

    BOOST_CHECK(board.hasPieceAt(E, _2));
    BOOST_CHECK(!board.hasPieceAt(E, _3));
}

BOOST_AUTO_TEST_CASE(remove_piece_from_position) {
    Board board;
    countOfAllocatedObjectsInFreeSpace = 0;
    {
        board.set(A, _1, {WHITE, POND});
        board.remove(A, _1);
        BOOST_CHECK(!board.hasPieceAt(A, _1));
    }
    BOOST_CHECK_EQUAL(countOfAllocatedObjectsInFreeSpace, 0);
}

BOOST_AUTO_TEST_CASE(boards_are_equal) {
    Board boardA = createStandardBoard();
    Board boardB = createStandardBoard();

    BOOST_CHECK_EQUAL(boardA, boardB);
}

BOOST_AUTO_TEST_CASE(boards_are_not_equal) {
    Board boardA = createStandardBoard();
    Board boardB;

    BOOST_CHECK_NE(boardA, boardB);
}


void positionHas(Board &board, Column column, Row row, const Piece &expectedPiece) {
    const Position &position = board.get(column, row);
    BOOST_TEST(position.hasValue);
    BOOST_CHECK_EQUAL(position.value, expectedPiece);
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
            BOOST_TEST(!position.hasValue);
        }
    }
}

void assertCopiedPieces(Board &boardA, Board &boardB) {
    for (int i = Column::A; i <= Column::H; i++) {
        for (int j = Row::_1; j <= Row::_8; ++j) {
            Column column = (Column) i;
            Row row = (Row) j;

            Position positionFromBoardA = boardA.get(column, row);
            Position positionFromBoardB = boardB.get(column, row);

            BOOST_CHECK_MESSAGE(positionFromBoardA.hasValue == positionFromBoardB.hasValue,
                                boost::format("Piece availability matches for %1%%2%") % column % row);
            if (positionFromBoardA.hasValue) {
                BOOST_CHECK_MESSAGE(&positionFromBoardA.value != &positionFromBoardB.value,
                                    boost::format("References must be different for %1%%2%") % column % row);
            }

        }
    }
}



