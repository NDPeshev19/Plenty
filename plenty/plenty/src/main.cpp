#include "include\backend\LinkedList.h"
#include "include\backend\HistoryEventManager.h"

#include "include\backend\SaveManager.h"

#include <iostream>

int main()
{
	HistoryEventManager HEM;
	auto HE = HistoryEvent("Title1", "Desc1", "03.10.2021");

	HEM.addEvent(HE);
	HEM.addEvent(HistoryEvent("Title2", "Desc2", "03.10.2021"));
	HEM.addEvent(HistoryEvent("Title3", "Desc3", "03.10.2021"));
	HEM.addEvent(HistoryEvent("Title4", "Desc4", "03.10.2021"));
	HEM.addEvent(HistoryEvent("Title5", "Desc5", "03.10.2021"));
	

	// HEM.displayAllEvents();

	// std::cout << "\n\n\n\n" << std::endl;

	HEM.deleteEvent(HEM.getEventById(2));
	// HEM.displayAllEvents();

	// std::cout << HEM.getEventById(4);

	// std::cout << "________________________________________" << std::endl;

	LinkedList<HistoryEvent> list = HEM.getAll();

	SaveManager::save("test", list);
	

	// // std::cout << HEM.getAll().getHead()->getData().getId();

	
	// auto all = HEM.getAll();

	// auto head = all.getHead();

	// auto data = head->getData();

	// auto id = data.getId();

	// std::cout << id;

	std::cin.get();
}