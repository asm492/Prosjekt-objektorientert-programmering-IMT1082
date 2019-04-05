#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "ListTool2B.h"
#include "Oppsett.h"
#include <fstream>
#include "Sone.h"
#include "Stoler.h"
#include "ListTool2B.h"
#include "Sted.h"
#include "functions.h"
#include "Vrimle.h"
#include "enums.h"
#include <cstring>

using namespace std;



Oppsett::Oppsett(int n) : NumElement(n){
	//seatsLayout = new List(Sorted);
	//swarmLayout = new List(Sorted);
	Stoler* tempSeat;
	Vrimle* tempVrimle;
	char command, ch;
	char buffer[STRLEN];

	zoneList = new List(Sorted);
	
	do
	{
		read("DESIRED NAME FOR NEW ZONE?", buffer, STRLEN);
	
		cout << "\n(S)EATS or S(W)ARM?: ";
		command = read();


		switch (command)
		{
		case 'S': 
			tempSeat = new Stoler(buffer, stoler);
			zoneList->add(tempSeat);					break;
		case 'W': 
			tempVrimle = new Vrimle(buffer, vrimle);	
			zoneList->add(tempVrimle);					break;
		default: printError("INVALID COMMAND");			break;
		}

		//cout << "\nNUMBER OF ZONES IN THIS LAYOUT ";
		//cout << seatsLayout->noOfElements() + swarmLayout->noOfElements() << endl;

		cout << "\nCONTINIUE TO ADD MORE ZONES? (Y/N):   "; ch = read();

	} while (ch == 'Y');
}
Oppsett::Oppsett(int n, ifstream & inn) : NumElement(n) {
	char nameOfZone[STRLEN];
	char buffer[STRLEN];
	enum zoneType typeOfZone;
	int noOfZones, zoneNo;
	Stoler* tempSeat;
	Vrimle* tempSwarm;
		
	zoneList = new List(Sorted);
	//seatsLayout = new List(Sorted);
	//swarmLayout = new List(Sorted);
	
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
			zoneList->add(tempSeat);
		}

		if (strcmp(buffer, "vrimle") == 0)
		{
			typeOfZone = vrimle;
			inn.getline(nameOfZone, STRLEN); //inn.ignore();
			tempSwarm = new Vrimle(nameOfZone, inn, typeOfZone);
			zoneList->add(tempSwarm);
		}


		//	FOR TESTING

		if (strcmp(buffer, "stoler") == 0 && strcmp(buffer, "vrimle") == 0)
		{
			cout << "OPPSETT::OPPSETT(ifstream): DON'T MIND ME! AN ERROR OCCURED, I AM JUST HERE TO HELP YOU:\n";
			cout << "\n\nBUFFER/ZONE NAME: " << buffer << " / " << nameOfZone;
			cout << "\nSTRLEN(BUFFER) / STRLEN(ZONENAME): " << strlen(buffer) << " / " << strlen(nameOfZone) << endl;
		}

		

	}
}
void Oppsett::writeToFile(ofstream & out) {
	Stoler* seatPtr;
	Vrimle* swarmPtr;
	Sone* zonePtr;
	int totalZones;
	//int zoneCounter = 0;
	int temp;
	
	totalZones = zoneList->noOfElements();
	
	out << totalZones << '\n';									//	Total zones in this layout

	for (int i = 1; i <= totalZones; i++)
	{
		out << i << '\n';
		zonePtr = (Sone*)zoneList->removeNo(i);
		temp = zonePtr->returnZoneType();
		zoneList->add(zonePtr);

		if (temp == 0)
		{
			out << "stoler" << '\n';
			seatPtr = (Stoler*)zoneList->removeNo(i);
			seatPtr->writeToFile(out);
			zoneList->add(seatPtr);
		}
		if (temp == 1)
		{
			out << "vrimle" << '\n';
			swarmPtr = (Vrimle*)zoneList->removeNo(i);
			swarmPtr->writeToFile(out);
			zoneList->add(swarmPtr);
		}
	}

	

}
void Oppsett::newLayout() {			//	SHOULD THIS BE INN THE OPPSETT() constructor instead?
	
	// THIS HAS BEEN MOVED TO THE CONSTRUCTOR								
/*
	char command, ch;
	char buffer[STRLEN];
	
	do
	{
		read("DESIRED NAME FOR NEW ZONE?", buffer, STRLEN);
		

		cout << "\n(S)EATS or S(W)ARM?: ";
		command = read();


		switch (command)
		{
		case 'S': seatsLayout->add(new Stoler(buffer));	break;	
		case 'W': swarmLayout->add(new Vrimle(buffer));	break;	
		default: printError("INVALID COMMAND");			break;
		}

		//cout << "\nNUMBER OF ZONES IN THIS LAYOUT ";
		//cout << seatsLayout->noOfElements() + swarmLayout->noOfElements() << endl;

		cout << "\nCONTINIUE TO ADD MORE ZONES? (Y/N):   "; ch = read();

	} while (ch == 'Y');
	*/
}

void Oppsett::addNewZone()
{										//	Almost the same as Oppsett(), but doesnt
										//	point to a new list
	Stoler* tempSeat;
	Vrimle* tempVrimle;
	char command, ch;
	char buffer[STRLEN];

	do
	{
		read("DESIRED NAME FOR NEW ZONE?", buffer, STRLEN);

		cout << "\n(S)EATS or S(W)ARM?: ";
		command = read();


		switch (command)
		{
		case 'S':
			tempSeat = new Stoler(buffer, stoler);
			zoneList->add(tempSeat);					break;
		case 'W':
			tempVrimle = new Vrimle(buffer, vrimle);
			zoneList->add(tempVrimle);					break;
		default: printError("INVALID COMMAND");			break;
		}

		//cout << "\nNUMBER OF ZONES IN THIS LAYOUT ";
		//cout << seatsLayout->noOfElements() + swarmLayout->noOfElements() << endl;

		cout << "\nCONTINIUE TO ADD MORE ZONES? (Y/N):   "; ch = read();

	} while (ch == 'Y');
}

bool Oppsett::deleteLayout()
{
	bool deleteConfirmation = false;
	char ch;

	cout << "\nThis layout has the following zones in it:" << endl;
	zoneList->displayList();

	cout << "DELETING THE LAYOUT WILL ALSO DELETE THE ZONES. CONTINIUE?\n";
	ch = read();

	if (ch == 'Y')
	{
		for (int i = 1; i <= zoneList->noOfElements(); i++)
		{
			zoneList->destroy(i);
		}
		deleteConfirmation = true;
	}
	else {
		cout << "\nABORTING DELETION" << endl;
	}



	return deleteConfirmation;
}

bool Oppsett::removeZone()
{
	bool deleteConfirmation = false;
	char command, ch;
	char buffer[STRLEN];

	
	cout << "\nWOULD YOU LIKE TO SEE A LIST OF ALL THE ZONES IN THIS LAYOUT? (Y/N)" << endl;
	ch = read();
	if (ch == 'Y')
	{
		zoneList->displayList();
	}

	cout << "\n";
	read("WHICH ZONE TO DELETE", buffer, STRLEN);

	if (zoneList->inList(buffer))
	{
		zoneList->displayElement(buffer);
		
		if (zoneList->noOfElements() == 1)
		{
			cout << "THIS IS THE LAST REMAINING ZONE IN THIS LAYOUT. ";
			cout << "\nREMOVING/DELETING THIS ZONE WILL AUTOMATICALLY ALSO DELETE THIS LAYOUT." << endl;
		}

		cout << "\n\nARE YOU SURE YOU WANT TO DELETE? (Y/N):" << endl;
		command = read();
		
		if (command == 'Y')
		{
			zoneList->destroy(buffer);
		}
	}
	else
		cout << "\n\nNO RESULTS FOR '" << buffer << "'!";

	if (zoneList->noOfElements() == 0)
	{
		deleteConfirmation = true;
		delete zoneList;
		
	}
	
	return deleteConfirmation;
}
Oppsett::~Oppsett() {

}

int Oppsett::retNoElements()
{
	return zoneList->noOfElements();
}

List* Oppsett::getZoneList()
{

	/*TROR IKKE VI TRENGER DENNE
	Å LAGE NO ANNEN INNMAT HER ENN DET SOM ER I 
	List * Oppsett::copyZone(). 
	DENNE KAN EVT KALLE PÅ DEN*/

	//Nullptr er bare midlertidig for å få dette til å funke
	return nullptr;
}

List* Oppsett::copyZone()
{
	int totalZones, i, temp;
	Sone *zonePtr, *zoneCopyPtr;
	List* zoneListCopy = NULL;

	cout << "\n10";
	
	totalZones = zoneList->noOfElements();
	/*
	if (totalZones)
	{

	}
	else {
		zoneCopyPtr = nullptr;
	}*/

	cout << "\n6";
	zoneListCopy = new List(Sorted);
	for (i = 1; i <= totalZones; i++) {
		zonePtr = (Sone*)zoneList->removeNo(i);
		temp = zonePtr->returnZoneType();
		zoneList->add(zonePtr);

		if (temp == 0) {
			zoneCopyPtr = new Stoler(*((Stoler*)zonePtr));		//	Makes new Stoler
		}
		else
		{
			zoneCopyPtr = new Vrimle(*((Vrimle*)zonePtr));
		}

		zoneList->add(zonePtr);								//	Adds back to old list 
		zoneListCopy->add(zonePtr);							//	and to new list
		cout << "\n7";
	}

	cout << "\n8";
	return zoneListCopy;
}

void Oppsett::display() {
	zoneList->displayList();
}
