#ifndef PAWN_H
#define PAWN_H

#include "decorator.h"

class Pawn : public Decorator {
    protected:
        int x, y;
        unsigned int val;
        string colour;
        char type = 'p';
        bool hasMoved = false;

    public:
        Pawn(Piece *piece, int x, int y, unsigned int val, string colour);
        Piece* pieceAt(int x, int y) override;
        char getChar() override;
        bool getHasMoved() override;
        void setCoordinates(int x, int y);
};

#endif
