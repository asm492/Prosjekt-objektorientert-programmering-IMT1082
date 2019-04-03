#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <fstream>
#include <iostream>
#include "Vrimle.h"
#include "ListTool2B.h"
#include "Sone.h"

using namespace std;

Vrimle::Vrimle(char name[], enum zoneType type) : Sone(name, type) {
    space = new int[ticketsForSale];
}

Vrimle::Vrimle(char name[], ifstream & inn, enum zoneType type) : Sone(name, inn, type)
{
	space = new int[ticketsForSale];
	inn.ignore();
}

void Vrimle::writeToFile(ofstream & out)
{
	Sone::writeToFile(out);
}

void Vrimle::display(){
    
    Sone::display();
}
Vrimle::~Vrimle() {
	space = nullptr;
}

