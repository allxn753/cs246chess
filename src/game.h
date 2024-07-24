#ifndef GAME_H
#define GAME_H
#include <string>
#include "board.h"

class Game {
    Board* theBoard;

    public:
        enum gameState {SETUP, WHITE_TURN, BLACK_TURN, GAME_END};
        Game(Board *);
        bool validMove(string pos1, string pos2);
        bool isThreatened(string pos);
};

#endif
