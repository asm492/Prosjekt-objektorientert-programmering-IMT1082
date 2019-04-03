#ifndef Oppsett_h
#define Oppsett_h

#include <iostream>
#include "ListTool2B.h"
#include <fstream>


using namespace std;

class Oppsett : public NumElement {
private:
	List* seatsLayout;		// IKKE BRUK
	List* swarmLayout;		// IKKE BRUK
	List* zoneList;
public:
	Oppsett(int n);
	Oppsett(int n, ifstream & inn);

	void display();
	void printLayouts();				
	void writeToFile(ofstream & out);
	void newLayout();
	int retNoElements();
	
	//void addToList(Stoler* tmpSeat);
	//void a
};

#endif
