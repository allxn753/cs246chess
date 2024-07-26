#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "game.h"

class Player : public Game {
    protected:
        string playerColour;
        Game* game;
        float score = 0;

    public:
        Player(string playerColour, Game* game);
        virtual void makeMove() const = 0;
        Board* getBoard();
        float getScore() {return score;};
        void addScore(float p) {score += p;};
        virtual ~Player();
};

#endif
