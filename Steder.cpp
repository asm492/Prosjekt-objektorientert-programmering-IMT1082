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

	cout << "\n\n\t\tVENUE CREATED!\n";
    
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
void Steder::layoutDisplay()
{
	Sted* tmpVenue;
	char buffer[STRLEN];

	read("Which venue's layout would you like to display?", buffer, STRLEN);

	if (venueList->inList(buffer))
	{
		tmpVenue = (Sted*)venueList->remove(buffer);
		venueList->add(tmpVenue);
		venueList->displayElement(buffer);

		tmpVenue->displayLayouts();					//	Calls Sted class' function
	}
	else
		cout << "\n\n\t\t'" << buffer << "' IS NOT IN LIST!\n\n";
}
void Steder::layoutNew()
{
	//tmpVenue->newLayout();

	Sted* tmpVenue;
	char buffer[STRLEN];

	read("Which venue would you like to add layout to?", buffer, STRLEN);

	if (venueList->inList(buffer))
	{
		tmpVenue = (Sted*)venueList->remove(buffer);
		venueList->add(tmpVenue);
		venueList->displayElement(buffer);
		tmpVenue->newLayout();
	}
	else
		cout << "\n\n\t\t'" << buffer << "' IS NOT IN LIST!\n\n";
	
}
void Steder::layoutEdit()
{
	//TO DO
}
void Steder::layoutDelete()
{
	//TO DO 
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
void Steder::layoutMenu() {		//	From main press 0
	char command;
	
	if ((venueList->noOfElements()) > 0)
	{
		command = read();

		switch (command)
		{
		case 'D': layoutDisplay();	break;
		case 'N': layoutNew();		break;
		case 'E': layoutEdit();		break;
		case 'S': layoutDelete();	break;
		
		
		default:
			break;
		}
	}
	else
		printError("VENUE LIST IS EMPTY. YOU MUST ADD A VENUE IN ORDER TO CONFIGURE OR DISPLAY A LAYOUT!");

	
	/*Sted* tempVenue;
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
    */
}
int Steder::retLastUsedVenue() {
	return lastUsedVenue;
}

