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
	Kunde();
	Kunde(ifstream & inn);
	void display();

};

#endif Kunde_h
