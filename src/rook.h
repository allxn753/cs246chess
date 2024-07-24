#ifndef ROOK_H
#define ROOK_H

#include "decorator.h"

class Rook : public Decorator {
    protected:
        int x, y;
        unsigned int val;
        string colour;
        char type = 'r';
        bool hasMoved = false;

    public:
        Rook(Piece *piece, int x, int y, unsigned int val, string colour);
        Piece* pieceAt(int x, int y) override;
        char getChar() override;
        bool getHasMoved() override;
        void setCoordinates(int x, int y);
};

#endif
