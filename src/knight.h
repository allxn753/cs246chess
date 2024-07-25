#ifndef KNIGHT_H
#define KNIGHT_H

#include "decorator.h"

class Knight : public Decorator {
    public:
        Knight(Piece *piece, int x, int y, unsigned int val, string colour);
};

#endif
