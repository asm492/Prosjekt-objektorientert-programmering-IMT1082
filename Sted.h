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
	Oppsett* layouts[MAXLAYOUTS + 1];		//	Init to 1;  Pointers to all the different seat layouts
	//	Tror vi må ha dynamic array eller liste her
											
											//List* zoneList;						

public:
<<<<<<< HEAD
    void display();
    void displayName();
=======
	Sted(char n[]);
	Sted(char n[], ifstream & inn);
    
	void display();
	void newLayout();
>>>>>>> 55597ca36a03ec5a11661bdd0c63b1cf7df1ccf3
	void newSeatLayout();
	void printSeatLayout();
	void writeToFile(ofstream & out);
};
    

#endif 
