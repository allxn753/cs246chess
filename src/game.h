#ifndef GAME_H
#define GAME_H
#include <string>
#include "board.h"

class Board;

class Game {
    Board* theBoard;

    public:
        enum gameStates {SETUP, WHITE_TURN, BLACK_TURN, GAME_END};
        Game(Board *);
        Board* getBoard() { return theBoard; };
        bool validMove(string pos1, string pos2);
        bool isThreatened(string pos);
};

#endif
