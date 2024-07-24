#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "piece.h"

class Decorator: public Piece {
    protected:
        Piece* piece;
        int x;
        int y;
        unsigned int val;
        bool hasMoved;
        string colour;

    public:
        Decorator(Piece* piece, int x, int y, unsigned int val, string colour);
        virtual ~Decorator();
        void setCoordinates(int x, int y);
};

#endif
