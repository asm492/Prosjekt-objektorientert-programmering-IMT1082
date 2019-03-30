#ifndef Sone_h
#define Sone_h

#include <stdio.h>
#include <fstream>
#include "ListTool2B.h"

using namespace std;

class Sone : public TextElement {
protected:
    char* zoneName;
    int ticketsForSale;                 //    DO NOT INCREMENT!
    int ticketsSold, ticketPrice;
    //List* seatList;                                        //    Stoler
    //List* swarmList;                                    //    Vrimle
public:
	Sone(char n[]);		//	NEW
	Sone(char n[], ifstream & inn);
	~Sone();
    
    void display();
	void writeToFile(ofstream & out);
    
};

#endif
