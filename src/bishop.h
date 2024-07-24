#ifndef BISHOP_H
#define BISHOP_H

#include "decorator.h"

class Bishop : public Decorator {
    public:
        Bishop(Board *, char, int, int);
};

#endif
