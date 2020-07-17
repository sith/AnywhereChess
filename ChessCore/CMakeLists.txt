cmake_minimum_required(VERSION 3.16)
project(ChessCore)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_library(ChessCore
        src/Board.cpp
        src/Position.cpp
        src/Piece.cpp
        src/Move.cpp
        src/BoardBuilder.cpp
        src/ChessRuleService.cpp include/PieceHandle.h src/MoveResult.cpp src/PieceHandle.cpp)
target_include_directories(ChessCore PUBLIC include)

add_executable(ChessCore_tests test/include/BoardTest.h test/TestUtils.cpp test/ChessCoreTests.cpp test/include/PondMoveTest.h)
target_include_directories(ChessCore_tests PUBLIC test/include)
target_link_libraries(ChessCore_tests PRIVATE ${Boost_LIBRARIES})
target_link_libraries(ChessCore_tests PRIVATE ChessCore)


