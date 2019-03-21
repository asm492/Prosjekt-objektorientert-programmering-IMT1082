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
	Arrangementer();
	~Arrangementer();
};




#endif
