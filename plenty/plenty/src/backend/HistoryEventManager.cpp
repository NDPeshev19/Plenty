#include "include\backend\HistoryEventManager.h"

HistoryEvent::HistoryEvent()
	: title("undefined"),
	description("undefined"),
	date("undefined"),
	id(0)
{

}

HistoryEvent::HistoryEvent(std::string title_t, std::string description_t, std::string date_t)
	: title(title_t),
	description(description_t),
	date(date_t),
	id(idCount++)
{

}


HistoryEvent::HistoryEvent(const HistoryEvent& HE)
	: title(HE.title),
	description(HE.description),
	date(HE.date),
	id(HE.id)
{

}

int HistoryEvent::getId()
{
	return id;
}


int HistoryEventManager::findId(HistoryEvent historyEvent) const
{
	auto hEvent = events.findNode(historyEvent);

	return hEvent ? hEvent->getData().getId() : -1;
}

void HistoryEventManager::addEvent(HistoryEvent historyEvent)
{
	events.addAtBack(historyEvent);
}

HistoryEvent HistoryEventManager::getEventById(int id)
{
	auto head = events.getHead();

	while (head != nullptr)
	{
		if (head->getData().getId() == id)
		{
			return head->getData();
		}

		head = head->getNext();
	}

	return {};
}

void HistoryEventManager::deleteEvent(HistoryEvent historyEvent)
{
	if (findId(historyEvent))
	{
		events.removeNode(historyEvent);
	}
}

void HistoryEventManager::displayAllEvents() const
{
	events.printList();
}

LinkedList<HistoryEvent> HistoryEventManager::getAll() const
{
	return events;
}
