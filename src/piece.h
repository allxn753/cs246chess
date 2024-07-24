#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>

using namespace std;

class Tile;

class Piece {

    public:
        virtual ~Piece();

        int value;
        string colour;
        virtual char pieceAt(int row, int col);
        virtual bool isValidMove(Tile);
};

#endif
