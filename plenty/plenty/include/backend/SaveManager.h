#pragma once

#include "LinkedList.h"
#include "HistoryEventManager.h"

#include "lib\csv.hpp"

#include <string>
#include <sstream>
#include <vector>

class SaveManager
{
public:
	static void save(std::string fileName, const LinkedList<HistoryEvent>& events)
	{
		std::stringstream ss;

		auto writer = csv::make_csv_writer(ss);

		auto head = events.getHead();

		while (head != nullptr)
		{
			HistoryEvent event = head->getData();

			writer << std::vector<std::string> {std::to_string(event.getId()), event.title, event.description, event.date};

			head = head->getNext();
		}
		
		std::cout << ss.str();
	}
};