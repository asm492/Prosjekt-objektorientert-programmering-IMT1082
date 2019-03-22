#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include "functions.h"
#include <iostream>
#include "Arrangement.h"

using namespace std;

void arrangement::searchChoice(){
    char command;
    command = read("Command: ", 1, 7);
    
    switch (command) {
        case 1:                   break;
        case 2:                   break;
        case 3:                   break;
        case 4:                   break;
        case 5:                   break;
        case 6:                   break;
        case 7:                   break;
        default:
            break;
    }
}

void arrangement::printMenu(){
    cout << "\n\nEVENT MENU - Avalible commands:";
    cout << "\n\t(1). - Print all the events";
    cout << "\n\t(2) - Search for an event";
    cout << "\n\t(3) - Search for event's on a certain venue";
    cout << "\n\t(4) - Search for events on a certain date";
    cout << "\n\t(5) - Search for event type";
    cout << "\n\t(6) - Search for artist";
    cout << "\n\t(7) - Print all data of a certain event";
   
}
