
#ifndef Steder_h
#define Steder_h
#include <fstream>
#include "ListTool2B.h"
#include "conster.h"
#include "Stoler.h"
#include "functions.h"

using namespace std;

class Sted : public TextElement {
private:
    char* name;
    int lastUsedLayout;
	Stoler* layouts[MAXLAYOUTS + 1];		//	Init to 1;  Pointers to all the different seat layouts
	List* zoneList;						

public:
    void display();
	void newSeatLayout();
	void printSeatLayout();
};
    

#endif 
