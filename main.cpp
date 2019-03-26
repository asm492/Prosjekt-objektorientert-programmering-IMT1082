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

//List* customerList;
//List* eventList;
//List* layoutList;
//List* venueList;


int main() {
    
    char command;
    
    Kunder customerDatabase;
    Arrangementer eventDatabase;
    Steder venueDatabase;
    
    
    
    
    
    customerDatabase.readCustomersFromFile();
    
    //    Should these be outside main?
    
    //customerList = new List(Sorted);
    //eventList = new List(Sorted);
    //layoutList = new List(Sorted);        //    THIS IS WRONG
    //venueList = new List(Sorted);
    
    
    
    
    printMenu();                  //  Meny av brukerens valg.
    
    command = read();             //  Leser brukerens ›nske/valg.
    while (command != 'Q')  {
        switch(command)  {
            case 'K': customerDatabase.customersMenu();        break;
            case 'A': eventDatabase.eventsMenu();            break;
            case 'S': venueDatabase.venuesMenu();            break;
            case 'O': venueDatabase.layoutMenu(); /*layoutMenu();*/                        break;
            default:  printError("INPUT NOT VALID!");    break;
        }
        printMenu();
        command = read();           //  Leser brukerens ›nske/valg.
    }
    
    
    return 0;
}
