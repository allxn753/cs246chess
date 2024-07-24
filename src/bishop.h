#ifndef BISHOP_H
#define BISHOP_H

#include "decorator.h"

class Bishop : public Decorator {
    public:
        Piece* pieceAt(int row, int col);
        char getChar();
};

#endif
