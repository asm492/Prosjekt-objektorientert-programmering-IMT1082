#ifndef Arrangement_h
#define Arrangement_h

#include <fstream>
#include "ListTool2B.h"
#include "enums.h"
#include "Sted.h"
#include "Steder.h"

class Arrangement : public TextElement {
private:
    char* eventName;
    char* artistName;

    Sted* venue;
    int eventNumber;
    int date, hour, min;
    eventType eventType;
	
    
public:
    
    Arrangement(int eNr, char n[]);
    
    
    
    const char* enumDisplay(enum eventType type);
    
    void display();
	void writeEventsToFile();
  //  void printEventTypeMenu();		//Moved to functions.cpp, because we need it in Arrangementer as well
    
	bool compareEventName(char query[]);
	bool compareArtistName(char query[]);
	bool compareEventDate(int searchDate);
	bool compareEventType(enum eventType type);
	
	int compare(Arrangement* arr);                //    Virtual fra listtool
    
};




#endif
