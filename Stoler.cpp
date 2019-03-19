#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include <fstream>
#include <cstring>
#include "Stoler.h"
//#include "Sted.h"			/***********/

using namespace std;

Stoler::Stoler() {
	
	
	cout << "\nNumber of seats per row?: "; cin >> seatPrRow;
	cout << "Number of rows?: "; cin >> rows;

	int** temp = new int*[seatPrRow];

	for (int i = 0; i < seatPrRow; i++)
	{
		temp[i] = new int[rows];
	}

	for (int i = 0; i < seatPrRow; i++)					//	Fills with 0
	{
		for (int j = 0; j < rows; j++)
		{
			temp[i][j] = 0;
		}

	}

	for (int i = 0; i < seatPrRow; i++)
	{
		for (int j = 0; j < rows; j++)
			std::cout << temp[i][j] << " ";

		cout << endl;
	}

	// deallocate memory using delete[] operator
	//for (int i = 0; i < seatPrRow; i++)
		//delete[] temp[i];

	//delete[] temp;
	



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

}

void Stoler::display() {

}