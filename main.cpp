#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include "conster.h"					//	Test
#include "functions.h"
#include "ListTool2B.h"

List* customerList;
List* eventList;
List* layoutList;
List* venueList;


int main(int argc, const char * argv[]) {
								
										//	Should these be outside main?
	customerList = new List(Sorted);
	eventList = new List(Sorted);
	layoutList = new List(Sorted);		//	THIS IS WRONG
	venueList = new List(Sorted);

	char command;                //  Brukerens ›nske/valg.
    
    
    printMenu();                  //  Meny av brukerens valg.
    
    command = read();             //  Leser brukerens ›nske/valg.
    while (command != 'Q')  {
        switch(command)  {
			case 'K': customerMenu();   break;   
			case 'S': venueMenu();      break;   
            case 'O': layoutMenu();		break;   
			case 'A': eventMenu();		break;   
            default:  printMenu();      break;   
        }
        command = read();           //  Leser brukerens ›nske/valg.
    }


    return 0;
}
