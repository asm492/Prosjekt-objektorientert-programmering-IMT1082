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
	int layoutNumber;
    int eventNumber;
    int date, hour, min;
    eventType eventType;
	
    
public:
    
    Arrangement(int eNr, char evntName[], char venName[], int layoutNo, List* zones);
    Arrangement(int eNr, char n[], ifstream & inn);
    ~Arrangement();
    
    const char* enumDisplay(enum eventType type);
    const char* getEventName();
	const char* getVenueName();
   
	void writeToARRXXFile(List* zones);
	List* readFromARRXXFile();
    void writeToFile(ofstream & out);
    void display();
	void purchaseTickets();
	void printTicket();
  //  void printEventTypeMenu();		//Moved to functions.cpp, because we need it in Arrangementer as well
    
    bool compareVenueName(char query[]);
	bool compareEventNameExact(char query[]);
	bool compareEventName(char query[]);
	bool compareArtistName(char query[]);
	bool compareEventDate(int searchDate);
	bool compareEventType(enum eventType type);
    bool compareEventNumber(int eveNr);
	


    int getEventNr();
	int getLayout();
	int compare(Arrangement* arr);                //    Virtual fra listtool
    
};




#endif
