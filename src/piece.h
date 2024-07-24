#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>

using namespace std;

class Piece { 
    public:
        virtual Piece* pieceAt(int x, int y) = 0;
        virtual char getChar();
        virtual bool getHasMoved();
        virtual ~Piece();
};

#endif
