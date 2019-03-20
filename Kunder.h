#ifndef Kunder_h
#define Kunder_h

#include "Kunde.h"
#include "ListTool2B.h"

class Kunder {
private:
	List* customersList;
	int lastCustomer;

public:
	Kunder();
	void newCustomer();
	void customersMenu();
};

#endif 
