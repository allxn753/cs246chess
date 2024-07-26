#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <iostream>
#include "subject.h"
#include "piece.h"
#include "chess_pieces.h"

class Piece;
class Game;

using namespace std;

class Board : public Subject {
    friend Game;
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
        Piece* getPiece(int x, int y);
        Piece* getPiece(string);
        vector<Decorator*> getArr();
        int getNumPieces();
        char getChar(int x, int y) const;
        void print(string pos);
        void wipe();
        ~Board();
};


#endif
