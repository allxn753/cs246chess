#ifndef PAWN_H
#define PAWN_H

#include "decorator.h"
#include <string>

class Pawn : public Decorator {
    bool hasMoved = false;
    public:
        Pawn(Board *, char, int, int);
};

#endif
