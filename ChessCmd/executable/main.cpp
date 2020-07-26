#include <ChessCmd.h>

int main(int argc, char **argv) {
    ChessCmd chessCmd(std::cin, std::cout, argc, argv);
    chessCmd.run();
    return 0;
}
