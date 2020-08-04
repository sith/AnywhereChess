cmake_minimum_required(VERSION 3.16)
project(ChessCoreIO)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_library(ChessCoreIO src/ChessCoreIO.cpp)
target_include_directories(ChessCoreIO PUBLIC include)
target_link_libraries(ChessCoreIO PRIVATE ${Boost_LIBRARIES})
target_link_libraries(ChessCoreIO PRIVATE ChessCore)