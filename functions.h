#ifndef functions_h
#define functions_h


//Sort by type:

char read();

int  read(const char t[], const int min, const int max);
int dayNumber(int dd, int mm, int yyyy);

bool leapyear(int yy);
bool checkDigit(const char t[]);


void venueMenu();            // Skal fjernes n�r vi lager Steder
void layoutMenu();            //
void read(const char t[], char s[], const int LEN);
void printError(const char t[]);
void printMenu();

#endif 
