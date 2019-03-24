#ifndef Arrangementer_h
#define Arrangementer_h

#include "ListTool2B.h"

class Arrangementer
{
private:
	int lastEvent;
	List* eventList;

public:
	void eventsMenu();
    void searchChoice();
    void eventSearch();
    void searchMenu();
	Arrangementer();
	~Arrangementer();
};




#endif
