#ifndef Kunder_h
#define Kunder_h

#include "Kunde.h"
#include "ListTool2B.h"
#include <fstream>

class Kunder {
private:
    List* customersList;            //    KundeR
    int lastCustomer;
    
public:
    Kunder();
    
    void editCustomer();
    void deleteCustomer();
    void newCustomer();
    void customersMenu();
    void display();
    void writeCustomersToFile();
    void readCustomersFromFile();
    
	bool customerExists(int nr);

    int customerNameSearch(char name[]);
	int returnLastCustomer();
};

#endif 
