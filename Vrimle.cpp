#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <iostream>
#include "Vrimle.h"
#include "ListTool2B.h"
#include "Sone.h"

using namespace std;

Vrimle::Vrimle(char name[]) : Sone(name) {    
    space = new int[ticketsForSale];
}

void Vrimle::display(){
    
    Sone::display();
}

