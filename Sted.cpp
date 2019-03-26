#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include "Sted.h"
#include "Stoler.h"
#include "Vrimle.h"
#include "Sone.h"

using namespace std;

Sted::Sted(char n[]) : TextElement(n) {
    
    lastUsedLayout = 0;
    
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    
    
    
}
Sted::Sted(char n[], ifstream & inn) : TextElement(n) {
    Stoler* tempSeat;
    Vrimle* tempSwarm;
    char zoneName[STRLEN];
    char zoneType[STRLEN];
    
    name = new char[strlen(n) + 1];
    strcpy(name, n);
    
    inn >> lastUsedLayout; inn.ignore();
    
    for(int i = 1; i <= lastUsedLayout; i++){
        
        inn.getline(zoneName, STRLEN); inn.ignore();
        inn.getline(zoneType, STRLEN); inn.ignore();
        
        if(strcmp("Stoler", zoneName) == 0){
            //tempSeat = (Oppsett*)layouts[i] = new Stoler(zoneName, inn);
        }
        else if(strcmp("Vrimle", zoneName) == 0){
            //tempSwarm = (Oppsett*)layouts[i] = new Vrimle(zoneName, inn);
        }
        else{
            printError("AN ERROR OCCURED WHILE READING FROM 'STEDER.DTA'!");
        }
    }
}

void Sted::display(){
    cout << '\n' << "Venue:             " << name;
    cout << '\n' << "Number of layouts: " << lastUsedLayout;
    cout << '\n';
}

void Sted::newSeatLayout() {
    char buffer[STRLEN];
    Oppsett* tmp;
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
        layouts[i]->writeToFile(out);
    }
}
void Sted::newLayout() {
    
    if (lastUsedLayout < 5)
    {
        layouts[++lastUsedLayout] = new Oppsett();
    }
    else
        printError("THIS VENUE HAS REACHED ITS MAX NO. OF LAYOUTS!");
}
