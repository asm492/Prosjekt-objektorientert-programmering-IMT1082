#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include "Kunder.h"
#include "functions.h"
#include "ListTool2B.h"
#include "Kunde.h"
#include "conster.h"

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>

void Kunder::customersMenu() {
	char command;

	command = read();

	switch (command)
	{
	case 'D':	display();		break;			//	Display
	case 'N':	newCustomer();	break;			//	New
	case 'E':	break;			//	Edit
	case 'S':	break;			//	Delete

	default:
		printError("INPUT NOT VALID! GOING BACK TO MAIN MENU");	
		printMenu(); 
		break;
	}
}

Kunder::Kunder() {
	customersList = new List(Sorted);
	
}
void Kunder::newCustomer() {
	
	customersList->add(new Kunde(++lastCustomer));
	writeCustomersToFile();

}
void Kunder::display() {
	int custNr;

	if (lastCustomer > 0)
	{
		custNr = read("Customer number to display? 0 for all", 0, lastCustomer);
		
		if (custNr != 0) {
			customersList->displayElement(custNr);
		}
		else
			customersList->displayList();
			
	}
	else
		printError("NO CUSTOMERS IN DATABASE!");
}
void Kunder::writeCustomersToFile() {
	
	int noOfCustomers;
	Kunde* tempKunde;
	
	
	ofstream out("KUNDER_TEST.DTA");						//CHANGE TO KUNDER.DTA

	noOfCustomers = customersList->noOfElements();			
	
	
	if (lastCustomer > 0)
	{
		for (int i = 1; i <= lastCustomer; i++)
		{
			tempKunde = (Kunde*)customersList->removeNo(i);		//	Removes from list
			tempKunde->writeToFile(i, out);						//	Makes the object write it self out
			customersList->add(tempKunde);						//	Puts the object back inn the list 
		}
	}
	else
		printError("NO CUSTOMERS IN DATABASE!");
	

}


