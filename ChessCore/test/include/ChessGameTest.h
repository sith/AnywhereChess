#ifndef ANYWHERECHESS_CHESSGAMETEST_H
#define ANYWHERECHESS_CHESSGAMETEST_H

#include <boost/test/unit_test.hpp>
#include <ChessGame.h>
#include <PieceColor.h>
#include <PieceType.h>
#include <Types.h>

std::string playerA = "playerA";
std::string playerB = "playerB";

BOOST_AUTO_TEST_CASE(proper_move_switches_player) {

    ChessGame<std::string> chessGame{playerA, playerB};

    MoveResult resultOfPlayerAMove = chessGame.move(Move{E, _2, E, _3});
    BOOST_CHECK_EQUAL(resultOfPlayerAMove.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::IN_PROGRESS);
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerB);

    MoveResult resultOfPlayerBMove = chessGame.move(Move{E, _7, E, _6});
    BOOST_CHECK_EQUAL(resultOfPlayerBMove.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerA);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::IN_PROGRESS);
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

    board.set({H, _8}, {PieceColor::BLACK, PieceType::KING});

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

    BOOST_CHECK_EQUAL(result.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::CHECK);
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

    BOOST_CHECK_EQUAL(result.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::CHECK_AND_MATE);
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

    BOOST_CHECK_EQUAL(result.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::STALE_MATE);
    BOOST_CHECK_EQUAL(playerA, chessGame.getCurrentPlayer());

    BOOST_CHECK_EQUAL(chessGame.move({B, _3, H, _3}).status, MoveStatus::NO_MOVE_GAME_OVER);
}


BOOST_AUTO_TEST_CASE(replace_white_pond_by_queen) {
    Board board;
    board.set({H, _7}, {PieceColor::BLACK, PieceType::KING});

    const Piece &whitePond = Piece{PieceColor::WHITE, PieceType::POND};
    board.set(A, _7, whitePond);

    ChessGame<std::string> chessGame{playerA, playerB, board};

    const MoveResult &result = chessGame.move(Move{A, _7, A, _8});

    BOOST_CHECK_EQUAL(result.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::PROMOTION);
    BOOST_CHECK_EQUAL(playerA, chessGame.getCurrentPlayer());

    PromotionResult promotionResult = chessGame.promote(PieceType::QUEEN);

    BOOST_CHECK_EQUAL(promotionResult, PromotionResult::SUCCESSFUL);

    Position expectedPosition{{WHITE, QUEEN}};
    Position actualPiece = chessGame.getBoard().get({A, _8});
    BOOST_CHECK_EQUAL(actualPiece, expectedPosition);
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerB);
}


BOOST_AUTO_TEST_CASE(replace_black_pond_by_queen) {
    Board board;
    board.set({B, _7}, {PieceColor::WHITE, PieceType::KING});

    const Piece &whitePond = Piece{PieceColor::BLACK, PieceType::POND};
    board.set(A, _2, whitePond);

    ChessGame<std::string> chessGame{playerA, playerB, board};
    chessGame.move({B, _7, B, _6});

    const MoveResult &result = chessGame.move(Move{A, _2, A, _1});

    BOOST_CHECK_EQUAL(result.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::PROMOTION);
    BOOST_CHECK_EQUAL(playerB, chessGame.getCurrentPlayer());

    PromotionResult promotionResult = chessGame.promote(PieceType::QUEEN);

    BOOST_CHECK_EQUAL(promotionResult, PromotionResult::SUCCESSFUL);

    Position expectedPosition{{BLACK, QUEEN}};
    Position actualPiece = chessGame.getBoard().get({A, _1});
    BOOST_CHECK_EQUAL(actualPiece, expectedPosition);
    BOOST_CHECK_EQUAL(chessGame.getCurrentPlayer(), playerA);
}


BOOST_AUTO_TEST_CASE(promotion_with_taken_piece) {
    Board board;
    board.set({H, _7}, {PieceColor::BLACK, PieceType::KING});

    Piece blackBishop = Piece{PieceColor::BLACK, PieceType::BISHOP};
    board.set({B, _8}, blackBishop);
    board.set(A, _7, Piece{PieceColor::WHITE, PieceType::POND});

    ChessGame<std::string> chessGame{playerA, playerB, board};


    const MoveResult &result = chessGame.move(Move{A, _7, B, _8});
    MoveResult expectedMoveResult = MoveResult{MoveStatus::OK, TakenPiece{blackBishop}};
    BOOST_CHECK_EQUAL(result, expectedMoveResult);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::PROMOTION);
}

BOOST_AUTO_TEST_CASE(promotion_with_check) {
    Board board;
    board.set({H, _8}, {PieceColor::BLACK, PieceType::KING});

    board.set(A, _7, Piece{PieceColor::WHITE, PieceType::POND});

    ChessGame<std::string> chessGame{playerA, playerB, board};

    const MoveResult &result = chessGame.move(Move{A, _7, A, _8});
    BOOST_CHECK_EQUAL(result.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::PROMOTION);

    chessGame.promote(PieceType::ROOK);

    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::CHECK);
}

BOOST_AUTO_TEST_CASE(promotion_with_check_mate) {
    Board board;
    board.set({H, _8}, {PieceColor::BLACK, PieceType::KING});

    board.set(A, _7, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(B, _7, Piece{PieceColor::WHITE, PieceType::ROOK});

    ChessGame<std::string> chessGame{playerA, playerB, board};

    const MoveResult &result = chessGame.move(Move{A, _7, A, _8});
    BOOST_CHECK_EQUAL(result.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::PROMOTION);

    chessGame.promote(PieceType::ROOK);

    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::CHECK_AND_MATE);
}

BOOST_AUTO_TEST_CASE(promotion_with_stale_mate) {
    Board board;
    board.set({H, _7}, {PieceColor::BLACK, PieceType::KING});

    board.set(A, _7, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(B, _6, Piece{PieceColor::WHITE, PieceType::ROOK});
    board.set(G, _1, Piece{PieceColor::WHITE, PieceType::ROOK});

    ChessGame<std::string> chessGame{playerA, playerB, board};

    const MoveResult &result = chessGame.move(Move{A, _7, A, _8});
    BOOST_CHECK_EQUAL(result.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::PROMOTION);

    chessGame.promote(PieceType::ROOK);

    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::STALE_MATE);
}

BOOST_AUTO_TEST_CASE(illegal_piece_for_promotion) {
    Board board;
    board.set({H, _7}, {PieceColor::BLACK, PieceType::KING});

    board.set(A, _7, Piece{PieceColor::WHITE, PieceType::POND});

    ChessGame<std::string> chessGame{playerA, playerB, board};

    const MoveResult &result = chessGame.move(Move{A, _7, A, _8});
    BOOST_CHECK_EQUAL(result.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::PROMOTION);

    BOOST_CHECK_EQUAL(chessGame.promote(PieceType::POND), PromotionResult::FAILED);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::PROMOTION);

    BOOST_CHECK_EQUAL(chessGame.promote(PieceType::KING), PromotionResult::FAILED);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::PROMOTION);
}


BOOST_AUTO_TEST_CASE(no_move_if_in_promotion) {

    Board board;
    board.set({H, _7}, {PieceColor::BLACK, PieceType::KING});

    board.set(A, _7, Piece{PieceColor::WHITE, PieceType::POND});
    board.set(A, _1, Piece{PieceColor::WHITE, PieceType::POND});

    ChessGame<std::string> chessGame{playerA, playerB, board};

    MoveResult result1 = chessGame.move(Move{A, _7, A, _8});
    BOOST_CHECK_EQUAL(result1.status, MoveStatus::OK);
    BOOST_CHECK_EQUAL(chessGame.getState(), ChessGameState::PROMOTION);

    MoveResult result2 = chessGame.move(Move{A, _1, A, _2});
    BOOST_CHECK_EQUAL(result2.status, MoveStatus::ILLEGAL);
}

BOOST_AUTO_TEST_CASE(no_promotion_if_move) {
    Board board;
    board.set({H, _7}, {PieceColor::BLACK, PieceType::KING});

    board.set(A, _7, Piece{PieceColor::WHITE, PieceType::POND});

    ChessGame<std::string> chessGame{playerA, playerB, board};

    PromotionResult result = chessGame.promote(ROOK);
    BOOST_CHECK_EQUAL(result, PromotionResult::FAILED);
}

BOOST_AUTO_TEST_CASE(wrong_piece) {
    Board board;

    board.set(A, _3, Piece{PieceColor::BLACK, PieceType::QUEEN});
    ChessGame<std::string> chessGame{playerA, playerB, board};
    BOOST_CHECK_EQUAL(chessGame.move({A, _3, A, _4}), MoveResult{MoveStatus::ILLEGAL});
}

#endif //ANYWHERECHESS_CHESSGAMETEST_H
