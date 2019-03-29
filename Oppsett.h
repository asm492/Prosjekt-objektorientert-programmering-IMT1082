#ifndef Oppsett_h
#define Oppsett_h

#include <iostream>
#include "ListTool2B.h"
#include <fstream>


using namespace std;

class Oppsett {
private:
	List* seatsLayout;
	List* swarmLayout;
public:
	Oppsett();

	void printLayouts();				
	void writeToFile(ofstream & out);
	void newLayout();
	
};

#endif
