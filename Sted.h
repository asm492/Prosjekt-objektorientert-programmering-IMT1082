#ifndef Sted_h
#define Sted_h

#include <fstream>
#include "ListTool2B.h"
#include "conster.h"
#include "Stoler.h"
#include "functions.h"
#include "Sone.h"
using namespace std;

class Sted : public TextElement {
private:
    char* name;
    int lastUsedLayout;
	List* venueLayouts[MAXLAYOUTS + 1];
	
    
	

    
public:
    Sted(char n[]);
    Sted(char n[], ifstream & inn);
    
    int compareVenueName(char text[]);
	void writeToFile(ofstream & out);
    void display();
    void displayName();
	void newLayoutFromCopy();
    void newSeatLayout();
   
	void changeDetails(int nr, char* zName);
	void displayLayouts();
	int returnLastUsedLayout();
    
	List* getLayout(int layoutN);
	

	
	void newVenueLayout();
	void addZones(int nr);
	void editLayout();
	void displayLayout();
	
};


#endif 


