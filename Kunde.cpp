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

Kunde::Kunde(int n) : NumElement(n) {        //    Passes parameter on to base-class
    
    char bufferName[STRLEN];
    char bufferEmail[STRLEN];
    char bufferAddress[STRLEN];
    char bufferArea[STRLEN];
    
    cout << "\n\tCustomer number: " << n << endl;   //Name
    
    read("Enter customer name", bufferName, STRLEN);
    name = new char[strlen(bufferName) + 1];            //Allocating enough space
    strcpy(name, bufferName);                            //for string + '\0'
    
    
    read("Enter street address", bufferAddress, STRLEN); //Address
    streetAddress = new char[strlen(bufferAddress) + 1];//Allocating enough space
    strcpy(streetAddress, bufferAddress);                //for string + '\0'
    
    postalCode = read("Enter postal code", MINZIP, MAXZIP);
    
    
    read("Enter postal area (City)", bufferArea, STRLEN); //Postal area / city
    postalArea = new char[strlen(bufferArea) + 1];        //Allocating enough space
    strcpy(postalArea, bufferArea);                        //for string + '\0'
    
    phoneNumber = read("Enter phone number", MINTLF, MAXTLF); //Reads phone number
    
    
    read("Enter email address", bufferEmail, STRLEN);       //Email:
    email = new char[strlen(bufferEmail) + 1];            //Allocating enough space
    strcpy(email, bufferEmail);                            //for string + '\0'
}
void Kunde::display() {      //Displays customer
    cout << "\nCustomer number: " << number << endl;
    cout << "Name:            " << name << endl;
    cout << "Street address:  " << streetAddress << endl;
	cout << "ZIP / Area:      ";
	
	if (postalCode < 10)								//	Ensures that ZIP is always 
	{													//	displayed with correct format
		cout << "000";
	}
	else if (postalCode < 100) {
		cout << "00";
	}
	else if (postalCode < 1000)
	{
		cout << '0';
	}
	
	cout << postalCode << ' ' << postalArea << endl;
    cout << "Phone:           " << phoneNumber << endl;
    cout << "Email:           " << email << endl;
    
}
void Kunde::writeToFile(int custNumber, ofstream & out) { //Writes customer to file
    out << custNumber << '\n';      // 2.line after number of all customers
    out << name << '\n';
    out << streetAddress << '\n';
    out << postalCode << '\n';
    out << postalArea << '\n';
    out << phoneNumber << '\n';
    out << email << '\n';
}
Kunde::Kunde(int n, ifstream & inn) : NumElement(n) {  //Reads customer from file
    
    char bufferName[STRLEN];
    char bufferEmail[STRLEN];
    char bufferAddress[STRLEN];
    char bufferArea[STRLEN];
    
    inn >> number; inn.ignore();
    
    
    inn.getline(bufferName, STRLEN);                    //Name
    name = new char[strlen(bufferName) + 1];            //Allocating enough space
    strcpy(name, bufferName);                            //for string + '\0'
    //inn.ignore();
    
    inn.getline(bufferAddress, STRLEN);                 //Address
    streetAddress = new char[strlen(bufferAddress) + 1];//Allocating enough space
    strcpy(streetAddress, bufferAddress);                //for string + '\0'
    //inn.ignore();
    
    inn >> postalCode;
    inn.ignore();
    
    
    inn.getline(bufferArea, STRLEN);                    //Postal area / city
    postalArea = new char[strlen(bufferArea) + 1];        //Allocating enough space
    strcpy(postalArea, bufferArea);                        //for string + '\0'
    
    
    inn >> phoneNumber;                                 //Reads phone number
    inn.ignore();
    
    
    inn.getline(bufferEmail, STRLEN);                   //Email
    email = new char[strlen(bufferEmail) + 1];            //Allocating enough space
    strcpy(email, bufferEmail);                            //for string + '\0'
    
    
    //inn.ignore();
    
}
Kunde::~Kunde() {               //Destrctor for customer
    delete[] name;
    delete[] streetAddress;
    delete[] postalArea;
    delete[] email;
}
bool Kunde::compareName(char query[])          //Compares customer number
{
    return strstr(name, query);
    
}
void Kunde::updateCustomerNumber(int newCustomerNr)  //Updates customer number
{
    number = newCustomerNr;
}
