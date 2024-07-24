#ifndef KNIGHT_H
#define KNIGHT_H

#include "decorator.h"

class Knight : public Decorator {
    protected:
        int x, y;
        unsigned int val;
        string colour;
        char type = 'n';
        bool hasMoved = false;

    public:
        Knight(Piece *piece, int x, int y, unsigned int val, string colour);
        Piece* pieceAt(int x, int y) override;
        char getChar() override;
        bool getHasMoved() override;
        void setCoordinates(int x, int y);
};

#endif
