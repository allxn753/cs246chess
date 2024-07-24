#ifndef GAME_H
#define GAME_H
#include <string>
#include "board.h"
#include "piece.h"

class Game {
    Board* theBoard;
    public:
        Game(Board *);
        void addPiece(char, string);
        void display();
};

#endif