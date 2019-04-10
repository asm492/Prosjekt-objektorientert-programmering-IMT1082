
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include "Sted.h"
#include "Stoler.h"
#include "Vrimle.h"
#include "Sone.h"
#include "ListTool2B.h"
#include <cstring>
#include "enums.h"
#include "conster.h"

using namespace std;

Sted::Sted(char n[]) : TextElement(n) {
    
	lastUsedLayout = 0;

	name = new char[strlen(n) + 1];         //Reads venue name
	strcpy(name, n);

	
	for (int i = 0; i <= MAXLAYOUTS; i++)
	{
		venueLayouts[i] = nullptr;          //All objects inn array to nullptr
	}

	

    
    
}
Sted::Sted(char n[], ifstream & inn) : TextElement(n) {
    
	char nameOfZone[STRLEN];
	char buffer[STRLEN];
	enum zoneType typeOfZone;
	int noOfZones, layNo, zoneNo;
	Stoler* tempSeat;
	Vrimle* tempSwarm;
    
    name = new char[strlen(n) + 1];					//	Name of the venue
    strcpy(name, n);
    
    inn >> lastUsedLayout;                         //Reading number of layouts
    
    for(int j = 1; j <= lastUsedLayout; j++){
        
		inn >> layNo;
		venueLayouts[layNo] = new List(Sorted);


		inn >> noOfZones; inn.ignore();           //Reading number of zones

		for (int i = 1; i <= noOfZones; i++)
		{
			inn.getline(buffer, STRLEN);          //Reads zone type

			if (strcmp(buffer, "stoler") == 0)
			{
				typeOfZone = stoler;
				inn.getline(nameOfZone, STRLEN);   //Zone name
				tempSeat = new Stoler(nameOfZone, inn, typeOfZone);
				venueLayouts[j]->add(tempSeat);    //To list
			}

			if (strcmp(buffer, "vrimle") == 0)
			{
				typeOfZone = vrimle;
				inn.getline(nameOfZone, STRLEN);   //Zone list
				tempSwarm = new Vrimle(nameOfZone, inn, typeOfZone);
				venueLayouts[j]->add(tempSwarm);   //To list
			}

            if (strcmp(buffer, "stoler") == 0 && strcmp(buffer, "vrimle") == 0)
			{
				cout << "OPPSETT::OPPSETT(ifstream): DON'T MIND ME! AN ERROR OCCURED, I AM JUST HERE TO HELP YOU:\n";
				cout << "\n\nBUFFER/ZONE NAME: " << buffer << " / " << nameOfZone;
				cout << "\nSTRLEN(BUFFER) / STRLEN(ZONENAME): " << strlen(buffer) << " / " << strlen(nameOfZone) << endl;
			}
        }
		
    }
}
void Sted::writeToFile(ofstream & out) {				
	
	
	Sone* zonePtr;
	Stoler* seatPtr;
	Vrimle* swarmPtr;
	

	out << text << '\n';									//	Name
	out << lastUsedLayout << '\n';							//	NoOfLayouts/lastUsedLayout

	for (int i = 1; i <= lastUsedLayout; i++)
	{
		out << i << '\n';									//Layout number
		out << venueLayouts[i]->noOfElements() << '\n';		//Number of zones
		for (int j = 1; j <= venueLayouts[i]->noOfElements(); j++)
		{
			zonePtr = (Sone*)venueLayouts[i]->removeNo(j);

			if (zonePtr->returnZoneType() == 0)        //If stoler
			{
				venueLayouts[i]->add(zonePtr);         //Writes zone type to file
				out << "stoler" << '\n';
				seatPtr = (Stoler*)venueLayouts[i]->removeNo(j);
				seatPtr->writeToFile(out);             //Writes stoler info to file
				venueLayouts[i]->add(seatPtr);
			}
			if (zonePtr->returnZoneType() == 1)        //If vrimle
			{

				venueLayouts[i]->add(zonePtr);          //Writes zone type to file
				out << "vrimle" << '\n';
				swarmPtr = (Vrimle*)venueLayouts[i]->removeNo(j);
				swarmPtr->writeToFile(out);           //Writes vrimle info to file
				venueLayouts[i]->add(swarmPtr);
			}
		}
	}

}

void Sted::display(){       //Displayes venue
    cout << "\nVenue:             " << name;
	cout << "\nNumber of layouts: " << lastUsedLayout << endl;
}

void Sted::displayName(){           //Only displayes name
    cout << name;
}

void Sted::newSeatLayout() {        //New layout
    char buffer[STRLEN];
   
    if (lastUsedLayout < 5)         //Checks if layouts is maxed
    {
        cout << "\nCreating new layout: " << endl;
        read("Enter name for zone", buffer, STRLEN);
        
    }
    else
    {
        printError("MAXIMUM NUMBER OF CONFIGURATIONS ARE ALREADY MADE!");
        
        
    }
    
}

void Sted::displayLayouts() //Sone display
{
	int layoutNo, sone, layTemp;
    
    if (lastUsedLayout > 0){                    //If layout exist
	
        layoutNo = read("WHICH LAYOUT TO DISPLAY?", 1, lastUsedLayout);
        layTemp = venueLayouts[layoutNo]->noOfElements();
        sone = read("WHICH SONE DO YOU WANT TP DISPLAY? (0 for all)", 0, layTemp);
	
        if (sone == 0)      //If typed zero, displayes all
        {
            cout << "\nLAYOUT NO " << layoutNo << " FOR " << name << ':' << endl;
            venueLayouts[layoutNo]->displayList();
            
        }
	else
		venueLayouts[layoutNo]->displayElement(sone);   //displayes wanted sone
	
    }
}
int Sted::returnLastUsedLayout()
{
	return lastUsedLayout;
}

List* Sted::getLayout(int layoutN)
{
	List* liste = NULL;
	int i, ant;
	Sone *sone, *kopi;

	if (layoutN <= lastUsedLayout) {        //checks if layout number is correct
		ant = venueLayouts[layoutN]->noOfElements();

		liste = new List(Sorted);               //Makes new list

		for (i = 1; i <= ant; i++) {

			sone = (Sone*)venueLayouts[layoutN]->removeNo(i);

			if (sone->returnZoneType() == 0)    //if stoler, add to list as stoler
				kopi = new Stoler(*((Stoler*)sone), stoler);
			else
				kopi = new Vrimle(*((Vrimle*)sone), vrimle); //Add to list as vrimle

			venueLayouts[layoutN]->add(sone);
			liste->add(kopi);                           //add to copy
		}
	}
		return liste;                           //Returns copy of list
}
	
	

void Sted::newLayoutFromCopy() {
	char buffer[STRLEN];
	int layNo;

	layNo = read("LAYOUT TO COPY FROM? 0 TO CANCEL", 0, lastUsedLayout);
	
	if (layNo != 0)
	{		
		venueLayouts[++lastUsedLayout] = getLayout(layNo); //Makes layout copy
	}
	else
		printError("NEW LAYOUT REGISTRATION ABORTED BY USER");

}

int Sted::compareVenueName(char text[]){        //Compares venue name
    return !strcmp(name, text);
}

void Sted::newVenueLayout(){
	char command;

	cout << "\nCURRENT NUMBER OF LAYOUTS: " << lastUsedLayout;

	if (lastUsedLayout < 5)                 //Checks if room in list
	{
		cout << "\nCreate layout from (S)cratch or (C)opy?: ";
		

		do
		{
			command = read();
			switch (command)    //Switch for choosing from scratch or copy
			{
			case 'S':
				cout << "\nCRATING LAYOUT NO. " << ++lastUsedLayout << " for " << name << ":\n\n";			    //	Increments layout counter, points to a new list
				venueLayouts[lastUsedLayout] = new List(Sorted);
				addZones(lastUsedLayout);									break;
                case 'C': newLayoutFromCopy();								break;

			default: printError("INVALID COMMAND, TRY AGAIN. S/C: ");	break;
			}
		} while (command != 'S' && command != 'C');


	}
	else
		printError("THIS VENUE HAS REACHED ITS MAX NO. OF LAYOUTS!");
}
void Sted::addZones(int nr) {
	Stoler* tempSeat;
	Vrimle* tempVrimle;
	char command, ch;
	char buffer[STRLEN];

	cout << "\nADDING ZONES TO LAYOUT NO. " << nr << endl;

	do
	{
		read("DESIRED NAME FOR NEW ZONE?", buffer, STRLEN);

		cout << "\n(S)EATS or S(W)ARM?: ";
		command = read();

		switch (command)    //Switch for seats or for swarm
		{
		case 'S':
			tempSeat = new Stoler(buffer, stoler);
			venueLayouts[nr]->add(tempSeat);			break;		//adds seat to list
		case 'W':
			tempVrimle = new Vrimle(buffer, vrimle);
			venueLayouts[nr]->add(tempVrimle);			break;      //add swarm to list

		default: printError("INVALID COMMAND");			break;  //error
		}

		cout << "\nCONTINIUE TO ADD MORE ZONES? (Y/N):   "; ch = read();

	} while (ch == 'Y');  //loops till user types something other than 'Y'
}
void Sted::editLayout() {
	int nr;
	char ch, command;
    char sone[STRLEN];
	
	if (lastUsedLayout > 0)               //Checks if layout exist
	{
		nr = read("WHICH LAYOUT TO EDIT?", 1, lastUsedLayout);
		venueLayouts[nr]->displayList();

		cout << "\nWHAT DO YOU WANT TO DO TO THE LAYOUT? " << endl;
		cout << "\n\tA\tAdd new zone from scratch";
		cout << "\n\tR\tRemove a zone";
		cout << "\n\tD\tChange the details" << endl;

		ch = read();
		switch (ch)
		{
		case 'A': addZones(nr);									break;	//	Add zones to existing layout
		case 'R': 
			read("WHICH ZONE TO REMOVE?: ", sone, STRLEN); 
			venueLayouts[nr]->destroy(sone); printError("ZONE DELETED"); //Deletes zone
			venueLayouts[nr]->displayList();				    		break;
		case 'D': 
			read("WHICH ZONE TO CHANGE?: ", sone, STRLEN);
			changeDetails(nr, sone);					     //Calls to change function to change zone
			venueLayouts[nr]->displayElement(sone);						break;
		default: printError("INVALID COMMAND!");						break;
		}        
    }
}
void Sted::changeDetails(int nr, char* zName) {
	Sone* zonePtr;
	int zoneTyp;
	
	zonePtr = (Sone*)venueLayouts[nr]->remove(zName);			//	Removes from list
	zoneTyp = zonePtr->returnZoneType();						//	Checks if Stoler or vrimle
	venueLayouts[nr]->add(zonePtr);								//	Adds back
	venueLayouts[nr]->destroy(zName);							//	Deletes it

	if (zoneTyp == 0)
	{
		venueLayouts[nr]->add(new Stoler(zName, stoler));		//	Makes new with same name
	}
	if (zoneTyp == 1)
	{
		venueLayouts[nr]->add(new Vrimle(zName, vrimle));		//	Makes new with same name
	}

	
}
void Sted::displayLayout() {
    int layoutNo;
	Sone* tmpZone;
	

	
	if (lastUsedLayout > 0)
	{
		layoutNo = read("WHICH LAYOUT TO DISPLAY?", 1, lastUsedLayout);

		for (int i = 1; i <= venueLayouts[layoutNo]->noOfElements(); i++) //Loops thru all sones
		{
			tmpZone = (Sone*)venueLayouts[layoutNo]->removeNo(i);
			tmpZone->display();                     //Displayes zones
			venueLayouts[layoutNo]->add(tmpZone);
		}
	}
	else
	{
		printError("VENUE HAS NO LAYOUTS YET!");
	}
	


}

