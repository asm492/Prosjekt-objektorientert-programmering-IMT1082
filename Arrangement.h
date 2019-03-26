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
    int date, hh, mm;
    eventType eventType;
    
public:
    
    Arrangement(int eNr, char eventName[]);
    
    const char* enumDisplay(enum eventType type);
    
    void display();
    void printEventTypeMenu();
    bool compareEvent(char query[]);
    int compare(Arrangement* arr);                //    Virtual fra listtool
    
};




#endif
