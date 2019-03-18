//
//  functions.h
//  ProsjektFil
//
//  Created by Sindre Hjelle on 18/03/2019.
//  Copyright © 2019 Sindre Hjelle. All rights reserved.
//

#ifndef functions_h
#define functions_h
#include "conster.h"

void read(const char t[], char s[], const int LEN);
char read();
void printError(char t[])
int  read(const char t[], const int min, const int max);
void printMenu();
int dayNumber(int dd, int mm, int yyyy);
bool leapyear(int yy);
#endif /* functions_h */
