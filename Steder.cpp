#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "Steder.h"
#include "functions.h"
#include "conster.h"
#include "ListTool2B.h"
#include "Sted.h"
#include "Sone.h"

using namespace std;

void Steder::venuesMenu(){
    
    char command = read();
    
    switch (command) {
        case 'D': venueDisplay();            break;     //Goes to display function
        case 'N': newVenue();                break;     //Goes to new venue function
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
        readAndUpcase("TYPE VENUE NAME", tempName, STRLEN);
		
		if (venueList->inList(tempName))
		{
			cout << "\n\n\t\tVENUE WITH THE NAME '" << tempName << "' ALREADY EXISTS!\n\n";
		}

    } while (venueList->inList(tempName));
    
    tempVenue = new Sted(tempName);         //Creates a new venue
    venueList->add(tempVenue);              //Adds it to list
    lastUsedVenue = venueList->noOfElements();
	cout << "\n\n\t\tVENUE CREATED!\n";
    
}
void Steder::venueDisplay() {       //Displayes all elements in list
	
	if ((venueList->noOfElements()) > 0)
	{
		venueList->displayList();
	}
	else
	{
		printError("NO VENUES IN LIST YET!");
	}
}
void Steder::readVenuesFromFile() {


	char bufferName[STRLEN];
	int venueNr;
	
	ifstream inn("STEDER.DTA");

	if (inn)
	{
		inn >> lastUsedVenue; inn.ignore();		

		for (int i = 1; i <= lastUsedVenue; i++) {
			//inn.ignore();								
			inn.getline(bufferName, STRLEN);		    //  Reads name from file
			venueList->add(new Sted(bufferName, inn));  //  Adds it in list
		}
	}
	else
		printError("FILE 'STEDER.DTA' NOT FOUND!");
}
void Steder::writeVenuesToFile() {
    
    int lastUsedVenue;
    Sted* tempVenue;
    
    ofstream out("STEDER.DTA");
    
    lastUsedVenue = venueList->noOfElements();
    
    out << lastUsedVenue << '\n';               //Number of venues
	for (int i = 1; i <= lastUsedVenue; i++)
	{
		out << '\n';									//	New line before each venue name
		tempVenue = (Sted*)venueList->removeNo(i);
		tempVenue->writeToFile(out);                    //Calls to sted writeToFile
		venueList->add(tempVenue);
	}
}
int Steder::display(char n[])           //Displayes venue with given name
{
	Sted* tmp;
	int layouts;
	if (venueList->inList(n))
	{
		venueList->displayElement(n);
		tmp = (Sted*)venueList->remove(n);
		layouts = tmp->returnLastUsedLayout();          // Gets last used layout
		venueList->add(tmp);
		return layouts;             //Returns last used layout
	}
	else
        return 0;
}
void Steder::layoutDisplay()
{
	
	Sted* tmpVenue;
	char buffer[STRLEN];

	readAndUpcase("Which venue's layout would you like to display?", buffer, STRLEN);

	tmpVenue = (Sted*)venueList->remove(buffer);
	

	if (tmpVenue->returnLastUsedLayout() > 0)       //Cheks if layouts exist
	{
		
        tmpVenue->displayLayout();					//	Displayes zones from sted::
	}
	else {
		cout << "\n\n\t\t'" << buffer;
		cout << "' HAS NO LAYOUTS! MAKE ONE WITH COMMAND 'O N' IN MAIN MENU\n\n";

	}
	venueList->add(tmpVenue);
}
void Steder::layoutNew()
{
	Sted* tmpVenue;
	char buffer[STRLEN];

	readAndUpcase("Which venue would you like to add layout to?", buffer, STRLEN);

	if (venueList->inList(buffer))								//	Checks if 'buffer' exists
	{
		tmpVenue = (Sted*)venueList->remove(buffer);			//	Takes out of list
		venueList->displayElement(buffer);					    //	Displays it
		tmpVenue->newVenueLayout();								//	Makes new layout
		venueList->add(tmpVenue);							    //	Adds back to list
	}
	else
		cout << "\n\n\t\t'" << buffer << "' IS NOT IN LIST!\n\n";
	
}
void Steder::layoutEdit()       //Edits layout for venue
{
	
	Sted* tmpVenue = nullptr;
	char buffer[STRLEN];

	readAndUpcase("EDIT LAYOUT FOR?", buffer, STRLEN);

	if (venueList->inList(buffer))          //Checks if venue exists
	{
		tmpVenue = (Sted*)venueList->remove(buffer);
		
		if (tmpVenue->returnLastUsedLayout() > 0)       //Checks if venue has layouts
		{
			
			
			venueList->displayElement(buffer);
			tmpVenue->editLayout();             //Displayes layouts
		}
		else
			printError("THIS VENUE DOESN'T HAVE ANY LAYOUTS YET!");
	}
	else
		cout << "\n\n\t\t'" << buffer << "' IS NOT IN LIST!\n\n";
	venueList->add(tmpVenue);
}
List* Steder::getVenue(char* venName, int layoutN)
{
	Sted* tmpVenue = NULL;
	List* newList = NULL;

    
	tmpVenue = (Sted*)venueList->remove(venName);
	if (tmpVenue)
	{
		
		newList = tmpVenue->getLayout(layoutN);     //Copies chosen layout
		
	}
	
	venueList->add(tmpVenue);

	return newList;	                    //Returns layout

}
void Steder::layoutMenu() {		//	Called from main, layout menu
	char command;
	
	if ((venueList->noOfElements()) > 0)        //Checks if venue list is empty
	{
		command = read();

		switch (command)
		{
		case 'D': layoutDisplay();	break;          //Display layout
		case 'N': layoutNew();		break;          //Make new layout
		case 'E': layoutEdit();		break;          //Edit layout
		default:
			break;
		}
	}
	else
		printError("VENUE LIST IS EMPTY. YOU MUST ADD A VENUE IN ORDER TO CONFIGURE OR DISPLAY A LAYOUT!");

}
int Steder::returnCurrentLayout(char venueName[])   //Returns layout number for given venue
{
	
	Sted* tempVenue;
	int nr;
	if (venueList->inList(venueName))
	{
		tempVenue = (Sted*)venueList->remove(venueName);
		nr = tempVenue->returnLastUsedLayout();         //Gets number of layouts
		venueList->add(tempVenue);

		return nr;                          //Return layout number
	}
	else
	{
		printError("VENUE NOT IN LIST!");
		return 0;
	}
}
int Steder::retLastUsedVenue() {            //Returns number of layouts
	return lastUsedVenue;
}

bool Steder::venueExist(char text[]){           //Checks if venue exists
    Sted* tempVenue;
    
	bool searchResult = false;
    lastUsedVenue = venueList->noOfElements();
    
    for (int i = 1; i <= lastUsedVenue; i++)        //Loops thru all venues
    {
        
        tempVenue = (Sted*)venueList->removeNo(i);        
		searchResult = tempVenue->compareVenueName(text);   //Compares text with existing venues
		venueList->add(tempVenue);
        

        if (searchResult) {
            return true;
        }
        
    }
    return false;
}


