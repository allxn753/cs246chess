#ifndef BISHOP_H
#define BISHOP_H

#include "decorator.h"

class Bishop : public Decorator {
    protected:
        int x, y;
        unsigned int val;
        string colour;
        char type = 'b';

    public:
        Bishop(Piece *piece, int x, int y, unsigned int val, string colour);
        Piece* pieceAt(int x, int y) override;
        char getChar() override;
        void setCoordinates(int x, int y);
};

#endif
