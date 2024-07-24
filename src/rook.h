#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include <string>

class Rook : public Piece {
    bool hasMoved = false;
    public:
        Rook(Board *, char, int, int);
};

#endif
