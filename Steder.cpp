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
        case 'D': venueDisplay();            break;
        case 'N': newVenue();                break;
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
	
	if ((venueList->noOfElements()) > 0)
	{
		read("WHICH VENUE TO DISPLAY?", venueName, STRLEN);
		if (venueList->inList(venueName)) {
			venueList->displayElement(venueName);
		}
		else {
			cout << "\n\n\t\tNO VENUES IN THE LIST WITH NAME: '";
			cout << venueName << "'!\n\n";
		}
	}
	else
	{
		printError("NO VENUES IN LIST YET!");
	}


	
	
    
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
    
    Sted* temp;
    char bufferName[STRLEN];
    
    ifstream inn("STEDER.DTA");
    
    if (inn)
    {
        inn >> lastUsedVenue; inn.ignore();
        
        for(int i = 1; i <= lastUsedVenue; i++){
            inn.getline(bufferName, STRLEN);
            temp = (Sted*)venueList->add(new Sted(bufferName, inn));
        }
    }
    else
        printError("FILE 'STEDER.DTA' NOT FOUND!");
    
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
int Steder::retLastUsedVenue() {
	return lastUsedVenue;
}
