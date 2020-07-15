add_executable(ChessCmd_tests ChessCmdTests.cpp include/PondMoveTest.h)
target_include_directories(ChessCmd_tests PUBLIC include)
target_link_libraries(ChessCmd_tests PUBLIC ChessCmd_library)
target_link_libraries(ChessCmd_tests PRIVATE ${Boost_LIBRARIES})


enable_testing()
add_test(ChessCmd_tests ChessCmd_tests)
