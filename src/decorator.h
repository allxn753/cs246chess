#ifndef _DECORATOR_H_
#define _DECORATOR_H_
#include "piece.h"

class Board;

class Decorator: public Piece {
    friend Board;
    protected:        
        Piece* piece;
        int x, y;
        unsigned int val;
        string colour;
        char type;
        bool hasMoved = false;
    public:
        Decorator(Piece* piece, int, int, unsigned int, string);
        virtual ~Decorator();
        int getX() {return x;}
        int getY() {return y;}
        virtual char getChar() override;
        virtual Piece* pieceAt(int, int) override;
        virtual void setCoordinates(int, int) {this->x = x; this->y = y;}
        virtual bool getHasMoved() {return hasMoved;}
        
};


#endif
