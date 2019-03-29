#ifndef Steder_h
#define Steder_h

#include <iostream>
#include "Steder.h"
#include "functions.h"
#include "conster.h"
#include "ListTool2B.h"
#include "Sted.h"

using namespace std;

class Steder {
private:
    List* venueList;
    int lastUsedVenue;

public:
    Steder();
    
	//List* kopier(char* nvn, int nr);
	

	void venuesMenu();
    void layoutMenu();
    void newVenue();
    void venueDisplay();
    void readVenuesFromFile();
    void writeVenuesToFile();
	
	void layoutDisplay();
	void layoutNew();
	void layoutEdit();
	void layoutDelete();
    
	int retLastUsedVenue();
    
	
};



#endif


