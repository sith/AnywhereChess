cmake_minimum_required(VERSION 3.16)
project(ChessCoreIO)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_library(ChessCoreIO src/ChessCoreIO.cpp src/PieceToCharMapper.cpp)
target_include_directories(ChessCoreIO PUBLIC include)
target_link_libraries(ChessCoreIO PRIVATE ${Boost_LIBRARIES})
target_link_libraries(ChessCoreIO PRIVATE ChessCore)


add_executable(ChessCoreIO_tests test/ChessCoreIOTests.cpp)
target_include_directories(ChessCoreIO_tests PRIVATE test/include)
target_link_libraries(ChessCoreIO_tests PRIVATE ${Boost_LIBRARIES})
target_link_libraries(ChessCoreIO_tests PRIVATE ChessCoreIO)
target_link_libraries(ChessCoreIO_tests PRIVATE ChessCore)
