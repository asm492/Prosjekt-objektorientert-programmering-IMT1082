#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include <fstream>
#include <cstring>
#include "Kunde.h"
#include "ListTool2B.h"
#include "functions.h"
#include "conster.h"

using namespace std;

Kunde::Kunde() {
	char bufferName[STRLEN];
	char bufferEmail[STRLEN];
	char bufferAddress[STRLEN];
	char bufferArea[STRLEN];

														//Name:
	read("Enter customer name", bufferName, STRLEN);
	name = new char[strlen(bufferName) + 1];			//Allocating enough space
	strcpy(name, bufferName);							//for string + '\0'

														//Address:
	read("Enter street address", bufferAddress, STRLEN);
	streetAddress = new char[strlen(bufferAddress) + 1];//Allocating enough space
	strcpy(streetAddress, bufferAddress);				//for string + '\0'
														
	postalCode = read("Enter postal code", MINZIP, MAXZIP);

														//Postal area / city:
	read("Enter street address", bufferArea, STRLEN);
	postalArea = new char[strlen(bufferArea) + 1];		//Allocating enough space
	strcpy(postalArea, bufferArea);						//for string + '\0'

	phoneNumber = read("Enter phone number", MINTLF, MAXTLF);

														//Email:
	read("Enter email address", bufferEmail, STRLEN);
	email = new char[strlen(bufferEmail) + 1];			//Allocating enough space
	strcpy(email, bufferEmail);							//for string + '\0'
}
void Kunde::display() {
	cout << "Name:           " << name << endl;
	cout << "Street address: " << streetAddress << endl;
	cout << "ZIP, Area:      " << postalCode << ", " << postalArea << endl;
	cout << "Phone:          " << phoneNumber << endl;
	cout << "Email:          " << email;
}