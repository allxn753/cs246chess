#include "textDisplay.h"
#include "subject.h"

using namespace std;

TextDisplay::TextDisplay(Subject* subject) : subject{subject} { subject->attach(this); }

void TextDisplay::notify() {
    cout << endl;
    for (int j = 7; j >= 0; --j) {
        cout << j + 1 << " ";
        for (int i = 0; i < 8; ++i) {
            cout << subject->getChar(i,j);
        }
        cout << endl;
    }

    cout << "  abcdefgh" << endl << endl;
}
