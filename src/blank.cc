#include "blank.h"
#include <iostream>

Piece* Blank::pieceAt(int row, int col) {

    if (row % 2 == 0) {

        if (col % 2 == 0) {
            this->type == ' ';
        } else { this->type == '_'; }

    } else {

        if (col % 2 == 0) {
            this->type == '_';
        } else { this->type == ' '; }

    }

    return this;
}
