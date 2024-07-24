#ifndef BLANK_H
#define BLANK_H
#include "board.h"
#include "piece.h"
#include <iostream>

class Blank: public Board {
  bool enPassant;
 
 public:
  char pieceAt(int , int) override;
  void setEnPassant(bool tf) { enPassant = tf; };
  bool getEnPassant() { return enPassant; };
};

#endif
