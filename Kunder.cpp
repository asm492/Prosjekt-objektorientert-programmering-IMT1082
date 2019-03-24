#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include <fstream>
#include "Kunder.h"
#include "functions.h"
#include "ListTool2B.h"
#include "Kunde.h"
#include "conster.h"

using namespace std;

void Kunder::customersMenu() {
	char command;

	command = read();

	switch (command)
	{
	case 'D':	display();			break;			//	Display
	case 'N':	newCustomer();		break;			//	New
	case 'E':	editCustomer();		break;			//	Edit
	case 'S':	deleteCustomer();	break;			//	Delete

	default:
		printError("INVALID INPUT! GOING BACK TO MAIN MENU");	
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
void Kunder::display(){
	
	Kunde* tempCust;
	int custNr, numberOfResults = 0;
	char query[STRLEN];
	bool searchResult;

	if (lastCustomer > 0)
	{
		cout << "\nCUSTOMER DISPLAY:" << endl;
		cout << "\nType name, customer number or leave blank to display all:\n\n";
		cin.getline(query, STRLEN);

		if (strlen(query) == 0)										//	Dislays all
		{
			customersList->displayList();
		}

		if (checkDigit(query) == true && strlen(query) > 0)			//	Input only digits & lenght 
		{															//	greater than 0.
			custNr = atoi(query);									//	Converts cstring to int
			if (custNr <= lastCustomer)
			{
				customersList->displayElement(custNr);				//	Displays that customer
			}
			else
				printError("CUSTOMER NUMBER NOT IN USE!");
		}

		if (checkDigit(query) == false && strlen(query) > 0)				//	Input not only digits &
		{															//	lenght greater than 0
			for (int i = 1; i <= lastCustomer; i++)
			{
				tempCust = (Kunde*)customersList->removeNo(i);		//	Takes customer out if list
				searchResult = tempCust->compareName(query);		//	Does a strstr comparison on customer
				customersList->add(tempCust);						//	Adds it back to the list

				if (searchResult == true)							//	Displays if partial match
				{
					customersList->displayElement(i);
					numberOfResults++;
				}
			}

			cout << "\n\tSearch: '" << query << "' returned " << numberOfResults
				<< " result(s)" << endl;
		}

	}
	else
		printError("NO CUSTOMERS IN DATABASE!");
}
void Kunder::writeCustomersToFile() {
	
	int noOfCustomers;
	Kunde* tempKunde;
	
	/********************************************************************************/
	ofstream out("KUNDER_TEST.DTA");							//JUST FOR TESTING. CHANGE TO KUNDER.DTA 

	noOfCustomers = customersList->noOfElements();			
	
	
	if (lastCustomer > 0)
	{
		
		out << noOfCustomers << '\n';
		for (int i = 1; i <= noOfCustomers; i++)
		{
			tempKunde = (Kunde*)customersList->removeNo(i);		//	Removes from list
			tempKunde->writeToFile(i, out);						//	Makes the object write it self out
			customersList->add(tempKunde);						//	Puts the object back inn the list 
		}
	}
	else
		printError("NO CUSTOMERS IN DATABASE!");
}
void Kunder::readCustomersFromFile() {
	ifstream inn("KUNDER.DTA");
	Kunde* temp;
	//int noOfCustomers;

	if (inn)
	{
		inn >> lastCustomer; inn.ignore();						//	Reads number of customers
		//lastCustomer = noOfCustomers + CUSTNOSTART;
		
		for (int i = 1; i <= lastCustomer; i++)
		{
			temp = (Kunde*)customersList->add(new Kunde(i, inn));
		}
	}
	else
		printError("FILE 'KUNDER.DTA' COULD NOT BE LOCATED!");
}
void Kunder::editCustomer() {
	int tempNumber;
	char ch;

	if (lastCustomer > 0)
	{
		tempNumber = read("Customer number you want to edit?: ", 1, lastCustomer);
		
		cout << "\nCurrent details on customer number " << tempNumber << ": ";
		customersList->displayElement(tempNumber);
		
		cout << "\nAre you sure you want to edit? (Y/N): ";
		ch = read();

		if (ch == 'Y')
		{
			customersList->destroy(tempNumber);
			customersList->add(new Kunde(tempNumber));

			cout << "\nNew details on customer number " << tempNumber << ": ";
			customersList->displayElement(tempNumber);
			writeCustomersToFile();
		}

	}
	else
		printError("NO CUSTOMERS IN DATABASE!"); 
}
void Kunder::deleteCustomer() {
	Kunde* buffer;
	int tempNumber;
	char ch;

	if (lastCustomer > 0)
	{
		tempNumber = read("Customer number you want to delete? 0 to abort", 0, lastCustomer);

		if (tempNumber != 0)
		{
			customersList->displayElement(tempNumber);

			cout << "\nAre you sure you want to DELETE? (Y/N): ";
			ch = read();

			if (ch == 'Y')
			{
				buffer = (Kunde*)customersList->removeNo(lastCustomer);		//Copies last customer 
				customersList->destroy(tempNumber);							//Deletes customer with index = tempNumber


				if (tempNumber != lastCustomer)
				{
					buffer->updateCustomerNumber(tempNumber);		//Puts last customer in the 
					customersList->add(buffer);						//gap left by the deleted customer
				}


				cout << "\nCustomer " << tempNumber << " deleted!" << endl;

				lastCustomer = customersList->noOfElements();			//Updates lastCustomer														
				writeCustomersToFile();
			}
		}
		else
			printError("NO CUSTOMER DELETED!");
	}
	else
		printError("NO CUSTOMERS IN DATABASE!");
}


