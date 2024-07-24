#ifndef KING_H
#define KING_H

#include "decorator.h"
#include <string>

class King : public Decorator {
    bool hasMoved = false;
    public:
        King(Board *, char, int, int);
};

#endif
