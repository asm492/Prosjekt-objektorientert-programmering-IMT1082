
#ifndef Sone_h
#define Sone_h

#include <stdio.h>
#include "ListTool2B.h"

class Sone : public TextElement {
private:
    char* zoneName;
    int ticketsForSale, ticketsSold, ticketPrice;
public:
    Sone();
    ~Sone();

	void display();

	
};

#endif
