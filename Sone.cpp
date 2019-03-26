#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "functions.h"
#include "Sone.h"
#include <iostream>

using namespace std;

Sone::Sone(char n[]) {
    
    zoneName = new char[strlen(n) + 1];
    strcpy(zoneName, n);
    
    swarmList = new List(Sorted);
    seatList = new List(Sorted);
}

Sone::~Sone() {
    
}

void Sone::display() {
    cout << "\nZone name:        " << zoneName << endl;
    cout << "Tickets for sale: " << ticketsForSale << endl;
    cout << "Ticket price:     " << ticketPrice << endl;
    
}
