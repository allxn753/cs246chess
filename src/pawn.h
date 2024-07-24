#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include <string>

class Pawn : public Piece {
    bool hasMoved = false;
    public:
        Pawn(Board *, char, int, int);
};

#endif
