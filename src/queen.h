#ifndef QUEEN_H
#define QUEEN_H

#include "decorator.h"

class Queen : public Decorator {
    protected:
        int x, y;
        unsigned int val;
        string colour;
        char type = 'q';

    public:
        Queen(Piece *piece, int x, int y, unsigned int val, string colour);
        Piece* pieceAt(int x, int y) override;
        char getChar() override;
        void setCoordinates(int x, int y);
};

#endif
