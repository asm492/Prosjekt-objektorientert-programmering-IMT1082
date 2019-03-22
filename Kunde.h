#ifndef Kunde_h
#define Kunde_h

#include "ListTool2B.h"
#include <iostream>
#include <fstream>

using namespace std;
class Kunde : public NumElement{
private:
	char* name;
	char* streetAddress;
	char* postalArea;
	int postalCode;
	int phoneNumber;
	char* email;

public:
	Kunde(int n);
	Kunde(int n, ifstream & inn);
	~Kunde();
	
	void display();
	void writeToFile(int custNumber, ofstream & out);
	void readFromFile(ifstream & inn);
	bool compareName(char query[]);
	void updateCustomerNumber(int newCustomerNr);			// Used to fill the void when a customer is deleted

};

#endif Kunde_h
