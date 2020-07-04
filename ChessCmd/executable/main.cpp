#include <ChessCmd.h>

int main(int argc, char **argv) {
    ChessCmd chessCmd(std::cin, std::cout);
    chessCmd.run();
    return 0;
}

