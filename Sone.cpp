#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "functions.h"
#include "Sone.h"
#include <fstream>
#include <iostream>
#include "conster.h"
#include "enums.h"

using namespace std;

Sone::Sone(char n[], enum zoneType type) : TextElement(n){			
																 
                                                    //	Total TicketsForSale must be equal to Stoler::seatPrRow * rows.
    zoneName = new char[strlen(n) + 1];
    strcpy(zoneName, n);
	typeOfZone = type;	
	
	cout << "\nNO. OF TICKETS FOR SALE?:   "; cin >> ticketsForSale;    //Number of wanted tickets for zone
	ticketsSold = 0;                                                //Sets tickets sold to zero
	ticketPrice = read("TICKET PRICE FOR ZONE", MINTICKETPRICE, MAXTICKETPRICE);    //reads ticket price

}
Sone::Sone(char n[], ifstream & inn, enum zoneType type) : TextElement(n)
{
	typeOfZone = type;
	zoneName = new char[strlen(n) + 1];
	strcpy(zoneName, n);

	inn >> ticketsForSale >> ticketsSold >> ticketPrice;    //Reads tickets info
	inn.ignore();
}
Sone::Sone(Sone* s, enum zoneType type) : TextElement(s->text) {
	typeOfZone = type;
	ticketsForSale = s->ticketsForSale;
	ticketsSold = s->ticketsSold;
	ticketPrice = s->ticketPrice;
	
}
Sone::~Sone() {			//Deconstructor
	delete zoneName;
}
int Sone::returnZoneType() {        //Returns type value
	switch (typeOfZone)
	{
	case stoler: return 0; break;
	case vrimle: return 1; break;
	}
}
void Sone::display() {      //Display zones

	cout << "\nZone type:             ";
	
	switch (typeOfZone)  //Displayes zone type
	{
	case stoler: cout << "Stoler"; break;
	case vrimle: cout << "Vrimle";  break;
	}
	
	
    cout << "\nZone name:             " << text << endl;    //Zone name
	cout << "Total no. of tickets:  " << ticketsForSale << endl; //Tickets for sale
    cout << "Tickets left for sale: " << ticketsForSale - ticketsSold << endl; //Tickets left
    cout << "Ticket price:          " << ticketPrice << endl;   //Ticket price
    
}

void Sone::writeToFile(ofstream & out)  //Writes zone info to file
{
	
	out << text << '\n';        //Writes name
	out << ticketsForSale << ' ' << ticketsSold << ' ' << ticketPrice << '\n'; //Writes ticket info
}
int Sone::getPrice() {      //Returns ticketprice
	return ticketPrice;
}
char* Sone::returnZoneName() {          //Returns zone name
	return zoneName;
}
