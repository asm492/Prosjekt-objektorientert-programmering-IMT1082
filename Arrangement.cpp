#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include "functions.h"
#include <iostream>
#include "Arrangement.h"

using namespace std;

bool Arrangement::compareEvent(char query[]) {
    
    return strstr(name, query);
    //return strcmp(name, query);
}
