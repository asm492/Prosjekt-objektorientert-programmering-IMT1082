#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "functions.h"
#include "Sone.h"
#include <iostream>

using namespace std;

Sone::Sone() {
	swarmList = new List(Sorted);
	seatList = new List(Sorted);
}

Sone::~Sone() {

}

void Sone::display() {

}