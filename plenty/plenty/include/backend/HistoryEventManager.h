#pragma once

#include "LinkedList.h"

#include <iostream>
#include <string>

class HistoryEvent
{
public:
	std::string title;
	std::string description;
	std::string date;

	HistoryEvent();
	HistoryEvent(std::string title_t, std::string description_t, std::string date_t);
	HistoryEvent(const HistoryEvent& HE);

	friend std::ostream& operator<<(std::ostream& out, const HistoryEvent& HE)
	{
		std::string spacer(15, '-');

		out << spacer << '\n';
		out << "Title: " << HE.title << '\n';
		out << "Description: " << HE.description << '\n';
		out << "Date: " << HE.date << '\n';
		out << spacer << '\n';

		return out;
	}
	friend bool operator==(const HistoryEvent& lhs, const HistoryEvent& rhs)
	{
		return lhs.title == rhs.title &&
			lhs.description == rhs.description &&
			lhs.date == rhs.date;
	}
};

class HistoryEventManager
{
private:
	struct _HistoryEvent
	{
		int id;
		HistoryEvent event;

		friend std::ostream& operator<<(std::ostream& out, const _HistoryEvent& HE)
		{
			std::string spacer(15, '-');

			out << spacer << '\n';
			out << "Title: " << HE.event.title << '\n';
			out << "Description: " << HE.event.description << '\n';
			out << "Date: " << HE.event.date << '\n';
			out << spacer << '\n';

			return out;
		}
		friend bool operator==(const _HistoryEvent& lhs, const _HistoryEvent& rhs)
		{
			return lhs.event.title == rhs.event.title &&
				lhs.event.description == rhs.event.description &&
				lhs.event.date == rhs.event.date;
		}
	};

private:
	int id = 1;

	LinkedList<_HistoryEvent> events;

private:
	int findId(HistoryEvent HE) const;

public:
	void addEvent(HistoryEvent historyEvent);

	// Returns default HistoryEvent on failure!
	HistoryEvent getEventById(int id);

	void deleteEvent(HistoryEvent historyEvent);
	void displayAllEvents();
};