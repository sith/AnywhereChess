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

        const MoveResult &moveResult = game.move(cmdMove.move);
        if (moveResult.status == MoveStatus::OK) {

            if (moveResult.takenPiece.hasPiece) {
                ostream << "Piece taken: " << moveResult.takenPiece.piece<<'\n';
            }

            ostream << game;
        } else {
            printInvalidMessage(game, "Invalid move!");
        }
    }
}

void ChessCmd::printInvalidMessage(const ChessGame<std::string> &game, const char *message) const {
    ostream << message << '\n';
    ostream << game.getCurrentPlayer() << '>';
}

