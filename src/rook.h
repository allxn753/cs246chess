#ifndef ROOK_H
#define ROOK_H

#include "decorator.h"

class Rook : public Decorator {
    public:
        Rook(Piece *piece, int x, int y, unsigned int val, string colour);
};

#endif
