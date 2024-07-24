#ifndef PAWN_H
#define PAWN_H

#include "decorator.h"

class Pawn : public Decorator {
    public:
        Piece* pieceAt(int row, int col);
        char getChar();
};

#endif
