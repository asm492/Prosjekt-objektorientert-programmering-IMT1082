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

	zoneList = new List(Sorted);
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

		if (strcmp(buffer, "Stoler") == 0)
		{
			typeOfZone = stoler;
			inn.getline(nameOfZone, STRLEN); //inn.ignore();
			tempSeat = new Stoler(nameOfZone, inn, typeOfZone);
			zoneList->add(tempSeat);
		}

		if (strcmp(buffer, "Vrimle") == 0)
		{
			typeOfZone = vrimle;
			inn.getline(nameOfZone, STRLEN); //inn.ignore();
			tempSwarm = new Vrimle(nameOfZone, inn, typeOfZone);
			zoneList->add(tempSwarm);
		}


		//	FOR TESTING

		cout << "\n\nBUFFER/ZONE NAME: " << buffer << " / " << nameOfZone;
		cout << "\nSTRLEN(BUFFER) / STRLEN(ZONENAME): " << strlen(buffer) << " / " << strlen(nameOfZone) << endl;

	}

	/*
	for (int i = 1; i <= noOfZones; i++)
	{
		inn >> zoneNo; 
		inn.ignore();
		
		inn.getline(buffer, STRLEN); //inn.ignore();					//????????????
		
		if (strcmp(buffer, "Stoler") == 0)
		{
			inn.getline(nameOfZone, STRLEN); //inn.ignore();
			tempSeat = new Stoler(nameOfZone, inn);
			seatsLayout->add(tempSeat);
		}

		if (strcmp(buffer, "Vrimle") == 0)
		{
			inn.getline(nameOfZone, STRLEN); //inn.ignore();
			tempSwarm = new Vrimle(nameOfZone, inn);
			swarmLayout->add(tempSwarm);
		}


		//	FOR TESTING
		
		cout << "\n\nBUFFER/ZONE NAME: " << buffer << " / " << nameOfZone;	
		cout << "\nSTRLEN(BUFFER) / STRLEN(ZONENAME): " << strlen(buffer) << " / " << strlen(nameOfZone) << endl;
			
	}
	*/
}
void Oppsett::printLayouts()
{

	/*Innmaten er fyttet til Oppsett::display*/
	/*Sted::displayLayouts kaller på denne funksjonen, husk å 
	endre der til Oppsett::display*/
	if ((seatsLayout->noOfElements()) > 0)
	{
		cout << "\nSEATS:" << endl;
		seatsLayout->displayList();
	}

	if ((swarmLayout->noOfElements()) > 0)
	{
		cout << "\nSWARM:" << endl;
		swarmLayout->displayList();
	}
	
}
void Oppsett::writeToFile(ofstream & out) {
	Stoler* seatPtr;
	Vrimle* swarmPtr;
	Sone* zonePtr;
	int totalZones, totalSeats, totalSwarm;
	int zoneCounter = 0;

	//totalSeats = seatsLayout->noOfElements();
	//totalSwarm = swarmLayout->noOfElements();
	totalZones = zoneList->noOfElements();
	
	out << totalZones << '\n';									//	Total zones in this layout

	for (int i = 1; i <= totalZones; i++)
	{
		out << i << '\n';
		zonePtr = (Sone*)zoneList->removeNo(i);
		/**/
	}

	/*
	for (int i = 1; i <= totalSeats; i++)
	{
		out << ++zoneCounter << '\n';
		out << "Stoler" << '\n';
		seatPtr = (Stoler*)seatsLayout->removeNo(i);
		seatsLayout->add(seatPtr);
		seatPtr->writeToFile(out);
	}

	for (int i = 1; i <= totalSwarm; i++)
	{
		out << ++zoneCounter << '\n';
		out << "Vrimle" << '\n';
		swarmPtr = (Vrimle*)swarmLayout->removeNo(i);
		swarmLayout->add(swarmPtr);
		swarmPtr->writeToFile(out);
	}*/
	/*
	for (int j = 1; j <= totalZones;  j++)						
	{
		out << j << '\n';										//	Prints zone number to file 
		
		for (int i = 1; i <= seatsLayout->noOfElements(); i++)
		{
			out << "Stoler" << '\n';
			seatPtr = (Stoler*)seatsLayout->removeNo(i);
			seatsLayout->add(seatPtr);
			seatPtr->writeToFile(out);
		}

		for (int i = 1; i <= swarmLayout->noOfElements(); i++)
		{
			out << "Vrimle" << '\n';
			swarmPtr = (Vrimle*)swarmLayout->removeNo(i);
			swarmLayout->add(swarmPtr);
			swarmPtr->writeToFile(out);
		}
	}
	*/

}
void Oppsett::newLayout() {			//	SHOULD THIS BE INN THE OPPSETT() constructor instead?
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
}

int Oppsett::retNoElements()
{
	return 0;
}

void Oppsett::display() {
	
	cout << seatsLayout->noOfElements();

	if ((seatsLayout->noOfElements()) > 0)
	{
		cout << "\nSEATS:" << endl;
		seatsLayout->displayList();
		cout << "TEST SEAATT";
	}

	if ((swarmLayout->noOfElements()) > 0)
	{
		cout << "\nSWARM:" << endl;
		swarmLayout->displayList();
		cout << "TEST";
	}
}
