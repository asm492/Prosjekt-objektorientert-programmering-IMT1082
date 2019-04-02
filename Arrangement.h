#ifndef Arrangement_h
#define Arrangement_h

#include <fstream>
#include "ListTool2B.h"
#include "enums.h"
#include "Sted.h"
#include "Steder.h"

extern Steder venueDatabase;

class Arrangement : public TextElement {
private:
    char* eventName;
    char* artistName;
    char* venueName;

    Sted* venue;
    int eventNumber;
    int date, hour, min;
    eventType eventType;
	
    
public:
    
    Arrangement(int eNr, char evntName[], char venName[]);
    Arrangement(char n[], ifstream & inn);
    
    
    const char* enumDisplay(enum eventType type);
    
   
    void writeToFile(ofstream & out);
    void display();
	
  //  void printEventTypeMenu();		//Moved to functions.cpp, because we need it in Arrangementer as well
    
    bool compareVenueName(char query[]);
	bool compareEventName(char query[]);
	bool compareArtistName(char query[]);
	bool compareEventDate(int searchDate);
	bool compareEventType(enum eventType type);
	
	int compare(Arrangement* arr);                //    Virtual fra listtool
    
};




#endif
