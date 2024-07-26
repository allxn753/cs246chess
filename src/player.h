#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "game.h"

class Player : public Game {
    protected:
        string playerColour;
        Game* game;

    public:
        Player(string playerColour, Game* game);
        virtual void makeMove() const = 0;
        Board* getBoard();
        virtual ~Player();
};

#endif