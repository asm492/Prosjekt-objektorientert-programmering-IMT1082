#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <fstream>
#include <iostream>
#include "Vrimle.h"
#include "ListTool2B.h"
#include "Sone.h"

using namespace std;

Vrimle::Vrimle(char name[]) : Sone(name) {    
    space = new int[ticketsForSale];
}

Vrimle::Vrimle(char name[], ifstream & inn) : Sone(name, inn)
{
	space = new int[ticketsForSale];
}

void Vrimle::writeToFile(ofstream & out)
{
	Sone::writeToFile(out);
}

void Vrimle::display(){
    
    Sone::display();
}

