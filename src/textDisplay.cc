#include "textDisplay.h"
#include "subject.h"

using namespace std;

TextDisplay::TextDisplay(Subject* subject) : subject{subject} { subject->attach(this); }

void TextDisplay::notify() {
    for (int i = 0; i < 8; i++) {
        cout << i + 1 << " ";

        for (int j = 0; j < 8; j++) {
            cout << subject->getChar(i,j);
        }
        cout << endl;
    }

    cout << "  abcdefgh" << endl << endl;
}
