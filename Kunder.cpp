#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include "Kunder.h"
#include "functions.h"
#include "ListTool2B.h"
#include "Kunde.h"

using namespace std;

void Kunder::customersMenu() {
	char command;

	command = read();

	switch (command)
	{
	case 'D':	break;			//	Display
	case 'N':	break;			//	New
	case 'E':	break;			//	Edit
	case 'S':	break;			//	Delete

	default:
		printError("INPUT NOT VALID! GOING BACK TO MAIN MENU");	break;
	}
}

Kunder::Kunder() {
	customersList = new List(Sorted);
	
}
void Kunder::newCustomer() {
	int custNumber;

	custNumber = 1000 + (++lastCustomer);

	customersList->add(new Kunde(custNumber));
}


