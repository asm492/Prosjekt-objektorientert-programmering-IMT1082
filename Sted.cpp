
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include "Sted.h"
#include "Stoler.h"
#include "Vrimle.h"
#include "Sone.h"
#include "Oppsett.h"
#include "ListTool2B.h"
#include <cstring>

using namespace std;

Sted::Sted(char n[]) : TextElement(n) {
    
	lastUsedLayout = 0;

	name = new char[strlen(n) + 1];
	strcpy(name, n);

	/*venueLayouts*/
	for (int i = 0; i <= MAXLAYOUTS; i++)
	{
		venueLayouts[i] = nullptr;
	}

	/*venueLayouts END*/

    
    
}
Sted::Sted(char n[], ifstream & inn) : TextElement(n) {
    int layoutNo;
	char nameOfZone[STRLEN];
	char buffer[STRLEN];
	enum zoneType typeOfZone;
	int noOfZones, layNo, zoneNo;
	Stoler* tempSeat;
	Vrimle* tempSwarm;
    
    name = new char[strlen(n) + 1];					//	Name of the venue
    strcpy(name, n);
    
    inn >> lastUsedLayout; //inn.ignore();
    
    for(int j = 1; j <= lastUsedLayout; j++){
        /************KODE FRA OPPSETT()***************/
		inn >> layNo;
		venueLayouts[j] = new List(Sorted);


		inn >> noOfZones; //inn.ignore();

		for (int i = 1; i <= noOfZones; i++)
		{
			inn >> zoneNo;
			inn.ignore();

			inn.getline(buffer, STRLEN); //inn.ignore();					//????????????

			if (strcmp(buffer, "stoler") == 0)
			{
				typeOfZone = stoler;
				inn.getline(nameOfZone, STRLEN); //inn.ignore();
				tempSeat = new Stoler(nameOfZone, inn, typeOfZone);
				venueLayouts[j]->add(tempSeat);
			}

			if (strcmp(buffer, "vrimle") == 0)
			{
				typeOfZone = vrimle;
				inn.getline(nameOfZone, STRLEN); //inn.ignore();
				tempSwarm = new Vrimle(nameOfZone, inn, typeOfZone);
				venueLayouts[j]->add(tempSwarm);
			}


			//	FOR TESTING

			if (strcmp(buffer, "stoler") == 0 && strcmp(buffer, "vrimle") == 0)
			{
				cout << "OPPSETT::OPPSETT(ifstream): DON'T MIND ME! AN ERROR OCCURED, I AM JUST HERE TO HELP YOU:\n";
				cout << "\n\nBUFFER/ZONE NAME: " << buffer << " / " << nameOfZone;
				cout << "\nSTRLEN(BUFFER) / STRLEN(ZONENAME): " << strlen(buffer) << " / " << strlen(nameOfZone) << endl;
			}



		}
		/***********KODE FRA OPPSETT() SLUTT *********/

		
    }
}
void Sted::writeToFile(ofstream & out) {				
	
	//HENTET FRA OPPSETT
	Sone* zonePtr;
	Stoler* seatPtr;
	Vrimle* swarmPtr;
	int temp;

	out << text << '\n';
	out << lastUsedLayout << '\n';

	for (int i = 1; i <= lastUsedLayout; i++)
	{
		out << i << '\n';									//Layout number
		out << venueLayouts[i]->noOfElements() << '\n';		//Zone number
		for (int j = 1; j <= venueLayouts[i]->noOfElements(); j++)
		{
			zonePtr = (Sone*)venueLayouts[i]->removeNo(i);
			venueLayouts[i]->add(zonePtr);

			if (zonePtr->returnZoneType() == 0)
			{
				venueLayouts[i]->add(zonePtr);
				out << "stoler" << '\n';
				seatPtr = (Stoler*)venueLayouts[i]->removeNo(i);
				seatPtr->writeToFile(out);
				venueLayouts[i]->add(seatPtr);
			}
			if (zonePtr->returnZoneType() == 1)
			{

				venueLayouts[i]->add(zonePtr);
				out << "vrimle" << '\n';
				swarmPtr = (Vrimle*)venueLayouts[i]->removeNo(i);
				swarmPtr->writeToFile(out);
				venueLayouts[i]->add(swarmPtr);
			}
		}
	}
}

void Sted::display(){
    cout << "\nVenue:             " << name;
	cout << "\nNumber of layouts: " << lastUsedLayout << endl;
}

void Sted::displayName(){
    cout << name;
}

void Sted::newSeatLayout() {
    char buffer[STRLEN];
   // Oppsett* tmp;
    if (lastUsedLayout < 5)
    {                                                    //    To do: copy
        cout << "\nCreating new layout:" << endl;
        read("Enter name for zone", buffer, STRLEN);
        //layouts[++lastUsedLayout] = (buffer);
        
    }
    else
    {
        printError("MAXIMUM NUMBER OF CONFIGURATIONS ARE ALREADY MADE!");
        
        
    }
    
}
void Sted::printSeatLayout() {
    int nr;
    
    if (lastUsedLayout > 0)
    {
        nr = read("Which layout do you want to display? Press '0' for all:", 0, lastUsedLayout);
        cout << '\n';
        if (nr != 0)
        {
            //layouts[nr]->printSeatMap();
        }
        else
        {
            for (int i = 1; i <= lastUsedLayout; i++)
            {
                //layouts[nr]->printSeatMap();
            }
        }
    }
    else
    {
        printError("NO LAYOUTS IN THE DATABASE");
    }
}
void Sted::displayLayouts()			//	TESTING
{
	int layoutNo, sone, layTemp;
    
    if (lastUsedLayout > 0){
	
        layoutNo = read("WHICH LAYOUT TO DISPLAY?", 1, lastUsedLayout);
        layTemp = venueLayouts[layoutNo]->noOfElements();
        sone = read("WHICH SONE DO YOU WANT TP DISPLAY? (0 for all)", 0, layTemp);
	
        if (sone == 0)
        {
            cout << "\nLAYOUT NO " << layoutNo << " FOR " << name << ':' << endl;
            venueLayouts[layoutNo]->displayList();
            
        }
	else
		venueLayouts[layoutNo]->displayElement(sone);
	
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

	if (layoutN <= lastUsedLayout) {
		ant = venueLayouts[layoutN]->noOfElements();

		liste = new List(Sorted);

		for (i = 1; i <= ant; i++) {

			sone = (Sone*)venueLayouts[layoutN]->removeNo(i);

			if (sone->returnZoneType() == 0)
				kopi = new Stoler(*((Stoler*)sone), stoler);
			else
				kopi = new Vrimle(*((Vrimle*)sone), vrimle);

			venueLayouts[layoutN]->add(sone);
			liste->add(kopi);
		}
	}
		cout << "\nSTED BOTTOM";
		return liste;
}
	
	
	//return newList
/*
List * Sted::kopier(int nr)
{
	
	List* list = NULL;
	int i, ant;
	Sone *sone, *kopi;

	if (nr >= 1 && nr <= lastUsedLayout) {
		
		ant = layouts[nr]->noOfElements();

		list = new List(Sorted);
		for (i = 1; i <= ant; i++) {
			sone = (Sone*)layouts[nr]->removeNo(i);
			if (*sone == 'S')  kopi = new Stoler(*((Stoler*)sone));
			else kopi = new Vrimle(*((Vrimle*)sone));
			oppsett[nr]->add(sone);
			list->add(kopi);
		}
	}
	return list;
}*/
void Sted::newLayout() {
	char command;

	cout << "\nCURRENT NUMBER OF LAYOUTS: " << lastUsedLayout;
    
	if (lastUsedLayout < 5)
    {
		cout << "\nCreate layout from (S)cratch or (C)opy?: ";
		command = read();

		do
		{
			switch (command)
			{
			case 'S':
				cout << "\nCRATING LAYOUT NO. " << ++lastUsedLayout << " for " << name << ":\n\n";
				venueLayouts[lastUsedLayout] = new List(Sorted);
				//layouts[lastUsedLayout]->newLayout(); break;		//PROGRAM STOPS HERE. TAKE A LOOK AT OPPSETT()....STED.CPP

			case 'C': /*newLayoutFromCopy();*/
				//cout << "\nCRATING LAYOUT NO. " << ++lastUsedLayout << " for " << name << ":\n\n";
				/*layouts[lastUsedLayout] = new Oppsett();*/				break;

			default: printError("INVALID COMMAND, TRY AGAIN. S/C: ");	break;
			}
		} while (command != 'S' && command != 'C');

		
    }
    else
        printError("THIS VENUE HAS REACHED ITS MAX NO. OF LAYOUTS!");
}
void Sted::newLayoutFromCopy() {
	char buffer[STRLEN];
	

	read("WHICH LAYOUT NR. TO COPY FROM?", buffer, STRLEN);

	
	++lastUsedLayout;
}
int Sted::compareVenueName(char text[]){
    return !strcmp(name, text);
}

void Sted::newVenueLayout(){
	char command;

	cout << "\nCURRENT NUMBER OF LAYOUTS: " << lastUsedLayout;

	if (lastUsedLayout < 5)
	{
		cout << "\nCreate layout from (S)cratch or (C)opy?: ";
		command = read();

		do
		{
			switch (command)
			{
			case 'S':
				cout << "\nCRATING LAYOUT NO. " << ++lastUsedLayout << " for " << name << ":\n\n";
				venueLayouts[lastUsedLayout] = new List(Sorted);
				addZones(lastUsedLayout);									break;

			case 'C': /*newLayoutFromCopy();*/
				//cout << "\nCRATING LAYOUT NO. " << ++lastUsedLayout << " for " << name << ":\n\n";
				/*layouts[lastUsedLayout] = new Oppsett();*/				break;

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

		switch (command)
		{
		case 'S':
			tempSeat = new Stoler(buffer, stoler);
			venueLayouts[nr]->add(tempSeat);			break;														
		case 'W':
			tempVrimle = new Vrimle(buffer, vrimle);
			venueLayouts[nr]->add(tempVrimle);			break;

		default: printError("INVALID COMMAND");			break;
		}

		cout << "\nCONTINIUE TO ADD MORE ZONES? (Y/N):   "; ch = read();

	} while (ch == 'Y');
}
void Sted::editLayout() {
	int nr;
	char ch, command;
    char sone[STRLEN];
	if (lastUsedLayout > 0)
	{
		nr = read("WHICH LAYOUT TO EDIT?", 1, lastUsedLayout);
        read("WHICH ZONE TO EDIT?: ", sone, STRLEN);
        
        if (venueLayouts[nr]->inList(sone))
        {
            cout << "\nWHAT DO YOU WANT TO DO TO SONE. " << sone << "?:" << endl;
            cout << "\n\tA\tAdd new zone from scratch";
            cout << "\n\tC\tAdd new zone from a copy";
            cout << "\n\tR\tRemove a zone";
            cout << "\n\tD\tChange the details" << endl;
           
            ch = read();
            switch (ch)
            {
            case 'A': addZones(nr);		break;
            case 'C': /*layouts[nr]->addNewCopy();*/	break;
            case 'R': venueLayouts[nr]->destroy(sone);                     break;
            case 'D':
                default: printError("INVALID COMMAND!");	break;
            }
        }
        else {
            printError("THIS VENUE HAS NO LAYOUTS! ADD NEW LAYOUT? (Y/N):");
            command = read();
            if (command == 'Y')
            {
			newVenueLayout();
            }
        }
    }
}
void Sted::displayLayout() {
	int layoutNo, seatOrSwarm;
	Sone* tmpZone;
	Stoler* tmpSeat;
	Vrimle* tmpSwarm;

	
	if (lastUsedLayout > 0)
	{
		layoutNo = read("WHICH LAYOUT TO DISPLAY?", 1, lastUsedLayout);

		for (int i = 1; i <= venueLayouts[layoutNo]->noOfElements(); i++)
		{
			/*
			tmpZone = (Sone*)venueLayouts[layoutNo]->removeNo(i);
			seatOrSwarm = tmpZone->getType();
			venueLayouts[layoutNo]->add(tmpZone);

			if (seatOrSwarm == 0)
			{
				tmpSeat = (Stoler*)venueLayouts[layoutNo]->removeNo(i);
				tmpSeat->display();
				venueLayouts[layoutNo]->add(tmpSeat);
			}
			else if (seatOrSwarm == 1)
			{
				tmpSwarm = (Vrimle*)venueLayouts[layoutNo]->removeNo(i);
				tmpSwarm->display();
				venueLayouts[layoutNo]->add(tmpSwarm);
			}*/
			tmpZone = (Sone*)venueLayouts[layoutNo]->removeNo(i);
			tmpZone->display();
			venueLayouts[layoutNo]->add(tmpZone);
		}
	}
	else
	{
		printError("VENUE HAS NO LAYOUTS YET!");
	}
	


}

void Sted::displayTest(int i) {

	Sone* tmpZone;


	for (int j = 1; j <= venueLayouts[i]->noOfElements(); j++)
	{
		tmpZone = (Sone*)venueLayouts[i]->removeNo(j);
		tmpZone->display();
		venueLayouts[i]->add(tmpZone);
	}
}
