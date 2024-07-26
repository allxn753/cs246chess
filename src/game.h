#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>
#include "board.h"

using namespace std;

class Game {
    public:
        enum gameState {SETUP, WHITE_TURN, BLACK_TURN, GAME_END};
    private:
        Board* theBoard;
        gameState state;
    public:        
        Game();
        Game(Board *);
        Board* getBoard() { return theBoard; };
        void reset();
        bool validMove(string pos1, string pos2);
        bool isPathObstructed(vector<int> coord1, int dX, int dY);
        bool isThreatened(string pos);
        void nextTurn();
        bool isInCheck();
};

#endif
