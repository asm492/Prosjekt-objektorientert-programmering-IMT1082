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

Oppsett::Oppsett(int n) : NumElement(n){
	seatsLayout = new List(Sorted);
	swarmLayout = new List(Sorted);
}
void Oppsett::printLayouts()
{
	if ((seatsLayout->noOfElements()) > 0)
	{
		cout << "\nSEATS:" << endl;
		seatsLayout->displayList();
	}

	if ((swarmLayout->noOfElements()) > 0)
	{
		cout << "\nSWARM:" << endl;
		swarmLayout->displayList();
	}
	
}
void Oppsett::writeToFile(ofstream & out) {
	Stoler* seatPtr;
//	Vrimle* swarmPtr;

	out << seatsLayout->noOfElements() << '\n';
	for (int i = 1; i <= seatsLayout->noOfElements(); i++)
	{
		seatPtr = (Stoler*)seatsLayout->removeNo(i);
		seatsLayout->add(seatPtr);
		seatPtr->writeToFile(out);
	}
}
void Oppsett::newLayout() {			//	SHOULD THIS BE INN THE OPPSETT() constructor instead?
	char command, ch;
	char buffer[STRLEN];
	
	do
	{
		read("DESIRED NAME FOR NEW ZONE?", buffer, STRLEN);
		

		cout << "\n(S)EATS or S(W)ARM?: ";
		command = read();


		switch (command)
		{
		case 'S': seatsLayout->add(new Stoler(buffer));	break;	
		case 'W': swarmLayout->add(new Vrimle(buffer));	break;	
		default: printError("INVALID COMMAND");			break;
		}

		//cout << "\nNUMBER OF ZONES IN THIS LAYOUT ";
		//cout << seatsLayout->noOfElements() + swarmLayout->noOfElements() << endl;

		cout << "\nCONTINIUE TO ADD MORE ZONES? (Y/N):   "; ch = read();

	} while (ch == 'Y');
}

int Oppsett::retNoElements()
{
	return 0;
}

