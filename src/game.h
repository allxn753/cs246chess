#ifndef GAME_H
#define GAME_H
#include <string>
#include "board.h"
#include "piece.h"

class Game {
    Board* theBoard;

    public:
        enum gameState {SETUP, WHITE_TURN, BLACK_TURN, GAME_END};
        Game(Board *);
        void addPiece(char, string);
        void removePiece(string);
        void display();
};

#endif