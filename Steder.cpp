#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include "Steder.h"
#include "functions.h"
#include "conster.h"
#include "ListTool2B.h"
#include "Sted.h"


using namespace std;

void Steder::venuesMenu(){
    
    char command = read();
    
    switch (command) {
	case 'D': venueDisplay();			break;
	case 'N': newVenue();				break;
        default: printError("INVALID INPUT! GOING BACK TO MAIN MENU");
            break;
    } 
}



Steder::Steder(){
venueList = new List(Sorted);
}
void Steder::newVenue() {
	Sted* tempVenue;
	char tempName[STRLEN];

	do
	{
		read("TYPE VENUE NAME", tempName, STRLEN);

	} while (venueList->inList(tempName));

	tempVenue = new Sted(tempName);
	venueList->add(tempVenue);

}
void Steder::venueDisplay() {
	/*THIS IS FOR TESING ONLY*/
	char venueName[STRLEN];
	read("WHICH VENUE TO DISPLAY?", venueName, STRLEN);
	venueList->displayElement(venueName);
	
	/************************/
}
void Steder::writeVenuesToFile() {
	
	int lastUsedVenue;
	Sted* tempVenue;

	ofstream out("STEDER_TEST.DTA");
	
	lastUsedVenue = venueList->noOfElements();

	out << lastUsedVenue << '\n';
	for (int i = 1; i <= lastUsedVenue; i++)
	{
		tempVenue = (Sted*)venueList->removeNo(i);
		tempVenue->writeToFile(out);
		venueList->add(tempVenue);
	}

}
void Steder::readVenuesFromFile() {
	//++lastUsedVenue;
}
void Steder::layoutMenu() {
	Sted* tempVenue;
	char venueName[STRLEN];
	read("ENTER NAME OF VENUE", venueName, STRLEN);

	if (venueList->inList(venueName))
	{
		tempVenue = (Sted*)venueList->remove(venueName);
		tempVenue->newLayout();
		venueList->add(tempVenue);
	}
	else
		printError("DIDN'T FIND ANY VENUES WITH THAT NAME");
	
}