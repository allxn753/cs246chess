#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <string>
#include "board.h"
#include "blank.h"

using namespace std;

class Piece: public Board { // Piece is a decorator class here
    protected:
        Board * component;
        char type;
        int value;
        int x, y;
    public:
        Piece(Board *, char, int, int);
        virtual char pieceAt(int x, int y);
        virtual ~Piece() = 0;
};

#endif
