#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include <string>

class Queen : public Piece {
    bool hasMoved = false;
    public:
        Queen(Board *, char, int, int);
};

#endif
