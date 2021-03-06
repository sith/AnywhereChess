#ifndef ANYWHERECHESS_GAMECONTROLLER_H
#define ANYWHERECHESS_GAMECONTROLLER_H

#include <ChessGame.h>

#include <PieceToCharMapper.h>
#include <CmdMove.h>
#include "CmdPieceType.h"

static const std::string giveUpString{"give up"};
static const std::string drawString{"draw"};

std::istream &operator>>(std::istream &is, CmdMove &cmdMove);

std::istream &operator>>(std::istream &is, CmdPieceType &cmdPieceType);

inline bool invalidColumn(const char &startColumnCharacter);

inline bool invalidRow(const char &startRowCharacter);

inline Column convertToColumn(char aChar);

inline Row convertToRow(char aChar);

#endif //ANYWHERECHESS_GAMECONTROLLER_H
