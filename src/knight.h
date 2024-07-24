#ifndef KNIGHT_H
#define KNIGHT_H

#include "decorator.h"

class Knight : public Decorator {
    public:
        Piece* pieceAt(int row, int col);
        char getChar();
};

#endif
