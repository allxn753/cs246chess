#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
#include "subject.h"
#include "board.h"
#include <iostream>

class TextDisplay : public Observer {
    Board* subject;
public:
    TextDisplay(Board* subject);
    void notify() override;
};

#endif
