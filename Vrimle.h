#ifndef Vrimle_h
#define Vrimle_h

#include "Sone.h"
#include "ListTool2B.h"
#include <stdio.h>
#include <fstream>
#include "enums.h"

using namespace std;

class Vrimle : public Sone {
private:
    
    int* space = nullptr;
	//enum zoneType type;
    //int soldToCustNo[ticketsForSale + 1]; MŒ ha dynamic array eller liste
public:
    
	Vrimle(char name[], enum zoneType type);
	Vrimle(char name[], ifstream & inn, enum zoneType type);
	Vrimle(Vrimle & v, enum zoneType type);
	~Vrimle();
	
	int purchaseSwarm(int cNr);
	void writeToFile(ofstream & out);
    void display();
	
    
};



#endif
