#include "subject.h"
#include "observer.h"
#include <vector>

void Subject::attach( Observer* o ) { observers.push_back(o); }

void Subject::detach( Observer* o ) {
    for ( auto it = observers.begin(); it != observers.end(); ++it ) {
        if ( *it == o ) {
            observers.erase(it);
            delete o;
            break;
        }
    }
}

void Subject::notifyObservers() { 
    for (auto ob : observers) ob->notify();
}
