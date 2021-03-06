#pragma once

#include "include\backend\Node.h"

#include <iostream>

template <typename T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(T node);
	LinkedList(const LinkedList<T>& list);
	~LinkedList();

	Node<T>* getHead() const;
	Node<T>* getTail() const;

	void addAtFront(T node);
	void addAtBack(T node);
	void addAfterNode(T oldNode, T nodeToInsert);
	void removeAtFront();
	void removeAtBack();
	void removeNode(T node);

	Node<T>* findNode(T obj) const;

	void printList() const;
	int size() const;

	/*
	template <typename TT>
	friend std::ostream& operator<<(std::ostream& out, const LinkedList<TT>& list)
	{
		if (list.size() == 0)
		{
			out << "NULL";
			return out;
		}
		
		Node<TT>* curr = list.head;

		while (curr != nullptr)
		{
			out << curr->getData() << ' ';
			curr = curr->getNext();
		}

		out << '\b';

		return out;
	}
	*/

private:
	Node<T>* head;
};

#include "src\backend\LinkedList.tpp"