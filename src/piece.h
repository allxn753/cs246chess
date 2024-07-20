#ifndef PIECE_H
#define PIECE_H

#include <string>

using namespace std;

class Tile;

class Piece {

    public:
        int value;
        string colour;
        virtual void draw();
        virtual bool isValidMove(Tile);
};

#endif
