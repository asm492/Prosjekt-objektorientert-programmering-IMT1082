#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <iostream>
#include "Steder.h"
#include "functions.h"

void Steder::customerMenu(){
    
    char command = read();
    
    switch (command) {
        case 'D':          break;
        case 'N':          break;
        default: printError("INPUT NOT VALID! GOING BACK TO MAIN MENU");
            break;
    }
}



Steder::Steder(){
venueList = new List(Sorted);
}
