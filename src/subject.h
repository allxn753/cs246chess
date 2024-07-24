#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

class Observer; // forward declaration
class Piece;

class Subject {
  std::vector<Observer*> observers;
 public:
  void attach( Observer* o );
  void detach( Observer* o );
  void notifyObservers();
  virtual Piece* getPiece(int row, int col) const = 0;
  virtual char getChar(int row, int col) const = 0;
  virtual ~Subject() = default;
};

#endif
