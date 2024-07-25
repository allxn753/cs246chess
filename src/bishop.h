#ifndef BISHOP_H
#define BISHOP_H

#include "decorator.h"

class Bishop : public Decorator {
    public:
        Bishop(Piece *piece, int x, int y, unsigned int val, string colour);
};

#endif
