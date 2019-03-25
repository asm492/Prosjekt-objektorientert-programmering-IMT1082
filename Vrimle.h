
#ifndef Vrimle_h
#define Vrimle_h
#include "Sone.h"
#include "ListTool2B.h"

#include <stdio.h>

class Vrimle : public Sone {
private:
    int numbOfSpots, ticketPrice, soldTickets;
    int** space;
	int soldToCustNo[ticketsForSale + 1];
public:
    Vrimle(char n[]);
    void display();
    void configVrimle();
};



#endif
