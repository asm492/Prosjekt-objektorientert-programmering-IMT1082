#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "functions.h"
#include <iostream>
#include "Arrangement.h"
#include "conster.h"
#include "Sted.h"
#include "enums.h"
#include "Steder.h"
#include "ListTool2B.h"
#include "Stoler.h"
#include "Vrimle.h"
#include "Sone.h"
#include <fstream>
#include "Kunder.h"
#include "Kunde.h"
#include <cstring>

using namespace std;

extern Steder venueDatabase;
extern Kunder customerDatabase;

Arrangement::Arrangement(int eNr, char evntName[], char venName[], int layoutNo) : TextElement(evntName){
    char buffer[STRLEN];
	int dd, mm, yyyy, nr;
	
	layoutNumber = layoutNo;
	eventNumber = eNr;                                     //Adds eventnumber from parametre
	eventName = new char[strlen(evntName) + 1];            //Allocating enough space
	strcpy(eventName, evntName);                            //for string + '\0'

	venueName = new char[strlen(venName) + 1];            //Allocating enough space
	strcpy(venueName, venName);                            //for string + '\0'
    
    cout << '\n';
	read("Enter artist name", buffer, STRLEN);
	artistName = new char[strlen(buffer) + 1];            //Allocating enough space
	strcpy(artistName, buffer);                            //for string + '\0'

		do
		{
			cout << "\nDATE:";                  //Reads date for event
			dd = read("Type day", DAYMIN, DAYMAX);
			mm = read("Type month", MONTHMIN, MONTHMAX);
			yyyy = read("Type year", YEARMIN, YEARMAX);

			if (dayNumber(dd, mm, yyyy) == 0)
			{
				printError("INVALID DATE! TRY AGAIN!");
			}
		} while (dayNumber(dd, mm, yyyy) == 0); //Checks if date is valid

		date = (dd * 1000000) + (mm * 10000) + yyyy;                //    Converts date format to 1 int

		cout << "\nTIME:";                      //Reads time for event
		hour = read("Type hours", HOURMIN, HOURMAX);
		min = read("Type minutes", MINUTEMIN, MINUTEMAX);

		printEventTypeMenu();                    //Writes type menue
		nr = read("Choice", 0, 6);
                                            //Number picket will set eventype to chosen type
		switch (nr)
		{
		case 0:    eventType = Musikk;		    break;
		case 1:    eventType = Sport;			break;
		case 2:    eventType = Teater;			break;
		case 3:    eventType = Show;			break;
		case 4:    eventType = Kino;			break;
		case 5:    eventType = Familie;			break;
		case 6:    eventType = Festival;		break;
		}
		
		
}
void Arrangement::getCopyOfList(List* zoneList) {

	writeToARRXXFile(zoneList);         //Writes copy of list to arr_xx
}
void Arrangement::deleteMe()        //File delete
{
	char fileName[STRLEN / 4] = "ARR_";
	char evntNo[STRLEN / 16];

	
	sprintf(evntNo, "%d", eventNumber);								//	Tried using iota(), causes compiler error	
	strcat(fileName, evntNo);                                       //  Gets the unique filename
	strcat(fileName, ".DTA");

	if (remove(fileName) == 0)                                  //  Deletes file
	{
		cout << "\n\nFILE '" << fileName << "' SUCCESSFULLY DELETED!\n";
	}
	else {
		cout << "\n\nFILE '" << fileName << "' COULD NOT BE DELETED!\n";
	}

}
void Arrangement::display(){         //Prints all data for one event
    int temp, day, month, year;
    
    day = date/1000000;          //Makes one int from ddmmyear
    temp = date%1000000;
    month = temp/10000;
    year = temp%10000;
    
    cout << "Event Nr " << eventNumber << ':';
    cout << "\n\tEvent name:             " << eventName << endl;
    cout << "\tVenue:                  " << venueName << endl;
	cout << "\tLayout no.:             " << layoutNumber << endl;
    cout << "\tArtist:                 " << artistName << endl;
	cout << "\tEvent Type:             "; cout << enumDisplay(eventType) << endl;
	cout << "\tEvent date and time:    ";
    
	if (day < 10)           //Adds zero on dates and time if number is under 10
	{
		cout << "0";
	}
	
   cout << day << ".";

   if (month < 10)
   {
	   cout << "0";
   }

   cout << month << "." << year << "  ";
   
   if (hour < 10)
   {
	   cout << '0';
   }
   cout << hour << ":";
   
   if (min < 10)
   {
	   cout << '0';
   }
   cout << min << endl;
	
    
}
void Arrangement::displayAllData()      //displayes all info of an event
{
	List* zones = NULL;

	zones = readFromARRXXFile();        //  Reads from arr_xx
	
	zones->displayList();               // displayes zones for event

	delete zones;                       // Delete zone copy


}

List* Arrangement::readFromARRXXFile() {
	List* zoneList = NULL;
	
	Vrimle* swarmTmp;
	Stoler* seatTmp;
	enum zoneType typeOfZone;
	char buffer[STRLEN], nameOfZone[STRLEN];
	char fileName[STRLEN / 4] = "ARR_";
	char evntNo[STRLEN / 16];
	int noOfZones;

	zoneList = new List(Sorted);

	sprintf(evntNo, "%d", eventNumber);								//	Tried using iota(), causes compiler error	
	strcat(fileName, evntNo);                               //Makes unique filename
	strcat(fileName, ".DTA");
	
	ifstream inn(fileName);
	
	if (inn)
	{
		inn.ignore(STRLEN, '\n');		//	Skips the first 8 lines of Arr_xx files
		inn.ignore(STRLEN, '\n'); 
		inn.ignore(STRLEN, '\n'); 
		inn.ignore(STRLEN, '\n'); 
		inn.ignore(STRLEN, '\n'); 
		inn.ignore(STRLEN, '\n');
		inn.ignore(STRLEN, '\n'); 
		inn.ignore(STRLEN, '\n'); 
		
		
		inn >> noOfZones; inn.ignore();             // Reads number of zones
		
		for (int i = 1; i <= noOfZones; i++)
		{
			
			inn.getline(buffer, STRLEN);            //Reads zone type
			if (strcmp(buffer, "stoler") == 0)      // If zone is stoler
			{
				typeOfZone = stoler;
				inn.getline(nameOfZone, STRLEN);    //Reads name of zone
				seatTmp = new Stoler(nameOfZone, inn, typeOfZone);  //Creates object
				zoneList->add(seatTmp);                         //Adds it to zone list
			}
			if (strcmp(buffer, "vrimle") == 0)      //If zone is vrimle
			{
				typeOfZone = vrimle;
				inn.getline(nameOfZone, STRLEN);    //Reads name of zone
				swarmTmp = new Vrimle(nameOfZone, inn, typeOfZone); //Creates object
				zoneList->add(swarmTmp);                //Adds it to zone list
			}
		}
	}
	else
		cout << "\n\n\t\tCOULD NOT FIND FILE '" << fileName << "'!\n\n";

	return zoneList;            //Return zone list
}
void Arrangement::purchaseTickets()         //Purchasing tickets
{
	Sone* zonePtr;
	Stoler* seatPtr;
	Vrimle* swarmPtr;

	List* zones = NULL;
	int custNo, lastCust, zoneType, reservationStatus = 0;
	int seat, row, ticketPrice, day, month, year, temp;
	
	char selectedZone[STRLEN]; 
	char eventCategory[STRLEN / 4];


	lastCust = customerDatabase.returnLastCustomer();   //Gets number of customers
	zones = readFromARRXXFile();                    //Reads event from file
	

	custNo = read("\nCUSTOMER NUMBER", 1, lastCust);    //Which customer who wants to buy
	
	if (customerDatabase.customerExists(custNo))        // Checks if customer is in database
	{ 
		cout << "\n\nZONES LIST DISPLAY LIST";
		zones->displayList();                           //Displayes zones
		read("\nZONE NAME", selectedZone, STRLEN);
		
		if (zones->inList(selectedZone))            //Checks if selected zone exists
		{
			zonePtr = (Sone*)zones->remove(selectedZone);
			zoneType = zonePtr->returnZoneType();     //Zone type gets added to zoneType
			ticketPrice = zonePtr->getPrice();        //Gets ticketprice
			zones->add(zonePtr);

			if (zoneType == 0)                      //If zero, event type is stoler
			{
				
				seatPtr = (Stoler*)zones->remove(selectedZone);
				do                          //Ask which seat customer wants
				{
					cout << "\n\tSEAT: "; cin >> seat;
					cout << "\tROW:  "; cin >> row;
					reservationStatus = seatPtr->purchaseSeat(seat, row, custNo);   //Cheks if seat is available

				} while (reservationStatus != 1);       //loops till seat is valid
				
				zones->add(seatPtr);
			}
			if (zoneType == 1)             //If 1, event type is vrimle
			{
				
				swarmPtr = (Vrimle*)zones->remove(selectedZone);
				reservationStatus = swarmPtr->purchaseSwarm(custNo);   //Checks if sold out
				zones->add(swarmPtr);
			}
		}
		else
			printError("INVALID ZONE!");

	}
	else
	{
		printError("COULD NOT VERIFY CUSTOMER NUMBER!");
	}

	
	if (reservationStatus == 1)											//	Writes tickets
	{
		ofstream out("BILLETTER.DTA", ios::app);						//	Appends to the existing file
		
		day = date / 1000000;											//makes date to 3 int's
		temp = date % 1000000;
		month = temp / 10000;
		year = temp % 10000;


		writeCharToFile('*', 40, out); out << '\n';   //Star line

		out << day << '/' << month << '-' << year << '\n';	    //Writes date
		out << "TICKET NO.: " << (eventNumber * 100000) + custNo << '\n';   //Writes ticketnumber
		out << "Customer:   " << custNo << '\n';                    // Writes customer number
		
		out << "(" << enumDisplay(eventType) << ") ";           // Writes event type
		out << eventName << ", " << artistName << '\n';         // Writes artist name
		out << venueName << '\n';                               // Writes venue name
		out << day << '/' << month << '-' << year << ' ';       // Writes Date
        
		if (hour < 10)                  //Makes an extra zero if hour or time is under 10
			out << '0';

		out << hour << ':';

		if (min < 10)
			out << '0';

		out << min << '\n';
		out << selectedZone << '\n';            // Writes selected zone
		if (zoneType == 0)                      // if zone is stole
			out << "SEAT/ROW: " << seat << "/" << row << '\n';
		else                                    // if zones is vrimle
			out << "Vrimle" << '\n';

		out << "KR " << ticketPrice << ",-" << '\n';        // Writes ticketsprice
		writeCharToFile('*', 40, out); out << '\n';         // Star line

		writeToARRXXFile(zones);						//	Writes to file
		
		
	}
}
bool Arrangement::compareEventNumber(int eveNr) //compares event number
{
    return (eveNr == eventNumber) ? true : false;
}
bool Arrangement::compareEventNameExact(char query[])  //compares exact event name
{
	return !strcmp(eventName, query);
}
bool Arrangement::compareEventName(char query[])    //compares event name
{
    return strstr(eventName, query);
}
bool Arrangement::compareArtistName(char query[]) //compares artist name
{
	return !strcmp(artistName, query);
	
}
bool Arrangement::compareEventDate(int searchDate) //compares event date
{
	return (searchDate == date) ? true : false;
}
bool Arrangement::compareVenueName(char query[])    //compares venue name
{
    return !strcmp(venueName, query);
}
bool Arrangement::compareEventType(enum eventType type) //Compares event type
{
    return (type == eventType) ? true : false;
}
const char* Arrangement::getEventName()        //returns event name
{
    return eventName;
}
const char * Arrangement::getVenueName()          //returns venue name
{
	return venueName;
}
const char* Arrangement::enumDisplay(enum eventType type){ //Returns enumn name
    
    switch (type) 
	{
	case Musikk:	return "Music";		break;
    case Sport:		return "Sport";		break;
    case Teater:	return "Theatre";	break;
    case Show:		return "Show";		break;
    case Kino:		return "Cinema";	break;
    case Familie:	return "Family";	break;
    case Festival:	return "Festival";	break;
    }
    
}

void Arrangement::writeToARRXXFile(List * zones)
{
	Sone* zonePtr;
	Stoler* seatPtr;
	Vrimle* swarmPtr;
	int zoneType;
	char tempZoneName[STRLEN / 8];
	char filePrefix[STRLEN / 4] = "ARR_";
	char evntNo[STRLEN / 8];

	

	sprintf(evntNo, "%d", eventNumber);				//Creates unique filename
	strcat(filePrefix, evntNo);
	strcat(filePrefix, ".DTA");
	
	ofstream out(filePrefix);                       //Opens file
	writeToFile(out);                           //Calls write to file function
	out << zones->noOfElements() << '\n';					//	Number of zones
	for (int i = 1; i <= zones->noOfElements(); i++)        //loops number of zones
	{		
		zonePtr = (Sone*)zones->removeNo(i);
		zoneType = zonePtr->returnZoneType();
		

		if (zoneType == 0)          //If zone type is zero = stoler
		{
			zones->add(zonePtr);
			out << "stoler" << '\n';
			seatPtr = (Stoler*)zones->removeNo(i);
			seatPtr->writeToFile(out);  //Writes seats to file
			zones->add(seatPtr);
		}
		if (zoneType == 1)
		{
			zones->add(zonePtr);    //If zone type is 1 = vrimle
			out << "vrimle" << '\n';
			swarmPtr = (Vrimle*)zones->removeNo(i);
			swarmPtr->writeToFile(out);  //Writes vimle to file
			zones->add(swarmPtr);
		}
	}

	 delete zones;                  //Delete copy of zones
}

void Arrangement::writeToFile(ofstream & out) {  //Writes events to file
   
    int temp, day, month, year;
    
    out << eventNumber << '\n';               //Writes alle data
    out << eventName << '\n';
    out << venueName << '\n';
	out << layoutNumber << '\n';
    out << artistName << '\n';
    
    switch (eventType) {                      //Takes event type en writes Letters to file
        case Musikk:     out << 'M';   break;
        case Sport:      out << 'S';   break;
        case Teater:     out << 'T';   break;
        case Show:       out << 'W';   break; //W - For show to avoid reading error
        case Kino:       out << 'C';   break;
        case Familie:    out << 'F';   break;
        case Festival:   out << 'V';   break; //V - For festival to avoid reading error
    }
    out << '\n';
    
    day = date/1000000;                  //makes date to 3 int's
    temp = date%1000000;
    month = temp/10000;
    year = temp%10000;
    
    out << day << '/' << month << '-' << year << '\n';
    
    if (hour < 10)            //Adds zero if its under 10
    {
        out << '0';
    }
    out << hour << ":";
    
    if (min < 10)            //Adds zero if its under 10
    {
        out << '0';
    }
    out << min << '\n';
    
    
}

Arrangement::Arrangement(int eNr, char n[], ifstream & inn) : TextElement(n) {
	char typeChar, buffer[STRLEN];
    int day, month, year;
    
	eventNumber = eNr;                            //Reads int into eventNumber

    eventName = new char[strlen(n) + 1];           //Reads eventName
    strcpy(eventName, n);
    
	
    inn.getline(buffer, STRLEN);				   //Reads venuName
	venueName = new char[strlen(buffer) + 1];
	strcpy(venueName, buffer);
	
	inn >> layoutNumber; inn.ignore();          //reads used layout number

	inn.getline(buffer, STRLEN);                //Reads artist name
	artistName = new char[strlen(buffer) + 1];
	strcpy(artistName, buffer);
	

    inn >> typeChar;                      // Reads eventType from char to enum
    switch (typeChar) {
        case 'M':  eventType = Musikk;    break;
        case 'S':  eventType = Sport;     break;
        case 'T':  eventType = Teater;    break;
        case 'W':  eventType = Show;      break;
        case 'C':  eventType = Kino;      break;
        case 'F':  eventType = Familie;   break;
        case 'V':  eventType = Festival;  break;
        default: cout << "\n\tUlovlig Status'verdi på fila!\n\n";  break;
    }
    
    inn >> day; inn.ignore();             //Reads day, month and year
    inn >> month; inn.ignore();
    inn >> year;
    date = (day * 1000000) + (month * 10000) + year; //Adds all to one int
    
    inn >> hour; inn.ignore();           //Reads hour and min
    inn >> min;
}

Arrangement::~Arrangement() {       //Destructor for Arrangement
    delete[] eventName;
    delete[] artistName;
    delete[] venueName;
}

int Arrangement::getEventNr(){      //Return eventnumber
    return eventNumber;
}

int Arrangement::getLayout()       //Returns layout number for event
{
	return layoutNumber;
}

