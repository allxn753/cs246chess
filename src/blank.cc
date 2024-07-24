#include "blank.h"
#include <iostream>

char Blank::pieceAt(int row, int col) {
    if (row % 2 == 0) {

        if (col % 2 == 0) {
            return ' ';
        } else { return '_'; }

    } else {

        if (col % 2 == 0) {
            return '_';
        } else { return ' '; }

    }
}
