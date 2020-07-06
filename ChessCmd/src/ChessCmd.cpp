#include <Board.h>
#include <PieceToCharMapper.h>
#include "ChessCmd.h"

#include <boost/program_options.hpp>

namespace po = boost::program_options;

void ChessCmd::run() {
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help", "produce help message")
            ("player1", po::value<std::string>()->default_value("A"), "name of first player")
            ("player2", po::value<std::string>()->default_value("B"), "name of second player");

    po::variables_map vm;
    po::store(po::command_line_parser (argc, argv).options(desc).allow_unregistered().run(), vm);
    po::notify(vm);

    if (vm.count("help")) {
        ostream << desc << "\n";
        return;
    }

    std::string player1 = vm["player1"].as<std::string>();
    std::string player2 = vm["player2"].as<std::string>();

    ostream << "Player 1: " << player1 << '\n';
    ostream << "Player 2: " << player2 << '\n';

    ChessGame chessGame{};
    ostream << chessGame;
}

ChessCmd::ChessCmd(std::istream &istream, std::ostream &ostream, int argc, char **argv) : istream(istream),
                                                                                          ostream(ostream),
                                                                                          argc(argc),
                                                                                          argv(argv) {

}

std::ostream &operator<<(std::ostream &os, const ChessGame &chessGame) {
    const Board &board = chessGame.getBoard();
    os << " abcdefgh \n";

    for (char row = '8'; row >= '1'; row--) {
        os << row;
        for (char column = 'a'; column <= 'h'; column++) {
            const Position &position = board.get(column, row);
            os << mapPositionToChar(position);
        }
        os << row << '\n';
    }
    os << " abcdefgh \n";
    return os;
}

