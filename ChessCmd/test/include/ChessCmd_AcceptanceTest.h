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

BOOST_AUTO_TEST_CASE(show_chess_board_on_startup_with_user_names, *utf::timeout(5)) {
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());

        char *args[] = {
                (char *) "app_path",
                (char *) "--player1",
                (char *) "foo",
                (char *) "--player2",
                (char *) "boo"
        };

        ChessCmd chessCmd(std::cin, std::cout, 5, args);
        std::thread threadObj(&ChessCmd::run, chessCmd);
        threadObj.join();
    }
    BOOST_CHECK(output.is_equal(
            "Player 1: foo\n"
            "Player 2: boo\n"
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

BOOST_AUTO_TEST_CASE(show_chess_board_on_startup_with_default_user_names, *utf::timeout(5)) {
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());

        char *args[] = {
                (char *) "app_path"
        };

        ChessCmd chessCmd(std::cin, std::cout, 1, args);
        std::thread threadObj(&ChessCmd::run, chessCmd);
        threadObj.join();
    }
    BOOST_CHECK(output.is_equal(
            "Player 1: A\n"
            "Player 2: B\n"
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

BOOST_AUTO_TEST_CASE(show_chess_board_on_startup_and_ignore_unrecognized_params, *utf::timeout(5)) {
    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard(output.rdbuf());

        char *args[] = {
                (char *) "app_path",
                (char *) "--hello_world"
        };

        ChessCmd chessCmd(std::cin, std::cout, 2, args);
        std::thread threadObj(&ChessCmd::run, chessCmd);
        threadObj.join();
    }
    BOOST_CHECK(output.is_equal(
            "Player 1: A\n"
            "Player 2: B\n"
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


