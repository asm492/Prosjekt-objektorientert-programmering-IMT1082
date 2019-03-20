
#ifndef Vrimle_h
#define Vrimle_h
#include "Sone.h"
#include "ListTool2B.h"

#include <stdio.h>

class Vrimle : public Sone {
private:
    int numbOfSpots, ticketPrice, soldTickets;
    int** space;
public:
    Vrimle();
    void display();
    void configVrimle();
};



#endif
