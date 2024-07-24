#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H

#include "observer.h"
#include "subject.h"
#include <iostream>

class TextDisplay : public Observer {
    Subject& subject;
public:
    TextDisplay(Subject& subject);
    void notify() override;
};

#endif
