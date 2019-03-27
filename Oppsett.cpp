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
#include "Vrimle.h"

using namespace std;

Oppsett::Oppsett() {
	seatsLayout = new List(Sorted);
	swarmLayout = new List(Sorted);
}
void Oppsett::writeToFile(ofstream & out) {
    
}
void Oppsett::newLayout() {			//	SHOULD THIS BE INN THE OPPSETT() constructor instead?
	char command;
	char buffer[STRLEN];

	cout << "\nNEW ZONE:";
	read("Enter desired name for the new zone", buffer, STRLEN);

	cout << "\n(S)EATS or S(W)ARM?: ";
	command = read();
	

	switch (command)
	{
	case 'S': seatsLayout->add(new Stoler(buffer));	break;
	case 'W': swarmLayout->add(new Vrimle(buffer));	break;
	default: printError("INVALID COMMAND");			break;
	}
}

