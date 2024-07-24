#ifndef KING_H
#define KING_H

#include "decorator.h"

class King : public Decorator {
    protected:
        int x, y;
        unsigned int val;
        string colour;
        char type = 'k';
        bool hasMoved = false;

    public:
        King(Piece *piece, int x, int y, unsigned int val, string colour);
        Piece* pieceAt(int x, int y) override;
        char getChar() override;
        void setCoordinates(int x, int y);
};

#endif
