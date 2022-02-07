#include "include\backend\LinkedList.h"
#include "include\backend\HistoryEventManager.h"

#include <iostream>

int main()
{
	HistoryEventManager HEM;

	HEM.addEvent(HistoryEvent("Title1", "Desc1", "03.10.2021"));
	HEM.addEvent(HistoryEvent("Title2", "Desc2", "03.10.2021"));
	HEM.addEvent(HistoryEvent("Title3", "Desc3", "03.10.2021"));

	HEM.displayAllEvents();

	std::cout << "\n\n\n\n" << std::endl;

	HEM.deleteEvent(HEM.getEventById(2));
	HEM.displayAllEvents();

	std::cout << HEM.getEventById(4);

	std::cin.get();
}