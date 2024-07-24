#ifndef ROOK_H
#define ROOK_H

#include "decorator.h"

class Rook : public Decorator {
    public:
        Piece* pieceAt(int row, int col);
        char getChar();
};

#endif
