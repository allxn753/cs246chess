#ifndef GAME_H
#define GAME_H
#include <string>
#include "board.h"

class Board;

class Game {
    Board* theBoard;

    public:
        enum gameStates {SETUP, WHITE_TURN, BLACK_TURN, GAME_END};
        Game();
        Game(Board *);
        Board* getBoard() { return theBoard; };
        vector<int> convertPosition(string pos);
        bool validMove(string pos1, string pos2);
        bool isPathObstructed(vector<int> coord1, int dX, int dY);
        bool isThreatened(string pos);
};

#endif
