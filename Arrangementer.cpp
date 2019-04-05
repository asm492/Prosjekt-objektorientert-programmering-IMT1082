#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <fstream>
#include <iostream>
#include "Arrangementer.h"
#include "functions.h"
#include "ListTool2B.h"
#include "Arrangement.h"
#include "conster.h"


using namespace std;

extern Steder venueDatabase;

void Arrangementer::eventsMenu() {
    char command;
    
    command = read();
    
    switch (command)
    {
        case 'D':   searchChoice();		break;            //    Display
        case 'N':   newEvent();			break;            //    New
        case 'E':						break;            //    Edit
        case 'S':						break;            //    Delete
		case 'K':    buyTickets();		break;            //    Purchase
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
		case 1: eventList->displayList();		break;				//	Displays all events
		case 2: eventNameSearch();              break;				//	Search by event name
		case 3: venueSearch();					break;		//	To do
		case 4: dateSearch();					break;				//	Search by date
		case 5: typeSearch();					break;				//	Search by event type
		case 6: artistNameSearch();				break;				//	Search by artist name
		case 7: allDataArrNr();                 break;		//	To do
		}
	}
	else
		printError("NO EVENTS IN EVENT LIST");
}
void Arrangementer::buyTickets() {
	Arrangement* tempEvent;
//	Oppsett* layout;
	List* newVenueList;
	int evnr1;
	char eventName[STRLEN], venueName[STRLEN];
	char ch;
	int layoutNr;

	if (eventList->noOfElements() > 0)
	{
		cout << "\nTICKET PURCHASE:" << endl;
		evnr1 = findEvent();
		
		if (evnr1 != 0)
		{
			cout << "\nWOULD YOU LIKE TO SEE ALL THE ZONES? (Y/N): " << endl;
			ch = read();

			if (ch == 'Y')
			{
				cout << "\n1";
				for (int i = 1; i <= eventList->noOfElements(); i++)
				{
					tempEvent = (Arrangement*)eventList->removeNo(i);

					if (tempEvent->compareEventNumber(evnr1))
					{
						strcpy(eventName, tempEvent->getEventName());
						strcpy(venueName, tempEvent->getVenueName());
						layoutNr = tempEvent->getLayout();
					}
					eventList->add(tempEvent);
					
				}
				cout << "\n4";
				newVenueList = venueDatabase.getVenue(eventName, layoutNr);
				cout << "\n5";
				newVenueList->displayList();
				//newVenueList->displayElement("ABC");
				/*for (int i = 1; i <= newVenueList->noOfElements(); i++)
				{
					
				}*/
			}
		}

		       
	}
	else
		printError("NO EVENTS IN DATABASE! CREATE ONE USING 'A N' INN MAIN MENU FIRST!");
}
int Arrangementer::findEvent() {							//	Use if multiple search results
   
	Arrangement* eventPtr;
    char eventName[STRLEN];
	int noOfEvents, nr;
    int searchResults = 0;
    int hit = 0;
	int* results;											
	bool validNumber = true;

    noOfEvents = eventList->noOfElements();					//	Updates variable

	results = new int[noOfEvents + 1];						//	Make new array with 'results' pointing to it

	for (int i = 1; i <= noOfEvents; i++)
	{
		results[i] = 0;										//	Initializing array
	}

    read("EVENT NAME", eventName, STRLEN);
    
    for (int i = 1; i <= noOfEvents; i++)                    //    Couldn't use listool:: inList()
    {                                                        //    Need to know exatly how many in list
        eventPtr = (Arrangement*)eventList->removeNo(i);

        if (eventPtr->compareEventNameExact(eventName))		//	strcmp on each, if true then:
        {
            searchResults++;								//	Increment counter
            eventPtr->display();				
            hit = eventPtr->getEventNr();
			results[i] = eventPtr->getEventNr();			//	Puts event no. in array for later
        }
            eventList->add(eventPtr);
    }
    
	if (searchResults == 1) {									//	Returns event no. if only ONE result
		return hit;
	}
    else if (searchResults > 1){							//	If results > 1
		
		cout << "\nMULTIPLE RESULTS, PLEASE ENTER ONE OF THE FOLLOWING NUMBERS:\n\t" ;
		
		for (int i = 1; i <= noOfEvents; i++)				//	Prints the event numbers of the events
		{													//	that returned a match. User is presented 
			if (results[i] != 0)							//	with a list that contains the event numbs
			{												//	of the events that match the query.
				cout  << results[i] << ' ';
			}
		}
		cout << endl;

		do
		{
			cout << "\nENTER NUMBER: ";						
			cin >> nr;										//	User enters desired number

			for (int i = 1; i <= noOfEvents; i++)
			{
				if (results[i] == nr)						//	Veryfies that number is in array.
				{											//	All numbers in array are valid input.
					return nr;								//	Retures a valid event number.
				}
				else
				{
					validNumber = false;					//	User entered invalid number. 
				}											//	Triggers do-loop.
			}
		} while (validNumber == false);
    }
	
		cout << "\n\n\t\tNO RESULTS FOR '" << eventName << "'!" << endl;
		return 0;
	
}

void Arrangementer::allDataArrNr() {
    
}

void Arrangementer::typeSearch() {
	
	int nr, numberOfResults = 0;
	eventType evntTyp;
	Arrangement* tempEvent;
	bool searchResult;

	cout << "\nSearch by event type:" << endl;
	printEventTypeMenu();
	nr = read("Select type you want to display", 0, 6);

	switch (nr)
	{
	case 0:    evntTyp = Musikk;		break;
	case 1:    evntTyp = Sport;			break;
	case 2:    evntTyp = Teater;        break;
	case 3:    evntTyp = Show;			break;
	case 4:    evntTyp = Kino;			break;
	case 5:    evntTyp = Familie;		break;
	case 6:    evntTyp = Festival;		break;
	}

	for (int i = 1; i <= lastEvent; i++)
	{
		tempEvent = (Arrangement*)eventList->removeNo(i);			//	Takes event out if list
		eventList->add(tempEvent);									//	Adds it back to the list
		searchResult = tempEvent->compareEventType(evntTyp);		//	Each 'Arrangement' compares with own eventType
		
		if (searchResult == 1)                                //    Displays if EXACT match
		{
			tempEvent->display();
			numberOfResults++;
		}

	}

	cout << "\n\tSearch returned " << numberOfResults << " result(s)" << endl;

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
    char venue[STRLEN];
    int searchResult = 0;
    
    Arrangement* tempeEvent;
    readAndUpcase("Venue name search", venue, STRLEN);
    
    for (int i = 1; i <= lastEvent; i++) {
        tempeEvent = (Arrangement*)eventList->removeNo(i);
        eventList->add(tempeEvent);

        if(tempeEvent->compareVenueName(venue)){
            tempeEvent->display();
            searchResult++;
        }
    }
    cout << "\n\nSearch results: " << searchResult << endl;
}

void Arrangementer::artistNameSearch() {
	
	Arrangement* tempEvent;
	char searchName[STRLEN];
	bool searchResult;
	int numberOfResults = 0;

	read("Aritst name search", searchName, STRLEN);
	
	for (int i = 1; i <= lastEvent; i++)
	{
		tempEvent = (Arrangement*)eventList->removeNo(i);       //    Takes event out if list
		eventList->add(tempEvent);
		searchResult = tempEvent->compareArtistName(searchName);
		
		if (searchResult == 1)									//    Displays if EXACT match
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
       
    cout << "\n\tSearch: '" << searchName << "' returned " << numberOfResults
    << " result(s)" << endl;
}

Arrangementer::Arrangementer() {
    eventList = new List(Sorted);
}
/*Arrangementer::~Arrangementer() {
    
} */

void Arrangementer::newEvent(){
	char venueName[STRLEN];
	char eventName[STRLEN];
    Arrangement* temp;

	if (venueDatabase.retLastUsedVenue() > 0)
	{
		readAndUpcase("Enter venue name", venueName, STRLEN);
		if (venueDatabase.venueExist(venueName))
		{
			if (venueDatabase.returnCurrentLayout(venueName))
			{
				read("Enter event name", eventName, STRLEN);
				temp = new Arrangement(++lastEvent, eventName, venueName);
				eventList->add(temp);
			}
			else
				printError("THIS VENUE DOES NOT HAVE ANY LAYOUTS YET!");
		}
		else
			printError("VENUE NOT IN DATABASE!");
	}
	else
		printError("VENUE LIST IS EMPTY! PLEASE REGISTER A VENUE USING 'S N' COMMAND IN MAIN MENU");
	
}

void Arrangementer::writeEventsToFile() {
    
    int noOfEvents;
    Arrangement* tempEvent;
    
    /********************************************************************************/
    ofstream out("ARRANGEMENTER_TEST.DTA");                            //JUST FOR TESTING. 
    
    noOfEvents = eventList->noOfElements();
    
    
    if (lastEvent > 0)
    {
        
        out << noOfEvents << '\n';
        for (int i = 1; i <= noOfEvents; i++)
        {
            tempEvent = (Arrangement*)eventList->removeNo(i);
            tempEvent->writeToFile(out);
            eventList->add(tempEvent);                      //    Puts the object back inn the list
        }
    }
    else
        printError("NO CUSTOMERS IN DATABASE!");
}

void Arrangementer::readEventsFromFile() {
    
    Arrangement* temp;
    char bufferName[STRLEN];
	int evntNumber;
    ifstream inn("ARRANGEMENTER.DTA");
    
    if (inn)
    {
        inn >> lastEvent; 
        
        for (int i = 1; i <= lastEvent; i++) {
			inn >> evntNumber; inn.ignore();
            inn.getline(bufferName, STRLEN);
            temp = new Arrangement(evntNumber, bufferName, inn);
            eventList->add(temp);
        }
    }
    else
        printError("FILE 'ARRANGEMENTER.DTA' NOT FOUND!");
    
    
}
