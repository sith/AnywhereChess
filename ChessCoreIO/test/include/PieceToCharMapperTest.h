#include <boost/test/unit_test.hpp>
#include <PieceToCharMapper.h>
#include <Piece.h>
#include <PieceColor.h>
#include <PieceType.h>
#include <Optional.h>

BOOST_AUTO_TEST_CASE(maps_white_pond) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::POND);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u2659");
}

BOOST_AUTO_TEST_CASE(maps_white_rook) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::ROOK);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u2656");
}

BOOST_AUTO_TEST_CASE(maps_white_knight) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::KNIGHT);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u2658");
}

BOOST_AUTO_TEST_CASE(maps_white_bishop) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::BISHOP);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u2657");
}

BOOST_AUTO_TEST_CASE(maps_white_queen) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::QUEEN);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u2655");
}

BOOST_AUTO_TEST_CASE(maps_white_king) {
    const Piece piece = Piece(PieceColor::WHITE, PieceType::KING);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u2654");
}


BOOST_AUTO_TEST_CASE(maps_black_pond) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::POND);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u265F");
}

BOOST_AUTO_TEST_CASE(maps_black_rook) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::ROOK);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u265C");
}

BOOST_AUTO_TEST_CASE(maps_black_knight) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::KNIGHT);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u265E");
}

BOOST_AUTO_TEST_CASE(maps_black_bishop) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::BISHOP);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u265D");
}

BOOST_AUTO_TEST_CASE(maps_black_queen) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::QUEEN);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u265B");
}

BOOST_AUTO_TEST_CASE(maps_black_king) {
    const Piece piece = Piece(PieceColor::BLACK, PieceType::KING);
    std::string aChar = mapPositionToChar(Optional(piece));
    BOOST_CHECK_EQUAL(aChar, "\u265A");
}


