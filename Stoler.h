#ifndef Stoler_h
#define Stoler_h

#include <iostream>
#include <fstream>
#include <cstring>
#include "Stoler.h"
#include "Sone.h"
#include "Sted.h"     
#include "enums.h"

class Stoler : public Sone {
private:
    //int seatConfig[MAXLAYOUTS + 1][MAXLAYOUTS + 1];            //    Usikker på om denne faktisk skal med
    int seatPrRow, rows;
	int** tempArray = nullptr;
	enum zoneType typeOfZone = stoler;
public:
    
    Stoler(char name[]);
	Stoler(char name[], ifstream & inn, enum zoneType type);
    void display();
    void configureSeats();
    void printSeatMap();
	void printSeatMapAvailibility();
	void writeToFile(ofstream & out);
};

#endif
