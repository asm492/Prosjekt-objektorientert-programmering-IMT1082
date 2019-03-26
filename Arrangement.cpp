#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "functions.h"
#include <iostream>
#include "Arrangement.h"
#include "conster.h"
#include "Sted.h"
#include "enums.h"

using namespace std;


Arrangement::Arrangement(int eNr, char eventName[]) {
    char buffer[STRLEN];
    int dd, mm, yyyy, nr;
    
    eventNumber = eNr;
    
    read("Enter event name", buffer, STRLEN);
    eventName = new char[strlen(buffer) + 1];            //Allocating enough space
    strcpy(eventName, buffer);                            //for string + '\0'
    
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
    hh = read("Type hours", HOURMIN, HOURMAX);
    mm = read("Type minutes", MINUTEMAX, MINUTEMAX);
    
    printEventTypeMenu();                    // Causes Linker2019 error
    nr = read("Choice", 0, 6);
    
    switch (nr)
    {
        case 0:    eventType = Musikk;            break;
        case 1:    eventType = Sport;            break;
        case 2:    eventType = Teater;            break;
        case 3:    eventType = Show;            break;
        case 4:    eventType = Kino;            break;
        case 5:    eventType = Familie;        break;
        case 6:    eventType = Festival;        break;
    }
    
}

void Arrangement::display(){
    int temp, day, month, year;
    
    day = date/1000000;
    temp = date%1000000;
    month = temp/10000;
    year = temp%10000;
    
    
    cout << "\nEvent name:        " << eventName << endl;
    cout << "Venue:               "; venue->displayName(); cout << endl;
    cout << "Artist:              " << artistName << endl;
    cout << "Event Type:          "; enumDisplay(eventType);
    cout << "Event date and time: ";
   
    if (day < 10)
     cout << "0";
    
    cout << day << "/";
    
    if (month < 10)
        cout << "0";
    
    cout << month << " - " << year << endl;
    
}

bool Arrangement::compareEvent(char query[]) {
    
    return strstr(eventName, query);
    //return strcmp(name, query);
}
int Arrangement::compare(Arrangement* arr) {
    //Arrangement* arr1 = (TextElement*)arr;
    return 0;
}
void Arrangement::printEventTypeMenu() {
    cout << "\n\nTYPE OF EVENT:";
    cout << "\n\t0\tMusic";
    cout << "\n\t1\tSport";
    cout << "\n\t2\tTheater";
    cout << "\n\t3\tShow";
    cout << "\n\t4\tCinema";
    cout << "\n\t5\tFamily";
    cout << "\n\t6\tFestival";
}

const char* Arrangement::enumDisplay(enum eventType type){
    
    switch (type) {
        case Musikk: return "Music";
        case Sport: return "Sport";
        case Teater: return "Theatre";
        case Show: return "Show";
        case Kino: return "Cinema";
        case Familie: return "Family";
        case Festival: return "Festival";
    }
    
}
