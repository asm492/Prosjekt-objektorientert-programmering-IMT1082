#ifndef Steder_h
#define Steder_h

#include <iostream>
#include "Steder.h"
#include "functions.h"
#include "conster.h"
#include "ListTool2B.h"
#include "Sted.h"


class Steder {
private:
    List* venueList;
public:
    Steder();
    void venuesMenu();
	void newVenue();
	void venueDisplay();
};



#endif 

