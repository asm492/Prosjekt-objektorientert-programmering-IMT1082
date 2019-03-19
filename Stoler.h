#ifndef Stoler_h
#define Stoler_h

#include "conster.h"
#include "Sone.h"

class Stoler : public Sone {
private:
	int seatConfig[MAXCONFIG + 1][MAXCONFIG + 1];
	int seatPrRow, rows;
	
	
public:
	void configureSeats();
};

#endif 

