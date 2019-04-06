#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "conster.h"                    //    Test
#include "functions.h"
#include "ListTool2B.h"
#include "Kunder.h"
#include "Arrangement.h"
#include "Arrangementer.h"
#include "Steder.h"


using namespace std;
//List* customerList;
//List* eventList;
//List* layoutList;
//List* venueList;

Kunder customerDatabase;
Arrangementer eventDatabase;
Steder venueDatabase;

int main() {
    
	char command;
    
	//venueDatabase.readVenuesFromFile();
    customerDatabase.readCustomersFromFile(); 
	//eventDatabase.readEventsFromFile();
    
    printMenu();                  //  Meny av brukerens valg.
    
    command = read();             //  Leser brukerens ›nske/valg.
    while (command != 'Q')  {
        switch(command)  {
            case 'K': customerDatabase.customersMenu();			break;
            case 'A': eventDatabase.eventsMenu();				break;
            case 'S': venueDatabase.venuesMenu();				break;
            case 'O': venueDatabase.layoutMenu(); /*layoutMenu();*/                        break;
            default:  printError("INPUT NOT VALID!");    break;
        }
        printMenu();
        command = read();           //  Leser brukerens ›nske/valg.
		
    }
    
	cout << "\n\nWRITING TO FILE...\n\n";
	eventDatabase.writeEventsToFile();
	venueDatabase.writeVenuesToFile();
	
    return 0;
}
