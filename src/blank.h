#ifndef BLANK_H
#define BLANK_H
#include "piece.h"
#include <iostream>

class Blank: public Piece {
  protected:
    vector<int> enPassant = {8, 8};
    char type;
  public:
    Piece* pieceAt(int x, int y) override;
    Piece* pieceAt(string) override;
    char getChar() override;
    void setEnPassant(vector<int> coord) { enPassant = coord; };
    vector<int> getEnPassant() { return enPassant; };
    bool getHasMoved() override;
};

#endif
