cmake_minimum_required(VERSION 3.16)
project(ChessCmd)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS program_options)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

add_executable(ChessCmd_exec executable/main.cpp)
target_link_libraries(ChessCmd_exec PRIVATE ChessCmd_library)
target_link_libraries(ChessCmd_exec PRIVATE ${Boost_LIBRARIES})

add_library(ChessCmd_library src/ChessCmd.cpp src/PieceToCharMapper.cpp)
target_include_directories(ChessCmd_library PUBLIC src/include)
target_link_libraries(ChessCmd_library PUBLIC ChessCore)


add_executable(ChessCmd_tests test/ChessCmdTests.cpp)
target_include_directories(ChessCmd_tests PUBLIC test/include)
target_link_libraries(ChessCmd_tests PUBLIC ChessCmd_library)
target_link_libraries(ChessCmd_tests PRIVATE ${Boost_LIBRARIES})
