#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>

using namespace std;

class Piece { 
    public:
        virtual Piece* pieceAt(int x, int y) = 0;
        virtual char getChar() = 0;
        virtual bool getHasMoved() = 0;
        virtual ~Piece();
};

#endif
