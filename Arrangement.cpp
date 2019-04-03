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

using namespace std;

extern Steder venueDatabase;

Arrangement::Arrangement(int eNr, char evntName[], char venName[]) : TextElement(evntName){
    char buffer[STRLEN];
    int dd, mm, yyyy, nr;
   
    
	
		eventNumber = eNr;

		eventName = new char[strlen(evntName) + 1];            //Allocating enough space
		strcpy(eventName, evntName);                            //for string + '\0'

		venueName = new char[strlen(venName) + 1];            //Allocating enough space
		strcpy(venueName, venName);                            //for string + '\0'


		read("Enter artist name", buffer, STRLEN);
		artistName = new char[strlen(buffer) + 1];            //Allocating enough space
		strcpy(artistName, buffer);                            //for string + '\0'



		do
		{
			cout << "\nDATE:";
			dd = read("Type day", DAYMIN, DAYMAX);
			mm = read("Type month", MONTHMIN, MONTHMAX);
			yyyy = read("Type year", YEARMIN, YEARMAX);

			if (dayNumber(dd, mm, yyyy) == 0)
			{
				printError("INVALID DATE! TRY AGAIN!");
			}
		} while (dayNumber(dd, mm, yyyy) == 0);

		date = (dd * 1000000) + (mm * 10000) + yyyy;                //    Converts date format to 1 int

		cout << "\nTIME:";
		hour = read("Type hours", HOURMIN, HOURMAX);
		min = read("Type minutes", MINUTEMIN, MINUTEMAX);

		printEventTypeMenu();                    // Causes Linker2019 error
		nr = read("Choice", 0, 6);

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

void Arrangement::display(){
    int temp, day, month, year;
    
    day = date/1000000;
    temp = date%1000000;
    month = temp/10000;
    year = temp%10000;
    
    cout << "Event Nr " << eventNumber << ':';
    cout << "\n\tEvent name:             " << eventName << endl;
    cout << "\tVenue:                  " << venueName << endl;

    cout << "\tArtist:                 " << artistName << endl;
	cout << "\tEvent Type:             "; cout << enumDisplay(eventType) << endl;
	cout << "\tEvent date and time:    ";
    
	if (day < 10)
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
bool Arrangement::compareEventNumber(int eveNr){
    return (eveNr == eventNumber) ? true : false;
}
bool Arrangement::compareEventNameExact(char query[]) {
	return !strcmp(eventName, query);
}
bool Arrangement::compareEventName(char query[]) {
    
    return strstr(eventName, query);
    
}
bool Arrangement::compareArtistName(char query[])
{
	return !strcmp(artistName, query);
	
}
bool Arrangement::compareEventDate(int searchDate)
{
	return (searchDate == date) ? true : false;
}
bool Arrangement::compareVenueName(char query[]) {
    return !strcmp(venueName, query);
    
}
const char* Arrangement::getEventName() {
    return eventName;
}
const char* Arrangement::enumDisplay(enum eventType type){
    
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
bool Arrangement::compareEventType(enum eventType type) {
	return (type == eventType) ? true : false;
}

void Arrangement::writeToFile(ofstream & out) {
   
    int temp, day, month, year;
    
    out << eventNumber << '\n';
    out << eventName << '\n';
    out << venueName << '\n';
    out << artistName << '\n';
    
    switch (eventType) {                   //  Status skrives som bokstaver:
        case Musikk:     out << 'M';   break;
        case Sport:      out << 'S';   break;
        case Teater:     out << 'T';   break;
        case Show:       out << 'W';   break; //W - For show to avoid reading error
        case Kino:       out << 'C';   break;
        case Familie:    out << 'F';   break;
        case Festival:   out << 'V';   break; //V - For festival to avoid reading error
    }
    out << '\n';
    
    day = date/1000000;
    temp = date%1000000;
    month = temp/10000;
    year = temp%10000;
    
    out << day << '/' << month << '-' << year << '\n';
    
    if (hour < 10)
    {
        out << '0';
    }
    out << hour << ":";
    
    if (min < 10)
    {
        out << '0';
    }
    out << min << '\n';
    
    
}

Arrangement::Arrangement(int eNr, char n[], ifstream & inn) : TextElement(n) {
	char typeChar, buffer[STRLEN];
    int day, month, year;
    
	eventNumber = eNr;

    eventName = new char[strlen(n) + 1];                    
    strcpy(eventName, n);
    
	
    inn.getline(buffer, STRLEN);				
	venueName = new char[strlen(buffer) + 1];
	strcpy(venueName, buffer);
	

	inn.getline(buffer, STRLEN);
	artistName = new char[strlen(buffer) + 1];
	strcpy(artistName, buffer);
	

    inn >> typeChar;
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
    
    inn >> day; inn.ignore();
    inn >> month; inn.ignore();
    inn >> year;
    date = (day * 1000000) + (month * 10000) + year;
    
    inn >> hour; inn.ignore();
    inn >> min;
}

Arrangement::~Arrangement() {
    delete[] eventName;
    delete[] artistName;
    delete[] venueName;
}

int Arrangement::getEventNr(){
    return eventNumber;
}
