#ifndef QUEEN_H
#define QUEEN_H

#include "decorator.h"

class Queen : public Decorator {
    public:
        Queen(Piece *piece, int x, int y, unsigned int val, string colour);
};

#endif
