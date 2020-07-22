#ifndef ANYWHERECHESS_GAMECONTROLLER_H
#define ANYWHERECHESS_GAMECONTROLLER_H

#include <ChessGame.h>
#include <PieceToCharMapper.h>
#include <CmdMove.h>

std::ostream &operator<<(std::ostream &os, const ChessGame<std::string> &chessGame);

std::istream &operator>>(std::istream &is, CmdMove &cmdMove);

inline bool invalidColumn(const char &startColumnCharacter);

inline bool invalidRow(const char &startRowCharacter);

inline Column convertToColumn(char aChar);

inline Row convertToRow(char aChar);

#endif //ANYWHERECHESS_GAMECONTROLLER_H
