#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include <fstream>
#include "Sted.h"

using namespace std;

void Sted::display(){
    cout << '\n' << "Venue: " << name;
    cout << '\n' << "Number of layout's: " << numberOfLayouts;
    cout << '\n';
}
