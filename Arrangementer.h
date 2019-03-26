#ifndef Arrangementer_h
#define Arrangementer_h

#include <iostream>
#include "Arrangementer.h"
#include "functions.h"
#include "ListTool2B.h"
#include "Arrangement.h"
#include "conster.h"
#include "enums.h"

class Arrangementer
{
private:
    int lastEvent;
    List* eventList;
    
public:
    void newEvent();
    void eventsMenu();
    void searchChoice();
    void eventNameSearch();
    void searchMenu();
    void artistNameSearch();
    void venueSearch();
    void dateSearch();
    void typeSearch();
    void allDataArrNr();
    Arrangementer();
    ~Arrangementer();
};




#endif
