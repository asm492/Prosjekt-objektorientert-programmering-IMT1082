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
    
    cout << "\n\tCustomer number: " << n << endl;
    //Name:
    read("Enter customer name", bufferName, STRLEN);
    name = new char[strlen(bufferName) + 1];            //Allocating enough space
    strcpy(name, bufferName);                            //for string + '\0'
    
    //Address:
    read("Enter street address", bufferAddress, STRLEN);
    streetAddress = new char[strlen(bufferAddress) + 1];//Allocating enough space
    strcpy(streetAddress, bufferAddress);                //for string + '\0'
    
    postalCode = read("Enter postal code", MINZIP, MAXZIP);
    
    //Postal area / city:
    read("Enter postal area (City)", bufferArea, STRLEN);
    postalArea = new char[strlen(bufferArea) + 1];        //Allocating enough space
    strcpy(postalArea, bufferArea);                        //for string + '\0'
    
    phoneNumber = read("Enter phone number", MINTLF, MAXTLF);
    
    //Email:
    read("Enter email address", bufferEmail, STRLEN);
    email = new char[strlen(bufferEmail) + 1];            //Allocating enough space
    strcpy(email, bufferEmail);                            //for string + '\0'
}
void Kunde::display() {
    cout << "\nCustomer number: " << number << endl;
    cout << "Name:            " << name << endl;
    cout << "Street address:  " << streetAddress << endl;
    cout << "ZIP / Area:      " << postalCode << ' ' << postalArea << endl;
    cout << "Phone:           " << phoneNumber << endl;
    cout << "Email:           " << email << endl;
    
}
void Kunde::writeToFile(int custNumber, ofstream & out) {
    out << custNumber << '\n';
    out << name << '\n';
    out << streetAddress << '\n';
    out << postalCode << '\n';
    out << postalArea << '\n';
    out << phoneNumber << '\n';
    out << email << '\n';
}
Kunde::Kunde(int n, ifstream & inn) : NumElement(n) {
    
    char bufferName[STRLEN];
    char bufferEmail[STRLEN];
    char bufferAddress[STRLEN];
    char bufferArea[STRLEN];
    
    inn >> number; inn.ignore();
    
    //Name:
    inn.getline(bufferName, STRLEN);
    name = new char[strlen(bufferName) + 1];            //Allocating enough space
    strcpy(name, bufferName);                            //for string + '\0'
    //inn.ignore();
    //Address:
    inn.getline(bufferAddress, STRLEN);
    streetAddress = new char[strlen(bufferAddress) + 1];//Allocating enough space
    strcpy(streetAddress, bufferAddress);                //for string + '\0'
    //inn.ignore();
    
    inn >> postalCode;
    inn.ignore();
    
    //Postal area / city:
    inn.getline(bufferArea, STRLEN);
    postalArea = new char[strlen(bufferArea) + 1];        //Allocating enough space
    strcpy(postalArea, bufferArea);                        //for string + '\0'
    
    
    inn >> phoneNumber;
    inn.ignore();
    
    //Email:
    inn.getline(bufferEmail, STRLEN);
    email = new char[strlen(bufferEmail) + 1];            //Allocating enough space
    strcpy(email, bufferEmail);                            //for string + '\0'
    
    
    //inn.ignore();
    
}
Kunde::~Kunde() {
    delete[] name;
    delete[] streetAddress;
    delete[] postalArea;
    delete[] email;
}
bool Kunde::compareName(char query[]) {
    
    return strstr(name, query);
    //return strcmp(name, query);
}
void Kunde::updateCustomerNumber(int newCustomerNr) {
    number = newCustomerNr;
}
