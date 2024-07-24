#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "piece.h"

class Decorator: public Piece {
    protected:
        Piece* piece;
    public:
        Decorator(Piece* piece);
        virtual ~Decorator();
};

#endif
