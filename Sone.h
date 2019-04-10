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
    int ticketsForSale;
    int ticketsSold, ticketPrice;
	enum zoneType typeOfZone;
  
public:
	Sone(char n[], enum zoneType type);						
	Sone(char n[], ifstream & inn, enum zoneType type);
	Sone(Sone* s, enum zoneType type);
	~Sone();
    
	char* returnZoneName();
	int getPrice();
	int returnZoneType();
    void display();
	void writeToFile(ofstream & out);
	
    
};

#endif
