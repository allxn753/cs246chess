#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "game.h"

class Player {
    protected:
        string playerColour;
        Game* game;
        unsigned int score = 0;

    public:
        Player(string playerColour, Game* game);
        virtual void makeMove() const = 0;
        Board* getBoard();
        int getScore() {return score;};
        virtual ~Player();
};

#endif
