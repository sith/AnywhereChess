cmake_minimum_required(VERSION 3.16)
project(ChessCore)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_library(ChessCore
        src/Board.cpp
        src/Position.cpp
        src/Piece.cpp
        src/Move.cpp
        src/ChessRuleService.cpp
        src/MoveResult.cpp
        )
target_include_directories(ChessCore PUBLIC include)

add_executable(ChessCore_tests
        test/ChessCoreTests.cpp
        )
target_include_directories(ChessCore_tests PUBLIC test/include)
target_link_libraries(ChessCore_tests PRIVATE ${Boost_LIBRARIES})
target_link_libraries(ChessCore_tests PRIVATE ChessCore)
target_link_libraries(ChessCore_tests PRIVATE ChessCoreIO)


