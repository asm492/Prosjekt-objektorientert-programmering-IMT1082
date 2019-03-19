#ifndef Stoler_h
#define Stoler_h

#include "conster.h"
#include "Sone.h"

class Stoler : public Sone {
private:
	int seatConfig[MAXLAYOUTS + 1][MAXLAYOUTS + 1];			//	Usikker på om denne faktisk skal med
	int seatPrRow, rows;


public:
	Stoler();
	void configureSeats();
	void printSeatMap();
};

#endif 