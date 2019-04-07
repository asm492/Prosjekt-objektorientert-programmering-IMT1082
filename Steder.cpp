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
        readAndUpcase("TYPE VENUE NAME", tempName, STRLEN);
		
		if (venueList->inList(tempName))
		{
			cout << "\n\n\t\tVENUE WITH THE NAME '" << tempName << "' ALREADY EXISTS!\n\n";
		}

    } while (venueList->inList(tempName));
    
    tempVenue = new Sted(tempName);
    venueList->add(tempVenue);
    lastUsedVenue = venueList->noOfElements();
	cout << "\n\n\t\tVENUE CREATED!\n";
    
}
void Steder::venueDisplay() {
	char venueName[STRLEN];
	
	if ((venueList->noOfElements()) > 0)
	{
		readAndUpcase("WHICH VENUE TO DISPLAY?", venueName, STRLEN);
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
}
void Steder::readVenuesFromFile() {

//    Sted* temp;
	char bufferName[STRLEN];
	int venueNr;
	ifstream inn("STEDER.DTA");
	//ifstream inn("STEDER_TEST.DTA");

	if (inn)
	{
		inn >> lastUsedVenue; //inn.ignore();

		for (int i = 1; i <= lastUsedVenue; i++) {
			
			inn >> venueNr; inn.ignore();
			inn.getline(bufferName, STRLEN);
			//inn.ignore();
			
			cout << "Steder.cpp: Buffer/strlen(buffer): " << bufferName << ' ' << strlen(bufferName) << endl;
			
			//temp = new Sted(bufferName, inn);
			venueList->add(new Sted(bufferName, inn));
		}
	}
	else
		printError("FILE 'STEDER.DTA' NOT FOUND!");
}
void Steder::writeVenuesToFile() {
    
    int lastUsedVenue;
    Sted* tempVenue;
    
    ofstream out("STEDER_TEST.DTA");
    
    lastUsedVenue = venueList->noOfElements();
    
    out << lastUsedVenue << '\n';
    for (int i = 1; i <= lastUsedVenue; i++)
    {
		out << i << '\n';								//	Venue number
        tempVenue = (Sted*)venueList->removeNo(i);
        tempVenue->writeToFile(out);
        venueList->add(tempVenue);
    }
    
}
int Steder::display(char n[])
{
	Sted* tmp;
	int layouts;
	if (venueList->inList(n))
	{
		venueList->displayElement(n);
		tmp = (Sted*)venueList->remove(n);
		layouts = tmp->returnLastUsedLayout();
		return layouts;
	}
	else
        return 0;
}
void Steder::layoutDisplay()
{
	
	Sted* tmpVenue;
	char buffer[STRLEN];

	readAndUpcase("Which venue's layout would you like to display?", buffer, STRLEN);

	if (venueList->inList(buffer))
	{
		tmpVenue = (Sted*)venueList->remove(buffer);
		venueList->add(tmpVenue);

		if (tmpVenue->returnLastUsedLayout() > 0)
		{
			//venueList->displayElement(buffer);
			tmpVenue->displayLayout();					//	displayLayout is the new, displayLayoutS is the old
		}
		else {
			cout << "\n\n\t\t'" << buffer; 
			cout << "' HAS NO LAYOUTS! MAKE ONE WITH COMMAND 'O N' IN MAIN MENU\n\n";

		}
	}
	else
		cout << "\n\n\t\t'" << buffer << "' IS NOT IN LIST!\n\n";
}
void Steder::layoutNew()
{
	//tmpVenue->newLayout();

	Sted* tmpVenue;
	char buffer[STRLEN];

	readAndUpcase("Which venue would you like to add layout to?", buffer, STRLEN);

	if (venueList->inList(buffer))
	{
		tmpVenue = (Sted*)venueList->remove(buffer);
		//
		venueList->displayElement(buffer);
		//tmpVenue->newLayout();	//OLD
		tmpVenue->newVenueLayout();	//new
		venueList->add(tmpVenue);	//moved
	}
	else
		cout << "\n\n\t\t'" << buffer << "' IS NOT IN LIST!\n\n";
	
}
void Steder::layoutEdit()
{
	
	Sted* tmpVenue = nullptr;
	char buffer[STRLEN];

	readAndUpcase("EDIT LAYOUT FOR?", buffer, STRLEN);

	if (venueList->inList(buffer))
	{
		tmpVenue = (Sted*)venueList->remove(buffer);
		venueList->add(tmpVenue);
		if (tmpVenue->returnLastUsedLayout() > 0)
		{
			
			
			venueList->displayElement(buffer);
			tmpVenue->editLayout();
		}
		else
			printError("THIS VENUE DOESN'T HAVE ANY LAYOUTS YET!");
	}
	else
		cout << "\n\n\t\t'" << buffer << "' IS NOT IN LIST!\n\n";
}
void Steder::layoutDelete()
{
	//TO DO 
}
List* Steder::getVenue(char* venName, int layoutN)
{
	
	Sted* tmpVenue;
	List* newList = NULL;

	cout << "\nSTEDER::GETVENUE() TOP" << endl;
	cout << venName << endl;
	tmpVenue = (Sted*)venueList->remove(venName);
	if (tmpVenue)
	{
		cout << "STEDER::getVenue IF" << endl;
		newList = tmpVenue->getLayout(layoutN);
		venueList->add(tmpVenue);
	}
	
	
	cout << "\nSTEDER::GETVENUE() BOTTOM";

	return newList;	

	
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
int Steder::returnCurrentLayout(char venueName[])
{
	
	Sted* tempVenue;
	int nr;
	if (venueList->inList(venueName))
	{
		tempVenue = (Sted*)venueList->remove(venueName);
		nr = tempVenue->returnLastUsedLayout();
		venueList->add(tempVenue);

		return nr;
	}
	else
	{
		printError("VENUE NOT IN LIST!");
		return 0;
	}
}
int Steder::retLastUsedVenue() {
	return lastUsedVenue;
}/*
List* Steder::kopier(char* nvn, int nr) {
	List* listPtr = NULL;
	Sted* venue;

	if ((venue = (Sted*)venueList->remove(nvn))) {
		listPtr = venue->kopier(nr);
		venueList->add(venue);
	}
	return listPtr;
}*/

bool Steder::venueExist(char text[]){
    Sted* tempVenue;
    
	bool searchResult = false;
    lastUsedVenue = venueList->noOfElements();
    
    for (int i = 1; i <= lastUsedVenue; i++)
    {
        
        tempVenue = (Sted*)venueList->removeNo(i);        
        venueList->add(tempVenue);
        searchResult = tempVenue->compareVenueName(text);

        if (searchResult) {
            return true;
        }
        
    }
    return false;
}


