#include <Board.h>
#include "ChessCmd.h"
#include "GameController.h"
#include <ChessCoreIO.h>
#include <boost/program_options.hpp>

namespace po = boost::program_options;

void ChessCmd::run() {
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help", "produce help message")
            ("player1", po::value<std::string>()->default_value("A"), "name of first player")
            ("player2", po::value<std::string>()->default_value("B"), "name of second player")
            ("noGame", po::bool_switch(), "skips the game. Is used for testing purpose");

    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).allow_unregistered().run(), vm);
    po::notify(vm);


    if (vm.count("help")) {
        ostream << desc << "\n";
        return;
    }

    std::string player1 = vm["player1"].as<std::string>();
    std::string player2 = vm["player2"].as<std::string>();

    ostream << "Player 1: " << player1 << '\n';
    ostream << "Player 2: " << player2 << '\n';

    ChessGame<std::string> chessGame{player1, player2};
    ostream << chessGame;

    if (vm["noGame"].as<bool>()) {
        return;
    }

    playGame(chessGame);
}

ChessCmd::ChessCmd(std::istream &istream, std::ostream &ostream, int argc, char **argv) : istream(istream),
                                                                                          ostream(ostream),
                                                                                          argc(argc),
                                                                                          argv(argv) {
}


void ChessCmd::playGame(ChessGame<std::string> &game) {
    while (true) {
        CmdMove cmdMove;
        istream >> cmdMove;

        if (!cmdMove.validFormat) {
            printInvalidMessage(game, "Invalid format!");
            continue;
        }

        if (cmdMove.giveUp) {
            ostream << "Player " << game.getCurrentPlayer() << " gave up!\n";
            return;
        }

        if (cmdMove.draw) {
            ostream << "Player " << game.getCurrentPlayer()
                    << " suggests draw. Type 'draw' to accept, or press Enter\n";
            CmdMove acceptDraw;
            istream >> acceptDraw;
            if (acceptDraw.validFormat && acceptDraw.draw) {
                ostream << "Draw!";

                return;
            } else {
                ostream << game.getCurrentPlayer() << ">";
                continue;
            }
        }

        const MoveResult &moveResult = game.move(cmdMove.move);

        switch (moveResult.status) {
            case MoveStatus::OK: {
                if (moveResult.takenPiece.hasValue) {
                    ostream << "Piece taken: " << moveResult.takenPiece.value << '\n';
                }

                ostream << game;

                const ChessGameState &state = game.getState();

                if (state == ChessGameState::PROMOTION) {
                    PromotionResult result = PromotionResult::FAILED;
                    do {
                        ostream << '\n' << "Promote(rook,knight,bishop,queen)>";
                        CmdPieceType cmdPieceType;
                        istream >> cmdPieceType;
                        if (!cmdPieceType.validFormat) {
                            ostream << "Invalid piece!\n";
                            continue;
                        }
                        result = game.promote(cmdPieceType.pieceType);
                        if (result == PromotionResult::FAILED) {
                            ostream << "Only rook, knight, bishop or queen are available for promotion!\n";
                        }
                    } while (result == PromotionResult::FAILED);

                } else {
                    switch (state) {
                        case ChessGameState::CHECK:
                            ostream << "Check! " << game.getCurrentPlayer() << "\n" << game;
                            break;
                        case ChessGameState::CHECK_AND_MATE:
                            ostream << "Check and Mate!\n";
                            ostream << "Winner: " << game.getCurrentPlayer() << "\n";
                            return;
                        case ChessGameState::STALE_MATE:
                            ostream << "Stale Mate!\n";
                            return;
                        default:
                            break;
                    }
                }
                break;
            }
            case MoveStatus::ILLEGAL:
                printInvalidMessage(game, "Invalid move!");
                break;
            case MoveStatus::NO_MOVE_GAME_OVER:
                return;
        }
    }
}

void ChessCmd::printInvalidMessage(const ChessGame<std::string> &game, const char *message) const {
    ostream << message << '\n';
    ostream << game.getCurrentPlayer() << '>';
}

