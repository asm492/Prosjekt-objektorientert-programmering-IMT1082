//
//  functions.cpp
//  ProsjektFil
//
//  Created by Sindre Hjelle on 18/03/2019.
//  Copyright © 2019 Sindre Hjelle. All rights reserved.
//

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "functions.h"
#include <iostream>
#include <cstring>              //  strlen
#include <cctype>               //  toupper


using namespace std;
// *******************   DEFINISJON AV GLOBALE FUNKSJONER:    ******************
char read() {                                    //    Henter ett ikke-blankt upcaset tegn:
    char ch;
    cin >> ch;   cin.ignore();                    //    Leser ETT tegn. Forkaster '\n'.
    return (toupper(ch));                        //  Upcaser og returnerer.
}
int read(const char t[], const int min, const int max) {
    int n;
    do {                                        //    Skriver ledetekst:
        cout << '\t' << t << " (" << min << '-' << max << "): ";
        cin >> n;   cin.ignore();                // Leser inn ett tall.
    } while (n < min || n > max);                // Sjekker at i lovlig intervall.
    return n;                                    // Returnerer innlest tall.
}                                                //  Leser en ikke-blank tekst:
void read(const char t[], char s[], const int LEN) {
    do {
        cout << '\t' << t << ": "; cin.getline(s, LEN); // Ledetekst og leser.
    } while (strlen(s) == 0);                    //  Sjekker at tekstlengden er ulik 0.
}
void readAndUpcase(const char t[], char s[], const int LEN) {
	do {
		cout << '\t' << t << ": "; cin.getline(s, LEN);		// Ledetekst og leser.
		for (int i = 0; i < strlen(s); i++)
		{
			s[i] = toupper(s[i]);
		}
	} while (strlen(s) == 0);                    //  Sjekker at tekstlengden er ulik 0.
}
void printError(const char t[]) {  //Function to print error messeges
    
    cout << "\n\n\t\t" << t << "\n\n";
    
}
int dayNumber(int dd, int mm, int yyyy) { //Checks if date input is valid
    int daysPrMonth[12] = { 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30,
        31 };
    int totDayNumber, i;
    if (yyyy < 1600 || yyyy > 2100) return 0;            //Invalid year.
    if (mm < 1 || mm > 12) return 0;                    //Invalid month.
    //februar 28 if
    //not leapyear.
    //29 if leapyear.
    daysPrMonth[1] = (leapyear(yyyy)) ? 29 : 28;
    if (dd < 1 || dd > daysPrMonth[mm - 1]) return 0; // Invalid day:
    totDayNumber = dd;
    for (i = 0; i < mm - 1; i++)                    //Calculates dates day number
        totDayNumber+= daysPrMonth[i];
    return totDayNumber;
}
bool leapyear(int yy) {
    //Leapyear?
    return ((yy % 400 == 0) || ((yy % 4 == 0) && (yy % 100) != 0));
}
void printMenu() {        //Main menu
    cout << "\n\nMAIN MENU - Avalible commands:";
    cout << "\n\tK D - Kunde Display";
    cout << "\n\tK N - Kunde Ny";
    cout << "\n\tK E - Kunde Endre";
    cout << "\n\tK S - Kunde Slette";
    cout << "\n\tS D - Sted Diplay";
    cout << "\n\tS N - Sted Nytt";
    cout << "\n\tO D - Oppsett Display";
    cout << "\n\tO N - Oppsett Nytt";
    cout << "\n\tO E - Oppsett Endre";
    cout << "\n\tA D - Arrangement Display";
    cout << "\n\tA N - Arrangement Nytt";
    cout << "\n\tA S - Arrangement Slett";
    cout << "\n\tA K - Arrangement Kjop";
    cout << "\n\tQ   - Quit / avslutt\n\n";
}

bool checkDigit(const char t[]) {   //Checks if input is only digits
    for (int i = 0; i < strlen(t); i++)
    {
        if (!isdigit(t[i]))
            return false;
    }
    return true;
}
void printEventTypeMenu() {      //Event type menu
	cout << "\n\nTYPE OF EVENT:";
	cout << "\n\t0\tMusic";
	cout << "\n\t1\tSport";
	cout << "\n\t2\tTheater";
	cout << "\n\t3\tShow";
	cout << "\n\t4\tCinema";
	cout << "\n\t5\tFamily";
	cout << "\n\t6\tFestival" << endl;
}
