#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include "player.h"

class Computer : public Player {
    protected:
        unsigned int level = 1;
    
    public:
        Computer(string playerColour, Game* game, unsigned int level);
        void makeMove() const override;
};

#endif
