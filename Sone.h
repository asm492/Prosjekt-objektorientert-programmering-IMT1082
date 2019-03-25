
#ifndef Sone_h
#define Sone_h

#include <stdio.h>
#include "ListTool2B.h"

class Sone : public TextElement {
private:
    char* zoneName;
    int ticketsForSale; 				//	DO NOT INCREMENT! 		
	int ticketsSold, ticketPrice;
	List* seatList;										//	Stoler
	List* swarmList;									//	Vrimle
public:
    Sone();
    ~Sone();

	void display();

	
};

#endif
