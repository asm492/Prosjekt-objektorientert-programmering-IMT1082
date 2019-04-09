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
    zoneName = new char[strlen(n) + 1]; //	NEW
    strcpy(zoneName, n);
	typeOfZone = type;	
	//ticketsForSale = sumSeats;
	cout << "\nNO. OF TICKETS FOR SALE?:   "; cin >> ticketsForSale;
	ticketsSold = 0;
	ticketPrice = read("TICKET PRICE FOR ZONE", MINTICKETPRICE, MAXTICKETPRICE);

}
Sone::Sone(char n[], ifstream & inn, enum zoneType type) : TextElement(n)
{
	typeOfZone = type;
	zoneName = new char[strlen(n) + 1];
	strcpy(zoneName, n);

	inn >> ticketsForSale >> ticketsSold >> ticketPrice; 
	inn.ignore();
}
Sone::Sone(Sone* s, enum zoneType type) : TextElement(s->text) {
	typeOfZone = type;
	ticketsForSale = s->ticketsForSale;
	ticketsSold = s->ticketsSold;
	ticketPrice = s->ticketPrice;
	
}
Sone::~Sone() {						
	delete zoneName;
}
int Sone::returnZoneType() {
	switch (typeOfZone)
	{
	case stoler: return 0; break;
	case vrimle: return 1; break;
	}
}
void Sone::display() {

	cout << "\nZone type:             ";
	
	switch (typeOfZone)
	{
	case stoler: cout << "Stoler"; break;
	case vrimle: cout << "Vrimle";  break;
	}
	
	
    cout << "\nZone name:             " << text << endl;
	cout << "Total no. of tickets:  " << ticketsForSale << endl;
    cout << "Tickets left for sale: " << ticketsForSale - ticketsSold << endl;
    cout << "Ticket price:          " << ticketPrice << endl;
    
}

void Sone::writeToFile(ofstream & out)
{
	
	out << text << '\n';
	out << ticketsForSale << ' ' << ticketsSold << ' ' << ticketPrice << '\n';
}
int Sone::getPrice() {
	return ticketPrice;
}
char* Sone::returnZoneName() {
	return zoneName;
}
