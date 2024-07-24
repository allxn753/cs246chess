#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include <string>

class Knight : public Piece {
    bool hasMoved = false;
    public:
        Knight(Board *, char, int, int);
};

#endif
