#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 


#include "functions.h"
#include <iostream>
#include "Arrangement.h"
#include "Sted.h"
using namespace std;

Arrangement::Arrangement() {
    
}
void Arrangement::display() {
    cout << "\nEvent Name: " << name << endl;
    sted->displayName();
    cout << "\nArtist:  " << artist << endl;
    cout << "Event type: " << getTypeName(eventType) << endl; //Diplayer enum type
     //Magler tidspunk
    
}





bool Arrangement::compareEvent(char query[]) {
    
    return strstr(name, query);
    //return strcmp(name, query);
}
