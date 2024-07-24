#ifndef BLANK_H
#define BLANK_H
#include "piece.h"
#include <iostream>

class Blank: public Piece {
 public:
  char pieceAt(int row, int col) override;
  bool enPassant();
};

#endif
