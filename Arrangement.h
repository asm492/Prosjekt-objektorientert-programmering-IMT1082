
#ifndef Arrangement_h
#define Arrangement_h

#include <fstream>
#include "ListTool2B.h"
#include "enums.h"

class arrangement : TextElement {
private:
    char* name;
    int eventNumber;			//	Excess?? Listtool index
    int date, hh, mm;
    eventType eventType;
    
public:
    void display();
    
    
};




#endif
