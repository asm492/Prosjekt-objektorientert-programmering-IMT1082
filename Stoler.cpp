#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <cstring>
#include "Stoler.h"
#include "Sone.h"
#include "Sted.h"            /***********/

using namespace std;

Stoler::Stoler(char name[]) : Sone(name) {			//	Sends name to base class
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
    
    tempArray = new int*[seatPrRow];					//	First pointer points to new int pointer
    
    for (int i = 1; i <= seatPrRow; i++)
    {
        tempArray[i] = new int[rows];
    }
    
    for (int i = 1; i <= rows; i++)                    //    Fills with 0
    {
        for (int j = 1; j <= seatPrRow; j++)
        {
			tempArray[i][j] = 0;
        }
    }

	//ticketsForSale = rows * seatPrRow;					//	Is this ok? How to distinguish stoler/vrimle?

	/*
	DELETE AFTER TEST
	for (int i = 1; i <= rows; i++)
	{
		cout << "\t" << i << ". ";
		for (int j = 1; j <= seatPrRow; j++)
		{
			if (temp[i][j] == 0)							//	THIS DOESNT WORK
			{
				cout << '-';								//	Seat is free
			}
			else
			{
				cout << 'x';								//	Seat is taken
			}
		}
		cout << endl;
	}
    */
	/*
	for (int i = 0; i < seatPrRow; i++)
	{
		for (int j = 0; j < rows; j++)
			cout << temp[i][j];

		cout << endl;
	}*/
    
    // deallocate memory using delete[] operator
    //for (int i = 0; i < seatPrRow; i++)
    //delete[] temp[i];
    
    //delete[] temp;
}
Stoler::Stoler(char name[], ifstream & inn) : Sone(name, inn)
{
	inn >> seatPrRow >> rows; //inn.ignore();
}





/*
 int** a = new int*[rowCount];
 for(int i = 0; i < rowCount; ++i)
 a[i] = new int[colCount];
 
 new:
 int **ary = new int*[sizeY];
 for(int i = 0; i < sizeY; ++i) {
 ary[i] = new int[sizeX];
 
 slette:
 for(int i = 0; i < sizeY; ++i) {
 delete [] ary[i];
 }
 delete [] ary;
 }
 */

void Stoler::configureSeats() {
    
}

void Stoler::printSeatMap() {
	//int** tempArray;									//	Declaring an int pointer to int pointer
												//	Makes a 2D dynamic int array

	/*tempArray = new int*[seatPrRow];					//	First pointer points to new int pointer
	
	
	for (int i = 1; i <= rows; i++)
	{
		tempArray[i] = new int[seatPrRow];				//change
	}*/
	








	/********remove
	for (int i = 1; i <= rows; i++)                    //    Fills with 0
	{
		for (int j = 1; j <= seatPrRow; j++)
		{
			tempArray[i][j] = 0;
		}
	}
	***************************/

	for (int i = 1; i <= rows; i++)
	{
		cout << "\t" << i << ". ";
		if (i < 10)
		{
			cout << ' ';
		}

		for (int j = 1; j <= seatPrRow; j++)
		{
			if (tempArray[i][j] == 0)							//	THIS DOESNT WORK
			{
				cout << '-';								//	Seat is free
			}
			else
			{
				cout << 'x';								//	Seat is taken
			}
		}
		cout << endl;
	}

	cout << "\n\n";


	/*TEST TO SEE WHICH NUMBER*/
	for (int i = 1; i <= rows; i++)
	{
		cout << "\t" << i << ". ";
		for (int j = 1; j <= seatPrRow; j++)
		{
			cout << tempArray[i][j] << ' ';
		}
		cout << endl;
	}
	/****************************/
}

void Stoler::writeToFile(ofstream & out)
{
	out << "Stoler" << '\n';
	Sone::writeToFile(out);
	out << seatPrRow << ' ' << rows << '\n';
}

void Stoler::display() {
	
	Sone::display();
	cout << "\nSEATS PR ROW / ROWS:  " << seatPrRow << " / " << rows << endl;
	//	REMEMBER TO FILL ARRAY WITH CUSTOMERNUMBER OF BUYERS
	printSeatMap();
}
