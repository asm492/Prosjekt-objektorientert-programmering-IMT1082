#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <fstream>
#include <iostream>
#include "Vrimle.h"
#include "ListTool2B.h"
#include "Sone.h"
#include "functions.h"

using namespace std;

Vrimle::Vrimle(char name[], enum zoneType type) : Sone(name, type) {
    space = new int[ticketsForSale];
}

Vrimle::Vrimle(char name[], ifstream & inn, enum zoneType type) : Sone(name, inn, type)
{
	space = new int[ticketsForSale];  // +1 ???space = new int[ticketsForSale + 1];
	inn.ignore();
}
Vrimle::Vrimle(Vrimle & v, enum zoneType type) : Sone((Sone*)&v, type ) {
	space = new int[ticketsForSale + 1];			//	Make new array, '* space' points to this
	for (int i = 1; i <= ticketsForSale; i++) {
		space[i] = 0;								//	Initializing array
	}
}
int Vrimle::purchaseSwarm(int cNr)
{
	if ((ticketsForSale - ticketsSold) > 0)
	{
		ticketsSold++;
		return 1;
	}
	else
	{
		printError("SOLD OUT!");
		return 0;
	}
}
void Vrimle::writeToFile(ofstream & out)
{
	Sone::writeToFile(out);
}
void Vrimle::display(){
    
    Sone::display();
}
Vrimle::~Vrimle() {
	space = nullptr;
}

