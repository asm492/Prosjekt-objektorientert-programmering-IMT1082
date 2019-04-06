#ifndef Sted_h
#define Sted_h

#include <fstream>
#include "ListTool2B.h"
#include "conster.h"
#include "Stoler.h"
#include "functions.h"
#include "Oppsett.h"
#include "Sone.h"
using namespace std;

class Sted : public TextElement {
private:
    char* name;
    int lastUsedLayout;
	List* venueLayouts[MAXLAYOUTS + 1];
	Oppsett* layouts[MAXLAYOUTS + 1];        //    Init to 1;  Pointers to all the different seat layouts
    
	
    //List* zoneList;
    
public:
    Sted(char n[]);						//	Updated
    Sted(char n[], ifstream & inn);
    
    int compareVenueName(char text[]);
	void writeToFile(ofstream & out);
    void display();
    void displayName();
    void newLayout();
	void newLayoutFromCopy();
    void newSeatLayout();
    void printSeatLayout();
	void displayLayouts();					//	Testing
	int returnLastUsedLayout();
	void editExistingLayout();
	List* getLayout(int layoutN);
	List* kopier(int nr);

	/*NEW CODE AFTER REMOVAL OF Oppsett* layouts[]*/
	void newVenueLayout();
	void addZones(int nr);
	void editLayout();
	void displayLayout();




};


#endif 


