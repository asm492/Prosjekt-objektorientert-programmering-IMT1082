//
//  functions.cpp
//  ProsjektFil
//
//  Created by Sindre Hjelle on 18/03/2019.
//  Copyright © 2019 Sindre Hjelle. All rights reserved.
//
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
void printText(char t[]) {
    int n = strlen(t);                        //    Tar i mot en char array
    for (int i = 0; i < n; i++)                //    Gj¯r hele array til uprcase
    {
        t[i] = toupper(t[i]);
    }
    cout << "\n\n\t\t" << t << "\n\n";        //    Hopper 2x linjer og tab
    //    Skriver ut melding i uprcase
    //    Hopper 2x linjer
}
int dayNumber(int dd, int mm, int yyyy) {
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
