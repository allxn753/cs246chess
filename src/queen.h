#ifndef QUEEN_H
#define QUEEN_H

#include "decorator.h"

class Queen : public Decorator {
    public:
        Piece* pieceAt(int row, int col);
        char getChar();
};

#endif
