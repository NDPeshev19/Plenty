#include "include/backend/HistoryEventManager.h"

HistoryEvent::HistoryEvent()
	: title("undefined"),
	description("undefined"),
	date("undefined")
{

}

HistoryEvent::HistoryEvent(std::string title_t, std::string description_t, std::string date_t)
	: title(title_t),
	description(description_t),
	date(date_t)
{

}


HistoryEvent::HistoryEvent(const HistoryEvent& HE)
	: title(HE.title),
	description(HE.description),
	date(HE.date)
{

}

int HistoryEventManager::findId(HistoryEvent historyEvent) const
{
	auto hEvent = events.findNode({ 0, historyEvent });

	return hEvent ? hEvent->getData().id : -1;
}

void HistoryEventManager::addEvent(HistoryEvent historyEvent)
{
	events.addAtBack({id++, historyEvent });
}

HistoryEvent HistoryEventManager::getEventById(int id)
{
	auto head = events.getHead();

	while (head != nullptr)
	{
		if (head->getData().id == id)
		{
			return head->getData().event;
		}

		head = head->getNext();
	}

	return {};
}

void HistoryEventManager::deleteEvent(HistoryEvent historyEvent)
{
	int id = findId(historyEvent);
	
	if (id)
	{
		events.removeNode({ id, historyEvent });
	}
}

void HistoryEventManager::displayAllEvents()
{
	events.printList();
}