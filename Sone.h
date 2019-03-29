#ifndef Sone_h
#define Sone_h

#include <stdio.h>
#include <fstream>
#include "ListTool2B.h"

class Sone : public TextElement {
protected:
    char* zoneName;
    int ticketsForSale;                 //    DO NOT INCREMENT!
    int ticketsSold, ticketPrice;
    //List* seatList;                                        //    Stoler
    //List* swarmList;                                    //    Vrimle
public:
	Sone(char n[]);		//	NEW
    ~Sone();
    
    void display();
	void writeToFile(ofstream & out);
    
};

#endif
