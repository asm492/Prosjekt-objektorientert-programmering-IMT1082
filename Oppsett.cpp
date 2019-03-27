#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "ListTool2B.h"
#include "Oppsett.h"
#include <fstream>
#include "Sone.h"
#include "Stoler.h"
#include "ListTool2B.h"
#include "Sted.h"
#include "functions.h"

using namespace std;

Oppsett::Oppsett() {
	seatsLayout = new List(Sorted);
	swarmLayout = new List(Sorted);
}
void Oppsett::writeToFile(ofstream & out) {
    
}
void newLayout() {
	int evntNr;
	int lastUsedVenue;
		
	evntNr = read("Which venue do you want to add a new layout to?", 1, 1);
}

