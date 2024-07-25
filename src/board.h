#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <iostream>
#include "subject.h"
#include "piece.h"
#include "pawn.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"

class Piece;


using namespace std;

class Board : public Subject {
    protected:
        Piece* pieces;
        int numPieces  = 0;
        vector<Decorator*> arr= {};


    public:
        inline static int HEIGHT = 8;
        inline static int WIDTH = 8;
        
        explicit Board(Piece* pieces) : pieces{pieces} {};
        Piece*& boardState() { return pieces; }
        void display();

        void addPiece(char type, string pos);
        void removePiece(string pos);
        Piece* getPiece(int x, int y) const override;
        char getChar(int x, int y) const override;
        void print(string pos);
        void wipe();
        ~Board();
};


#endif
