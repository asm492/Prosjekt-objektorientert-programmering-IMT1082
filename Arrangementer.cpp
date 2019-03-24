#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include "Arrangementer.h"
#include "functions.h"
#include "ListTool2B.h"
#include "Arrangement.h"
#include "conster.h"

using namespace std;

void Arrangementer::eventsMenu() {
    char command;
    
    command = read();
    
    switch (command)
    {
        case 'D':   searchChoice();   break;            //    Display
        case 'N':    break;            //    New
        case 'E':    break;            //    Edit
        case 'S':    break;            //    Delete
        case 'K':    break;            //    Purchase
        case 'R':    break;            //    Return
            
        default:
            printError("INVALID INPUT! GOING BACK TO MAIN MENU");    break;
    }
}

void Arrangementer::searchChoice(){
   
    searchMenu();
    
    char command;
    command = read("Command: ", 1, 7);
    
    switch (command) {
        case 1: eventList->displayList();    break;
        case 2:                   break;
        case 3:                   break;
        case 4:                   break;
        case 5:                   break;
        case 6:                   break;
        case 7:                   break;
        default:   break;
    }
}

void Arrangementer::searchMenu() {
    cout << "\n\nEVENT MENU - Avalible commands:";
    cout << "\n\t(1). - Print all the events";
    cout << "\n\t(2) - Search for an event";
    cout << "\n\t(3) - Search for event's on a certain venue";
    cout << "\n\t(4) - Search for events on a certain date";
    cout << "\n\t(5) - Search for event type";
    cout << "\n\t(6) - Search for artist";
    cout << "\n\t(7) - Print all data of a certain event";
    
}

void Arrangementer::eventSearch() {
    
    Arrangement* tempEvent;
    char searchName[STRLEN];
    bool searchResult;
    int numberOfResults = 0;
    
    read("Type the name you are searching for", searchName, STRLEN);
    
    for (int i = 1; i <= lastEvent; i++)
    {
        tempEvent = (Arrangement*)eventList->removeNo(i);        //    Takes customer out if list
        searchResult = tempEvent->compareEvent(searchName);    //    Does a strstr comparison on customer
//        eventList->add(tempEvent);                        //    Adds it back to the list
//          compare(<#Element *element#>)
        if (searchResult == 1)                                //    Displays if partial match
        {
            eventList->displayElement(i);
            numberOfResults++;
        }
    }
    
    cout << "\n\tSearch: '" << searchName << "' returned " << numberOfResults
    << " result(s)" << endl;
}

Arrangementer::Arrangementer() {

}
Arrangementer::~Arrangementer() {

}




