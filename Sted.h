
#ifndef Steder_h
#define Steder_h
#include <fstream>
#include "ListTool2B.h"

using namespace std;

class Sted : public TextElement {
private:
    char* name;
    int numberOfLayouts;
public:
    void display();
};
    

#endif 
