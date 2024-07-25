#include "textDisplay.h"
#include "subject.h"
#include "board.h"

using namespace std;

TextDisplay::TextDisplay(Board* subject) : subject{subject} { subject->attach(this); }

void TextDisplay::notify() {
    cout << endl;
    for (int j = Board::HEIGHT - 1; j >= 0; --j) {
        cout << j + 1 << " ";
        for (int i = 0; i < Board::WIDTH; ++i) {
            cout << subject->getChar(i,j);
        }
        cout << endl;
    }

    cout << "  abcdefgh" << endl << endl; // could change to be dynamic with board size.
}
