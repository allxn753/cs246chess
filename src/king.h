#ifndef KING_H
#define KING_H

#include "piece.h"
#include <string>

class King : public Piece {
    bool hasMoved = false;
    public:
        King(Board *, char, int, int);
};

#endif
