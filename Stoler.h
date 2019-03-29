#ifndef Stoler_h
#define Stoler_h

#include "conster.h"
#include "Sone.h"

class Stoler : public Sone {
private:
    //int seatConfig[MAXLAYOUTS + 1][MAXLAYOUTS + 1];            //    Usikker p� om denne faktisk skal med
    int seatPrRow, rows;
	int** tempArray;
    
public:
    
    Stoler(char name[]);
    
    void display();
    void configureSeats();
    void printSeatMap();
    
};

#endif
