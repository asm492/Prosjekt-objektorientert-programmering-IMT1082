#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include "Arrangementer.h"
#include "functions.h"

using namespace std;

Arrangementer::Arrangementer() {

}
Arrangementer::~Arrangementer() {

}

void Arrangementer::eventsMenu() {
	char command;

	command = read();

	switch (command)
	{
	case 'D':	break;			//	Display
	case 'N':	break;			//	New
	case 'E':	break;			//	Edit
	case 'S':	break;			//	Delete
	case 'K':	break;			//	Purchase
	case 'R':	break;			//	Return

	default:
		printError("INVALID INPUT! GOING BACK TO MAIN MENU");	break;
	}
}


