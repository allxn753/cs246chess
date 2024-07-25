#ifndef KING_H
#define KING_H

#include "decorator.h"

class King : public Decorator {
    public:
        King(Piece *piece, int x, int y, unsigned int val, string colour);
};

#endif
