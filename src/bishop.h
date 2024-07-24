#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include <string>

class Bishop : public Piece {
    public:
        Bishop(Board *, char, int, int);
};

#endif
