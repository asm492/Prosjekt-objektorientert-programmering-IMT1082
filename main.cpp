#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include "conster.h"					//	Test
#include "functions.h"
#include "ListTool2B.h"
#include "Kunder.h"
#include "Arrangement.h"
#include "Arrangementer.h"

//List* customerList;
//List* eventList;
//List* layoutList;
//List* venueList;


int main() {
	
	Kunder customerDatabase;
	Arrangementer eventDatabase;
	
	char command;                					
										//	Should these be outside main?
	
	//customerList = new List(Sorted);
	//eventList = new List(Sorted);
	//layoutList = new List(Sorted);		//	THIS IS WRONG
	//venueList = new List(Sorted);

	
    
    
    printMenu();                  //  Meny av brukerens valg.
    
    command = read();             //  Leser brukerens ›nske/valg.
    while (command != 'Q')  {
        switch(command)  {
		case 'K': customerDatabase.customersMenu();		break;
			case 'S': venueMenu();						break;   
            case 'O': layoutMenu();						break;   
			case 'A': eventMenu();						break;   
			default:  printError("INPUT NOT VALID!");	break;
        }
		printMenu();
        command = read();           //  Leser brukerens ›nske/valg.
    }


    return 0;
}
