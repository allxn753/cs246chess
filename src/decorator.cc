#include "piece.h"
#include "decorator.h"

Decorator::Decorator(Piece* piece) : piece{piece} {}

Decorator::~Decorator() { delete piece; }
