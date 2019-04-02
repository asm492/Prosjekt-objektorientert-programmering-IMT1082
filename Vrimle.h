#ifndef Vrimle_h
#define Vrimle_h
#include "Sone.h"
#include "ListTool2B.h"
#include <stdio.h>
#include <fstream>

using namespace std;

class Vrimle : public Sone {
private:
    
    int* space = nullptr;
    //int soldToCustNo[ticketsForSale + 1]; MŒ ha dynamic array eller liste
public:
    Vrimle(char name[]);
	Vrimle(char name[], ifstream & inn);

	void writeToFile(ofstream & out);
    void display();
    
};



#endif
