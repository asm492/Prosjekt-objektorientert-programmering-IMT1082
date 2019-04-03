#ifndef Sone_h
#define Sone_h

#include <stdio.h>
#include <fstream>
#include "ListTool2B.h"
#include "enums.h"

using namespace std;

class Sone : public TextElement {
protected:
    char* zoneName;
    int ticketsForSale;                 //    DO NOT INCREMENT!
    int ticketsSold, ticketPrice;
	enum zoneType typeOfZone;
    //List* seatList;                                        //    Stoler
    //List* swarmList;                                    //    Vrimle
public:
	Sone(char n[], enum zoneType type);		//	NEW
	Sone(char n[], ifstream & inn, enum zoneType type);
	~Sone();
    
	int returnZoneType();
    void display();
	void writeToFile(ofstream & out);
	
    
};

#endif
