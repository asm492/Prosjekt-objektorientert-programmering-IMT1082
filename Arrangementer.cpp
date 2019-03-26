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
        case 'N':   newEvent();       break;            //    New
        case 'E':    break;            //    Edit
        case 'S':    break;            //    Delete
        case 'K':    break;            //    Purchase
        case 'R':    break;            //    Return
            
        default:
            printError("INVALID INPUT! GOING BACK TO MAIN MENU");    break;
    }
}

void Arrangementer::searchChoice(){
    
	if ((eventList->noOfElements()) > 0)
	{
		searchMenu();

		char command;
		command = read("Command: ", 1, 7);

		switch (command) {
		case 1: eventList->displayList();		break;				//	Done
		case 2: eventNameSearch();              break;				//	Done
		case 3: venueSearch();					break;		//	To do
		case 4: dateSearch();					break;				//	Done
		case 5: typeSearch();					break;		//	To do
		case 6: artistNameSearch();				break;				//	Done	
		case 7: allDataArrNr();                 break;		//	To do
		}
	}
	else
		printError("NO EVENTS IN EVENT LIST");
}

void Arrangementer::allDataArrNr() {
    
}

void Arrangementer::typeSearch() {
    
}

void Arrangementer::dateSearch() {
	
	Arrangement* tempEvent;
	int searchDate, dd, mm, yyyy;
	bool searchResult;
	int numberOfResults = 0;

	do
	{
		cout << "\nDATE SEARCH:";
		dd = read("Type day", DAYMIN, DAYMAX);
		mm = read("Type month", MONTHMIN, MONTHMAX);
		yyyy = read("Type year", YEARMIN, YEARMAX);

		if (dayNumber(dd, mm, yyyy) == 0)
		{
			printError("INVALID DATE! TRY AGAIN!");
		}
	} while (dayNumber(dd, mm, yyyy) == 0);

	searchDate = (dd * 1000000) + (mm * 10000) + yyyy;                //    Converts date format to 1 int


	for (int i = 1; i <= lastEvent; i++)
	{
		tempEvent = (Arrangement*)eventList->removeNo(i);        //    Takes event out if list
		eventList->add(tempEvent);
		searchResult = tempEvent->compareEventDate(searchDate);
		//searchResult = tempEvent->compareEvent(searchName);    //    Does a strcmp  comparison on event
		//    Adds it back to the list
		//        Bruke ListTool til å compare???
		if (searchResult == 1)                                //    Displays if EXACT match
		{
			tempEvent->display();
			numberOfResults++;
		}

	}

	cout << "\n\tSearch: '" << searchDate << "' returned " << numberOfResults
		<< " result(s)" << endl;
}

void Arrangementer::venueSearch() {
    
}

void Arrangementer::artistNameSearch() {
	Arrangement* tempEvent;
	char searchName[STRLEN];
	bool searchResult;
	int numberOfResults = 0;

	read("Aritst name search", searchName, STRLEN);


	for (int i = 1; i <= lastEvent; i++)
	{
		tempEvent = (Arrangement*)eventList->removeNo(i);        //    Takes event out if list
		eventList->add(tempEvent);
		searchResult = tempEvent->compareArtistName(searchName);
		
		if (searchResult == 1)                                //    Displays if EXACT match
		{
			tempEvent->display();
			numberOfResults++;
		}

	}

	cout << "\n\tSearch: '" << searchName << "' returned " << numberOfResults
		<< " result(s)" << endl;
}
void Arrangementer::searchMenu() {
    cout << "\n\nEVENT MENU - Avalible commands:";
    cout << "\n\t(1) - Print all the events";
    cout << "\n\t(2) - Search for an event by event name";
    cout << "\n\t(3) - Search for event's on a certain venue";
    cout << "\n\t(4) - Search for events on a certain date";
    cout << "\n\t(5) - Search for event type";
    cout << "\n\t(6) - Search for artist";
    cout << "\n\t(7) - Print all data of a certain event";
    
}

void Arrangementer::eventNameSearch() {
    
    Arrangement* tempEvent;
    char searchName[STRLEN];
    bool searchResult;
    int numberOfResults = 0;
    
    read("Type the event name you are searching for", searchName, STRLEN);
    
    
    for (int i = 1; i <= lastEvent; i++)
    {
        tempEvent = (Arrangement*)eventList->removeNo(i);        //    Takes event out if list
        eventList->add(tempEvent);
		searchResult = tempEvent->compareEventName(searchName);
        //searchResult = tempEvent->compareEvent(searchName);    //    Does a strcmp  comparison on event
        //    Adds it back to the list
        //        Bruke ListTool til å compare???
        if (searchResult == 1)                                //    Displays if EXACT match
        {
			tempEvent->display();
            numberOfResults++;
        }
        
    }
    
    /*
     for (int i = 1; i <= lastEvent; i++)
     {
     tempEvent = (Arrangement*)eventList->removeNo(i);        //    Takes customer out if list
     searchResult = tempEvent->compareEvent(searchName);    //    Does a strstr comparison on customer
     eventList->add(tempEvent);                        //    Adds it back to the list
     //        Bruke ListTool til å compare???
     if (searchResult == 1)                                //    Displays if partial match
     {
     eventList->displayElement(i);
     numberOfResults++;
     }
     }*/
    
    cout << "\n\tSearch: '" << searchName << "' returned " << numberOfResults
    << " result(s)" << endl;
}

Arrangementer::Arrangementer() {
    eventList = new List(Sorted);
}
Arrangementer::~Arrangementer() {
    
} 

void Arrangementer::newEvent(){
	char buffer[STRLEN];
	
	read("Enter event name", buffer, STRLEN);
	eventList->add(new Arrangement(++lastEvent, buffer));
}


