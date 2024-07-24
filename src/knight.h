#ifndef KNIGHT_H
#define KNIGHT_H

#include "decorator.h"
#include <string>

class Knight : public Decorator {
    bool hasMoved = false;
    public:
        Knight(Board *, char, int, int);
};

#endif
