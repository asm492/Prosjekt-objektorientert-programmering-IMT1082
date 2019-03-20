#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <iostream>
#include "Vrimle.h"
#include "ListTool2B.h"

using namespace std;

Vrimle::Vrimle() {
    
}

void Vrimle::display(){
    cout << "\n#Type: Vrimle" << "\t#Number of spots: " << numbOfSpots
    << "\n#Price pr. ticket: " << ticketPrice << "NOK\t#Tickets left: "
    << numbOfSpots-soldTickets;
}

void Vrimle::configVrimle(){
    
    cout << "\n\nNumber of tickets to be sold in sone?: "; cin >> numbOfSpots;
    cout << "\nPrice pr. ticket?: "; cin >> ticketPrice;
    
    space = new int* [numbOfSpots + 1];
    
    for (int i = 1; i <= numbOfSpots + 1; i++)
        space[i] = nullptr;
}



