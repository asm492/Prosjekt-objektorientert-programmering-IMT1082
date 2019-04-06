#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <cstring>
#include "Stoler.h"
#include "Sone.h"
#include "Sted.h"            /***********/
#include "enums.h"

using namespace std;

Stoler::Stoler(char name[], enum zoneType type) : Sone(name, type) {			//	Sends name to base class
    //int** temp;									//	Declaring an int pointer to int pointer
												//	Makes a 2D dynamic int array
	//int tempTicketsForSale, tempTicketsSold, tempTicketPrice;
	

	do
	{
		cout << "\nNUMBER OF SEATS PR ROW?:    ";	cin >> seatPrRow;
		cout << "NUMBER OF ROWS?:            ";		cin >> rows;
		if (seatPrRow*rows != ticketsForSale)
		{
			printError("ROWS*SEATS PR ROW MUST EQUAL NUMBER OF TICKETS FOR SALE");
		}

	} while (seatPrRow*rows != ticketsForSale);
    
    tempArray = new int*[rows + 1];					//	First pointer points to new int pointer
    
    for (int i = 1; i <= rows; i++)
    {
        tempArray[i] = new int[seatPrRow + 1];
    }
    
    for (int i = 1; i <= rows; i++)                    //    Fills with 0
    {
        for (int j = 1; j <= seatPrRow; j++)
        {
			tempArray[i][j] = 0;
        }
    }

}
Stoler::Stoler(char name[], ifstream & inn, enum zoneType type) : Sone(name, inn, type)
{
	inn >> seatPrRow >> rows; inn.ignore();
	tempArray = new int*[rows + 1];					//	First pointer points to new int pointer

	for (int i = 1; i <= rows; i++)
	{
		tempArray[i] = new int[seatPrRow + 1];
	}

	for (int i = 1; i <= rows; i++)                    //    Fills with 0
	{
		for (int j = 1; j <= seatPrRow; j++)
		{
			tempArray[i][j] = 0;
		}
	}
}
Stoler::Stoler(Stoler & s) : Sone((Sone*)&s) {
	int i, j;
	seatPrRow = s.seatPrRow;
	rows = s.rows;
	
	tempArray = new int*[seatPrRow + 1];					//	First pointer points to new int pointer

	for (int i = 1; i <= rows; i++)
	{
		tempArray[i] = new int[seatPrRow + 1];
	}

	for (int i = 1; i <= rows; i++)                    //    Fills with 0
	{
		for (int j = 1; j <= seatPrRow; j++)
		{
			tempArray[i][j] = 0;
		}
	}

}
void Stoler::configureSeats() {
    
}
Stoler::~Stoler() {
	tempArray = nullptr;
}
void Stoler::printSeatMap() {		//	Used to display seat layout
	
	cout << "\n\t\tSEAT MAP:" << endl;
	cout << "\t\t    ";							//	USED TO WRITE SEAT NUMBER
	for (int k = 1; k <= seatPrRow; k++)
	{
		cout << " " << k;
		if (k < 10)
		{
			cout << ' ';
		}
	}
	cout << "\n";

	
	for (int i = 1; i <= rows; i++)
	{
		cout << "\t\t" << i << ". ";
		if (i < 10)
		{
			cout << ' ';
		}

		for (int j = 1; j <= seatPrRow; j++)
		{
			cout << " - "; 
		}
		cout << endl;
	}

	cout << "\n";


	/*TEST TO SEE WHICH NUMBER*/
	/*
	for (int i = 1; i <= rows; i++)
	{
		cout << "\t" << i << ". ";
		for (int j = 1; j <= seatPrRow; j++)
		{
			cout << tempArray[i][j] << ' ';
		}
		cout << endl;
	}
	*/
}
void Stoler::printSeatMapAvailibility() {		//	USED TO DISPLAY IF A SEAT IS 
												//	RESERVED OR FREE
	
	cout << "\n\t\tAVAILIBLE SEATS:" << endl;
	cout << "\t\t    ";							//	USED TO WRITE SEAT NUMBER
	for (int k = 1; k <= seatPrRow; k++)
	{
		cout << " " << k;
		if (k < 10)
		{
			cout << ' ';
		}
	}
	cout << "\n";



	for (int i = 1; i <= rows; i++)
	{
		
		cout << "\t\t" << i << ". ";
		if (i < 10)
		{
			cout << ' ';
		}

		for (int j = 1; j <= seatPrRow; j++)
		{
			if (tempArray[i][j] == 0)
			{
				cout << " - ";								//	Seat is free
			}
			else
			{
				cout << " x ";								//	Seat is taken
			}
		}
		cout << endl;
	}

	cout << "\n";
	////////////////
	
	


	/*TEST TO SEE WHICH NUMBER*/
	/*
	for (int i = 1; i <= rows; i++)
	{
		cout << "\t" << i << ". ";
		for (int j = 1; j <= seatPrRow; j++)
		{
			cout << tempArray[i][j] << ' ';
		}
		cout << endl;
	}
	*/
}

void Stoler::writeToFile(ofstream & out)
{
	
	Sone::writeToFile(out);
	out << seatPrRow << ' ' << rows << '\n';
}

void Stoler::display() {
	
	Sone::display();
	cout << "SEATS*ROWS:            " << seatPrRow << "*" << rows << endl;
	
	printSeatMap();
	
}
