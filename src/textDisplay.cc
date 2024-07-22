#include "textDisplay.h"
#include "subject.h"

using namespace std;

TextDisplay::TextDisplay(Subject* subject) : subject{subject} {}

void TextDisplay::notify() {
    for (int i = 0; i < 8; i++) {
        if (i != 8) cout << i + 1 << " ";

        for (int j = 0; j < 8; j++) {
            cout << subject->getPiece(i, j);
        }
        cout << endl;
    }

    cout << "  abcdefgh" << endl;
}
