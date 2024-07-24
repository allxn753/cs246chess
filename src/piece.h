#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>

using namespace std;

class Piece { 
    protected:
        char type;
    // protected:
    //     Board * component;
    //     char type;
    //     int value;
    //     int x, y;
    public:
        virtual Piece* pieceAt(int x, int y) = 0;
        virtual char getChar();
        virtual ~Piece();
};

#endif
