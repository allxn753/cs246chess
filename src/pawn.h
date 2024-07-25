#ifndef PAWN_H
#define PAWN_H

#include "decorator.h"

class Pawn : public Decorator {
    public:
        Pawn(Piece *piece, int x, int y, unsigned int val, string colour);
};

#endif
