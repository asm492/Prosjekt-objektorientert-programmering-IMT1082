#ifndef Stoler_h
#define Stoler_h

#include <iostream>
#include <fstream>
#include <cstring>
#include "Stoler.h"
#include "Sone.h"
#include "Sted.h"     
#include "enums.h"

using namespace std;

class Stoler : public Sone {
private:
    
    int seatPrRow, rows;
	int** tempArray = nullptr;
	
	
public:
	~Stoler();
	Stoler(Stoler & s);
    Stoler(char name[], enum zoneType type);
	Stoler(char name[], ifstream & inn, enum zoneType type);
    void display();
    void configureSeats();
    void printSeatMap();
	void printSeatMapAvailibility();
	void writeToFile(ofstream & out);
};

#endif
