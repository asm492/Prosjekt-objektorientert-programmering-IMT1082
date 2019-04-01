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

using namespace std;

extern Steder venueDatabase;

Arrangement::Arrangement(int eNr, char n[]) : TextElement(n){
    char buffer[STRLEN];
    int dd, mm, yyyy, nr;
	

    eventNumber = eNr;
    
    
    eventName = new char[strlen(n) + 1];            //Allocating enough space
    strcpy(eventName, n);                            //for string + '\0'
    
    read("Enter artist name", buffer, STRLEN);
    artistName = new char[strlen(buffer) + 1];            //Allocating enough space
    strcpy(artistName, buffer);                            //for string + '\0'
    
    readAndUpcase("Enter venue name", buffer, STRLEN);
    if(venueDatabase.venueExist(buffer) == 0)
    printError("Venue not in database, please create a new venue");
    venueName = new char[strlen(buffer) + 1];            //Allocating enough space
    strcpy(venueName, buffer);
	

	
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
    

	/*
	REMEMBER TO READ 'Oppsett' FROM USER
	*/
    
    
}
void Arrangement::writeEventsToFile() {
	

}
void Arrangement::display(){
    int temp, day, month, year;
    
    day = date/1000000;
    temp = date%1000000;
    month = temp/10000;
    year = temp%10000;
    
    
    cout << "\nEvent name:             " << eventName << endl;
    cout << "Venue:                    "; venue->displayName(); cout << endl;

    cout << "Artist:                 " << artistName << endl;
	cout << "Event Type:             "; cout << enumDisplay(eventType) << endl;
	cout << "Event date and time:    "; //<< date << ' ';
    
	
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

bool Arrangement::compareEventName(char query[]) {
    
    return strstr(eventName, query);
    //return strcmp(name, query);
}
bool Arrangement::compareArtistName(char query[])
{
	return !strcmp(artistName, query);
	
}
bool Arrangement::compareEventDate(int searchDate)
{
	return (searchDate == date) ? true : false;
}
int Arrangement::compare(Arrangement* arr) {
    //Arrangement* arr1 = (TextElement*)arr;
    return 0;
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
