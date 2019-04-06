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
	
    bool venueExist(char text[]);
    
	void layoutDisplay();
	void layoutNew();
	void layoutEdit();
	void layoutDelete();
	List* getVenue(char venName[], int layoutN);
    
	int returnCurrentLayout(char venueName[]);
	int retLastUsedVenue();
	//const char* returnZoneName();

	//FRODE:
	List* kopier(char* nvn, int nr);

	/*NEW CODE AFTER REMOVAL OF Oppsett* layouts[]*/
	
};



#endif


