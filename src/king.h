#ifndef KING_H
#define KING_H

#include "decorator.h"

class King : public Decorator {
    public:
        Piece* pieceAt(int row, int col);
        char getChar();
};

#endif
