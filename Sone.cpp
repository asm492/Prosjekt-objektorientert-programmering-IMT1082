#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "functions.h"
#include "Sone.h"
#include <fstream>
#include <iostream>
#include "conster.h"

using namespace std;

Sone::Sone(char n[]) : TextElement(n){			//	THIS CONSTRUCTOR IS USED BY STOLER() BECAUSE IT HAS
																//	TO KNOW HOW MANY SEATS WERE CONFIGURED. 
																//	Total TicketsForSale must be equal to Stoler::seatPrRow * rows.
    zoneName = new char[strlen(n) + 1]; //	NEW
    strcpy(zoneName, n);
    
	//ticketsForSale = sumSeats;
	ticketsForSale = read("NO. OF TICKETS FOR SALE?", MINTICKETSSALE, MAXTICKETSSALE);		//	How to distinguish between STOLER AND VRIMLE?
	ticketsSold = 0;
	ticketPrice = read("TICKET PRICE FOR ZONE", MINTICKETPRICE, MAXTICKETPRICE);

}
Sone::Sone(char n[], ifstream & inn) : TextElement(n)
{
	zoneName = new char[strlen(n) + 1];
	strcpy(zoneName, n);

	inn >> ticketsForSale >> ticketsSold >> ticketPrice; 
	inn.ignore();
}
Sone::~Sone() {						
    
}

void Sone::display() {
    cout << "\nZone name:             " << zoneName << endl;
	cout << "Total no. of tickets:  " << ticketsForSale << endl;
    cout << "Tickets left for sale: " << ticketsForSale - ticketsSold << endl;
    cout << "Ticket price:          " << ticketPrice << endl;
    
}

void Sone::writeToFile(ofstream & out)
{
	
	out << zoneName << '\n';
	out << ticketsForSale << ' ' << ticketsSold << ' ' << ticketPrice << '\n';
}
