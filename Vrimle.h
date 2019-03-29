#ifndef Vrimle_h
#define Vrimle_h
#include "Sone.h"
#include "ListTool2B.h"
#include <stdio.h>

using namespace std;

class Vrimle : public Sone {
private:
    int numbOfSpots;
    int* space = nullptr;
    //int soldToCustNo[ticketsForSale + 1]; MŒ ha dynamic array eller liste
public:
    Vrimle(char name[]);
    void display();
    void configVrimle();
};



#endif
