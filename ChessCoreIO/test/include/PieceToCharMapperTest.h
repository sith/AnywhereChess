#include <boost/test/unit_test.hpp>
#include <PieceToCharMapper.h>
#include <Piece.h>
#include <PieceColor.h>
#include <PieceType.h>
#include <PieceOptional.h>

BOOST_AUTO_TEST_CASE(maps_white_pond) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::POND);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'P');
}

BOOST_AUTO_TEST_CASE(maps_white_rook) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::ROOK);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'R');
}

BOOST_AUTO_TEST_CASE(maps_white_knight) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::KNIGHT);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'N');
}

BOOST_AUTO_TEST_CASE(maps_white_bishop) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::BISHOP);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'B');
}

BOOST_AUTO_TEST_CASE(maps_white_queen) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::QUEEN);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'Q');
}

BOOST_AUTO_TEST_CASE(maps_white_king) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::KING);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'K');
}


BOOST_AUTO_TEST_CASE(maps_black_pond) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::POND);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'p');
}

BOOST_AUTO_TEST_CASE(maps_black_rook) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::ROOK);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'r');
}

BOOST_AUTO_TEST_CASE(maps_black_knight) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::KNIGHT);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'n');
}

BOOST_AUTO_TEST_CASE(maps_black_bishop) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::BISHOP);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'b');
}

BOOST_AUTO_TEST_CASE(maps_black_queen) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::QUEEN);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'q');
}

BOOST_AUTO_TEST_CASE(maps_black_king) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::KING);
    char aChar = mapPositionToChar(PieceOptional(piece));
    BOOST_CHECK_EQUAL(aChar, 'k');
}


