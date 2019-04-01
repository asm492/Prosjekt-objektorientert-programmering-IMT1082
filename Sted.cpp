
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include "Sted.h"
#include "Stoler.h"
#include "Vrimle.h"
#include "Sone.h"
#include "Oppsett.h"
#include "ListTool2B.h"
#include <cstring>

using namespace std;

Sted::Sted(char n[]) : TextElement(n) {
    
    lastUsedLayout = 0;
    
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    
    
    
}
Sted::Sted(char n[], ifstream & inn) : TextElement(n) {
    //Stoler* tempSeat;
    //Vrimle* tempSwarm;
	int layoutNo;
    //char zoneName[STRLEN];
    //char zoneType[STRLEN];
    
    name = new char[strlen(n) + 1];					//	Name of the venue
    strcpy(name, n);
    
    inn >> lastUsedLayout; //inn.ignore();
    
    for(int i = 1; i <= lastUsedLayout; i++){
        
		inn >> layoutNo; //inn.ignore();			//??????????????
		layouts[i] = new Oppsett(layoutNo, inn);
    }
}

void Sted::display(){
    cout << '\n' << "Venue:             " << name;
    cout << '\n' << "Number of layouts: " << lastUsedLayout;
    cout << '\n';
}

void Sted::displayName(){
    cout << name;
}

void Sted::newSeatLayout() {
    char buffer[STRLEN];
   // Oppsett* tmp;
    if (lastUsedLayout < 5)
    {                                                    //    To do: copy
        cout << "\nCreating new layout:" << endl;
        read("Enter name for zone", buffer, STRLEN);
        //layouts[++lastUsedLayout] = new Stoler(buffer);
        
    }
    else
    {
        printError("MAXIMUM NUMBER OF CONFIGURATIONS ARE ALREADY MADE!");
        
        
    }
    
}
void Sted::printSeatLayout() {
    int nr;
    
    if (lastUsedLayout > 0)
    {
        nr = read("Which layout do you want to display? Press '0' for all:", 0, lastUsedLayout);
        cout << '\n';
        if (nr != 0)
        {
            //layouts[nr]->printSeatMap();
        }
        else
        {
            for (int i = 1; i <= lastUsedLayout; i++)
            {
                //layouts[nr]->printSeatMap();
            }
        }
    }
    else
    {
        printError("NO LAYOUTS IN THE DATABASE");
    }
}
void Sted::writeToFile(ofstream & out) {
    out << name << '\n';
    out << lastUsedLayout << '\n';
    
    for (int i = 1; i <= lastUsedLayout; i++)
    {
		out << i << '\n';							//Layout number
        layouts[i]->writeToFile(out);
    }
}
void Sted::displayLayouts()			//	TESTING
{
	int layoutNo;

	layoutNo = read("WHICH LAYOUT TO DISPLAY? 0 = ALL", 0, lastUsedLayout);

	if (layoutNo == 0)
	{
		for (int i = 1; i <= lastUsedLayout; i++)									//	Prints all
		{
			cout << "\nLAYOUT NO " << i << " FOR " << name << ':' << endl;
			layouts[i]->printLayouts();												//	Calls Oppsett class' function	
		}
	}
	else {
		layouts[layoutNo]->printLayouts();
	}

	
}
/*
List * Sted::kopier(int nr)
{
	
	List* list = NULL;
	int i, ant;
	Sone *sone, *kopi;

	if (nr >= 1 && nr <= lastUsedLayout) {
		
		ant = layouts[nr]->noOfElements();

		list = new List(Sorted);
		for (i = 1; i <= ant; i++) {
			sone = (Sone*)layouts[nr]->removeNo(i);
			if (*sone == 'S')  kopi = new Stoler(*((Stoler*)sone));
			else kopi = new Vrimle(*((Vrimle*)sone));
			oppsett[nr]->add(sone);
			list->add(kopi);
		}
	}
	return list;
}*/
void Sted::newLayout() {
	char command;

	cout << "\nCURRENT NUMBER OF LAYOUTS: " << lastUsedLayout;
    
	if (lastUsedLayout < 5)
    {
		cout << "\nCreate layout from (S)cratch or (C)opy?: ";
		command = read();

		do
		{
			switch (command)
			{
			case 'S':
				cout << "\nCRATING LAYOUT NO. " << ++lastUsedLayout << " for " << name << ":\n\n";
				layouts[lastUsedLayout] = new Oppsett(lastUsedLayout); 
				layouts[lastUsedLayout]->newLayout(); break;		//PROGRAM STOPS HERE. TAKE A LOOK AT OPPSETT()....STED.CPP

			case 'C':
				//cout << "\nCRATING LAYOUT NO. " << ++lastUsedLayout << " for " << name << ":\n\n";
				/*layouts[lastUsedLayout] = new Oppsett();*/				break;

			default: printError("INVALID COMMAND, TRY AGAIN. S/C: ");	break;
			}
		} while (command != 'S' && command != 'C');

		
    }
    else
        printError("THIS VENUE HAS REACHED ITS MAX NO. OF LAYOUTS!");
}

bool Sted::compareVenueName(char text[]){
    return !strcmp(text, name);
}
