#ifndef ANYWHERECHESS_CHESSGAMETEST_H
#define ANYWHERECHESS_CHESSGAMETEST_H

#include <boost/test/unit_test.hpp>
#include <ChessGame.h>
#include <PieceColor.h>
#include <PieceType.h>

std::string playerA = "playerA";
std::string playerB = "playerB";

BOOST_AUTO_TEST_CASE(proper_move_switches_player) {

    ChessGame<std::string> chessGame{playerA, playerB};

    MoveResult resultOfPlayerAMove = chessGame.move(Move{E, _2, E, _3});
    BOOST_CHECK_EQUAL(resultOfPlayerAMove.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerB);

    MoveResult resultOfPlayerBMove = chessGame.move(Move{E, _7, E, _6});
    BOOST_CHECK_EQUAL(resultOfPlayerBMove.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerA);
}

BOOST_AUTO_TEST_CASE(inproper_move_does_not_switch_player) {

    ChessGame<std::string> chessGame{playerA, playerB};

    MoveResult resultOfPlayerAMove = chessGame.move(Move{E, _2, E, _8});
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerA);
    BOOST_CHECK_EQUAL(resultOfPlayerAMove.status, MoveStatus::ILLEGAL);
}

BOOST_AUTO_TEST_CASE(invalid_move_no_piece) {
    ChessGame<std::string> chessGame{playerA, playerB};

    MoveResult resultOfPlayerAMove = chessGame.move(Move{E, _4, E, _5});
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
    BOOST_CHECK_MESSAGE(result.takenPiece.hasValue, "Taken value must exist");
    BOOST_CHECK_EQUAL(result.takenPiece.value, blackPond);
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


BOOST_AUTO_TEST_CASE(check) {
    Board board;

    const Piece &whitePond = Piece{PieceColor::WHITE, PieceType::ROOK};
    board.set(A, _1, whitePond);
    const Piece &blackPond = Piece{PieceColor::BLACK, PieceType::KING};
    board.set(B, _8, blackPond);

    ChessGame<std::string> chessGame{playerA, playerB, board};

    const MoveResult &result = chessGame.move(Move{A, _1, B, _1});

    BOOST_CHECK_EQUAL(result.status, MoveStatus::CHECK);
}

BOOST_AUTO_TEST_CASE(check_and_mate) {
    Board board;

    const Piece &whiteRook = Piece{PieceColor::WHITE, PieceType::ROOK};
    board.set(H, _8, whiteRook);
    const Piece &whiteKing = Piece{PieceColor::WHITE, PieceType::KING};
    board.set(A, _3, whiteKing);

    const Piece &blackKing = Piece{PieceColor::BLACK, PieceType::KING};
    board.set(A, _1, blackKing);

    ChessGame<std::string> chessGame{playerA, playerB, board};

    const MoveResult &result = chessGame.move(Move{H, _8, H, _1});

    BOOST_CHECK_EQUAL(result.status, MoveStatus::CHECK_MATE);
    BOOST_CHECK_EQUAL(playerA, chessGame.getCurrentPlayer());

    BOOST_CHECK_EQUAL(chessGame.move({H, _1, H, _2}).status, MoveStatus::NO_MOVE_GAME_OVER);
}

BOOST_AUTO_TEST_CASE(stale_mate) {
    Board board;

    const Piece &whiteRook1 = Piece{PieceColor::WHITE, PieceType::ROOK};
    board.set(H, _2, whiteRook1);
    const Piece &whiteRook2 = Piece{PieceColor::WHITE, PieceType::ROOK};
    board.set(H, _3, whiteRook2);

    const Piece &blackKing = Piece{PieceColor::BLACK, PieceType::KING};
    board.set(A, _1, blackKing);

    ChessGame<std::string> chessGame{playerA, playerB, board};

    const MoveResult &result = chessGame.move(Move{H, _3, B, _3});

    BOOST_CHECK_EQUAL(result.status, MoveStatus::STALE_MATE);
    BOOST_CHECK_EQUAL(playerA, chessGame.getCurrentPlayer());

    BOOST_CHECK_EQUAL(chessGame.move({B, _3, H, _3}).status, MoveStatus::NO_MOVE_GAME_OVER);
}

BOOST_AUTO_TEST_CASE(wrong_piece) {
    Board board;

    board.set(A, _3, Piece{PieceColor::BLACK, PieceType::QUEEN});
    ChessGame<std::string> chessGame{playerA, playerB, board};
    BOOST_CHECK_EQUAL(chessGame.move({A, _3, A, _4}), MoveResult{MoveStatus::ILLEGAL});
}

#endif //ANYWHERECHESS_CHESSGAMETEST_H
