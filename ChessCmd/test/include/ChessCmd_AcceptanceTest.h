#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <boost/program_options/config.hpp>
#include <thread>
#include <ChessCmd.h>

namespace utf = boost::unit_test;

struct cout_redirect {
    cout_redirect(std::streambuf *new_buffer)
            : old(std::cout.rdbuf(new_buffer)) {}

    ~cout_redirect() {
        std::cout.rdbuf(old);
    }

private:
    std::streambuf *old;
};

BOOST_AUTO_TEST_CASE(show_chess_board_on_startup, *utf::timeout(5)) {
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());

        ChessCmd chessCmd(std::cin, std::cout);
        std::thread threadObj(&ChessCmd::run, chessCmd);
        threadObj.join();
    }
    BOOST_CHECK(output.is_equal(
            " abcdefgh \n"
            "8rnbqkbnr8\n"
            "7pppppppp7\n"
            "6........6\n"
            "5........5\n"
            "4........4\n"
            "3........3\n"
            "2PPPPPPPP2\n"
            "1RNBQKBNR1\n"
            " abcdefgh \n"
    ));
}
