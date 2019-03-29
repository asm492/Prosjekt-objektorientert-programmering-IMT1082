#ifndef Stoler_h
#define Stoler_h

#include <iostream>
#include <fstream>
#include <cstring>
#include "Stoler.h"
#include "Sone.h"
#include "Sted.h"       

class Stoler : public Sone {
private:
    //int seatConfig[MAXLAYOUTS + 1][MAXLAYOUTS + 1];            //    Usikker på om denne faktisk skal med
    int seatPrRow, rows;
	int** tempArray;
    
public:
    
    Stoler(char name[]);
    
    void display();
    void configureSeats();
    void printSeatMap();
	void writeToFile(ofstream & out);
};

#endif
