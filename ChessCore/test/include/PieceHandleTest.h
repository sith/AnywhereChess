//
// Created by Fedorov, Alex on 7/16/20.
//

#ifndef ANYWHERECHESS_PIECEHANDLETEST_H
#define ANYWHERECHESS_PIECEHANDLETEST_H

#include <boost/test/unit_test.hpp>
#include <PieceHandle.h>
#include <set>
#include "MemoryManagmentUtils.h"

BOOST_AUTO_TEST_CASE(piece_handle_stores_and_cleans_object) {
    countOfAllocatedObjectsInFreeSpace = 0;
    Piece *piece = new Piece(PieceColor::WHITE, PieceType::POND);
    {
        PieceHandle pieceHandle{piece};
        BOOST_CHECK_EQUAL(pieceHandle.getValue(), *piece);
    };
    BOOST_CHECK(countOfAllocatedObjectsInFreeSpace == 0);
}

BOOST_AUTO_TEST_CASE(piece_handle_moves) {
    Piece *piece = new Piece(PieceColor::WHITE, PieceType::POND);
    PieceHandle pieceHandleA{piece};
    PieceHandle pieceHandleB = std::move(pieceHandleA);

    BOOST_CHECK_EQUAL(pieceHandleA.value, nullptr);
    BOOST_CHECK_EQUAL(pieceHandleB.value, piece);
}


#endif //ANYWHERECHESS_PIECEHANDLETEST_H
