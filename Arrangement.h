#ifndef Arrangement_h
#define Arrangement_h

#include <fstream>
#include "ListTool2B.h"
#include "enums.h"
#include "Sted.h"

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
    void printEventTypeMenu();
    
	bool compareEventName(char query[]);
	bool compareArtistName(char query[]);
	bool compareEventDate(int searchDate);
	
	int compare(Arrangement* arr);                //    Virtual fra listtool
    
};




#endif
