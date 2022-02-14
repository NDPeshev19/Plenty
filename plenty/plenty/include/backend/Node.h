#pragma once

#include <iostream>

template <typename T>
class LinkedList;

template <typename T>
class Node
{
	friend class LinkedList<T>;

public:
	Node();
	Node(T node);
	T getData();
	Node<T>* getNext() { return next; }
	Node<T>* getPrev() { return prev; }

	friend std::ostream& operator<<(std::ostream & out, const Node<T>& node)
	{
		out << node.data;
		return out;
	}

private:
	T data;
	Node<T>* next;
	Node<T>* prev;
};

#include "src\backend\Node.tpp"