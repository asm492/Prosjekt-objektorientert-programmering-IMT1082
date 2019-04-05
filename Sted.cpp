
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
    int layoutNo;
    
    
    name = new char[strlen(n) + 1];					//	Name of the venue
    strcpy(name, n);
    
    inn >> lastUsedLayout; //inn.ignore();
    
    for(int i = 1; i <= lastUsedLayout; i++){
        
		inn >> layoutNo; //inn.ignore();			//??????????????
		layouts[i] = new Oppsett(layoutNo, inn);
		//inn.ignore();
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

void Sted::display(){
    cout << "\nVenue:             " << name;
	cout << "\nNumber of layouts: " << lastUsedLayout << endl;
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
void Sted::displayLayouts()			//	TESTING
{
	int layoutNo;

	layoutNo = read("WHICH LAYOUT TO DISPLAY? 0 = ALL", 0, lastUsedLayout);

	if (layoutNo == 0)
	{
		for (int i = 1; i <= lastUsedLayout; i++)									//	Prints all
		{
			cout << "\nLAYOUT NO " << i << " FOR " << name << ':' << endl;
			
			layouts[i]->display();												//	Calls Oppsett class' function	
		}
	}
	else {
		layouts[layoutNo]->display();
	}

	
}
int Sted::returnLastUsedLayout()
{
	return lastUsedLayout;
}
void Sted::editExistingLayout()
{
	int nr;
	char ch;

	nr = read("WHICH LAYOUT TO EDIT?", 1, lastUsedLayout);

	cout << "\nWHAT DO YOU WANT TO DO TO LAYOUT NR. " << nr << "?:" << endl;
	cout << "\n\tA\tAdd new zone from scratch";
	cout << "\n\tC\tAdd new zone from a copy";
	cout << "\n\tR\tRemove a zone";
	cout << "\n\tD\tChange the details" << endl;
	ch = read();
	switch (ch)
	{
	case 'A': layouts[nr]->addNewZone();		break;
	case 'C': /*layouts[nr]->addNewCopy();*/	break;
	case 'R': if (layouts[nr]->removeZone() == true)
	{
		layouts[nr] = nullptr;							//	Deletes layout if deleted
		--lastUsedLayout;								//	zone was the last one in layout
	}												break;
	case 'D': if (layouts[nr]->deleteLayout() == true)
	{
		layouts[nr] = nullptr;
		--lastUsedLayout;
	}
		break;
	default: printError("INVALID COMMAND!");	break;
	}

}
List* Sted::getLayout(int layoutN)
{
	List* listPtr = nullptr;
	cout << "\n3";
	if (layouts[layoutN]->copyZone() == nullptr)
	{
		cout << "den peker til nullptr";
	}
	else {
		listPtr = layouts[layoutN]->copyZone();
		//layouts[layoutN]->display();
	}
	//layouts[layoutN]->display();
	cout << "\n3.5";
	
	return listPtr;
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
				//layouts[lastUsedLayout]->newLayout(); break;		//PROGRAM STOPS HERE. TAKE A LOOK AT OPPSETT()....STED.CPP

			case 'C': /*newLayoutFromCopy();*/
				//cout << "\nCRATING LAYOUT NO. " << ++lastUsedLayout << " for " << name << ":\n\n";
				/*layouts[lastUsedLayout] = new Oppsett();*/				break;

			default: printError("INVALID COMMAND, TRY AGAIN. S/C: ");	break;
			}
		} while (command != 'S' && command != 'C');

		
    }
    else
        printError("THIS VENUE HAS REACHED ITS MAX NO. OF LAYOUTS!");
}
void Sted::newLayoutFromCopy() {
	char buffer[STRLEN];
	

	read("WHICH LAYOUT NR. TO COPY FROM?", buffer, STRLEN);

	
	++lastUsedLayout;
}
int Sted::compareVenueName(char text[]){
    return !strcmp(name, text);
    
}
