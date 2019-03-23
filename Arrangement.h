
#ifndef Arrangement_h
#define Arrangement_h

#include <fstream>
#include "ListTool2B.h"
#include "enums.h"

class Arrangement : TextElement {
private:
    char* name;
    int eventNumber;			
    int date, hh, mm;
    eventType eventType;
    
public:
    void display();
    bool compareEvent(char query[]);
    
};




#endif
