cmake_minimum_required(VERSION 3.16)
project(ChessCmd)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED COMPONENTS unit_test_framework program_options iostreams REQUIRED)

add_executable(ChessCmd_exec executable/main.cpp)
target_link_libraries(ChessCmd_exec PRIVATE ChessCmd_library)

add_library(ChessCmd_library
        src/ChessCmd.cpp
        src/PieceToCharMapper.cpp
        src/GameController.cpp
        )
target_include_directories(ChessCmd_library PUBLIC src/include)
target_link_libraries(ChessCmd_library PUBLIC ChessCore)
target_link_libraries(ChessCmd_library PRIVATE ${Boost_LIBRARIES})
target_include_directories(ChessCmd_library PRIVATE ${Boost_INCLUDE_DIR})
target_link_directories(ChessCmd_library PRIVATE ${Boost_LIBRARY_DIR})

add_subdirectory(test)

