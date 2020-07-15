//
// Created by Fedorov, Alex on 7/13/20.
//

#ifndef ANYWHERECHESS_MOVE_H
#define ANYWHERECHESS_MOVE_H


class Move {
    const char startColumn;
    const char startRow;
    const char endColumn;
    const char endRow;
public:
    Move(char startColumn, char startRow,  char endColumn,  char endRow);
};


#endif //ANYWHERECHESS_MOVE_H
