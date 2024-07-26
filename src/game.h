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
        bool check = false;
    public:        
        Game();
        Game(Board *);
        Board* getBoard() { return theBoard; };
        void reset();
        bool validMove(string pos1, string pos2);
        bool isPathObstructed(vector<int> coord1, int dX, int dY);
        int isCastling(string pos1, string pos2);
        bool isEnPassant(string pos1, string pos2);
        bool isSkipping(string pos1, string pos2);
        bool isPromoting(string pos1, string pos2);
        bool isThreatened(string pos);
        void nextTurn();
        void updateCheck(string colour);
        bool getCheck() {return check;}
        bool isCheckmate(string colour);
        string whoseTurn();
};

#endif
