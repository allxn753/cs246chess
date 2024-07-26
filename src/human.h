#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include "player.h"

class Human : public Player {
    
    public:
        Human(string playerColour, Game* game);
        void makeMove() const override;
};

#endif
