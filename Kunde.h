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
	
	void display();
	void writeToFile(int custNumber, ofstream & out);
	void readFromFile(ifstream & inn);

};

#endif Kunde_h
