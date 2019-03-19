#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include <fstream>
#include <cstring>
#include "Stoler.h"

using namespace std;

/*************  2D dynamic array  - DON'T DELETE: ***********/
	/*
	cout << "Hvor mange? Sete pr rad * Rad "; cin >> seatPrRow >> rows;

	int** A = new int*[seatPrRow];

	for (int i = 0; i < seatPrRow; i++)
	{
		A[i] = new int[rows];
	}

	for (int i = 0; i < seatPrRow; i++)					//	REMOVE, FILLS RANDOM
	{
		for (int j = 0; j < rows; j++)
		{
			A[i][j] = (rand() % 100) + 1;
		}

	}

	for (int i = 0; i < seatPrRow; i++)
	{
		for (int j = 0; j < rows; j++)
			std::cout << A[i][j] << " ";

		cout << endl;
	}

	// deallocate memory using delete[] operator
	for (int i = 0; i < seatPrRow; i++)
		delete[] A[i];

	delete[] A;
	*/


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