#include "include\backend\LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() 
	: head(nullptr)
{

}

template <typename T>
LinkedList<T>::LinkedList(T node)
	: head(node)
{

}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list)
{
	auto head = list.getHead();

	while (head != nullptr)
	{
		addAtBack(head->getData());

		head = head->getNext();
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	Node<T>* node = head;
	Node<T>* tempNode;

	while (node != nullptr)
	{
		tempNode = node;
		node = node->next;
		delete tempNode;
	}
}

template <typename T>
Node<T>* LinkedList<T>::getHead() const
{
	return head;
}

template <typename T>
Node<T>* LinkedList<T>::getTail() const
{
	Node<T>* tail = head;
	while (tail->next != nullptr)
		tail = tail->next;

	return tail;
}

template <typename T>
void LinkedList<T>::addAtFront(T node)
{
	Node<T>* newNode = new Node<T>(node);

	if (head == nullptr)
	{
		head = newNode;
		return;
	}

	newNode->next = head;
	head->prev = newNode;
	head = newNode;
}

template <typename T>
void LinkedList<T>::addAtBack(T node)
{
	Node<T>* newTail = new Node<T>(node);

	if (head == nullptr)
	{
		head = newTail;
		return;
	}

	Node<T>* oldTail = head;
	while (oldTail->next != nullptr)
	{
		oldTail = oldTail->next;
	}

	oldTail->next = newTail;
	newTail->prev = oldTail;
}

template <typename T>
void LinkedList<T>::addAfterNode(T oldNode, T nodeToInsert)
{
	if (head == nullptr)
		return;

	Node<T>* beforeNode = head;
	while (beforeNode != nullptr)
	{
		if (beforeNode->data == oldNode)
			break;

		beforeNode = beforeNode->next;
	}

	if (beforeNode)
	{
		Node<T>* newNode = new Node<T>(nodeToInsert);
		Node<T>* afterNode = beforeNode->next;

		beforeNode->next = newNode;
		newNode->prev = beforeNode;

		newNode->next = afterNode;
		afterNode->prev = newNode;
	}
}

template <typename T>
void LinkedList<T>::removeAtFront()
{
	Node<T>* tempHead = head;
	if (head->next)
	{
		head = head->next;
		head->prev = nullptr;
	}
	else
	{
		head = nullptr;
	}

	delete tempHead;
}

template <typename T>
void LinkedList<T>::removeAtBack()
{
	Node<T>* tail = getTail();
	if (tail->prev)
		tail->prev->next = nullptr;
	else
		head = nullptr;

	delete tail;
}

template <typename T>
void LinkedList<T>::removeNode(T node)
{
	Node<T>* curr = head;
	while (curr != nullptr)
	{
		if (curr->data == node)
			break;

		curr = curr->next;
	}

	if (!curr)
		return;

	Node<T>* prevNode = curr->prev;
	Node<T>* nextNode = curr->next;

	delete curr;
	if (prevNode) prevNode->next = nextNode;
	else head = nextNode;
	if (nextNode) nextNode->prev = prevNode;
}

template <typename T>
Node<T>* LinkedList<T>::findNode(T obj) const
{
	Node<T>* curr = head;

	while (curr != nullptr)
	{
		if (curr->data == obj)
			return curr;

		curr = curr->next;
	}

	return nullptr;
}

template <typename T>
void LinkedList<T>::printList() const
{
	Node<T>* temp = head;

	while (temp != nullptr)
	{
		std::cout << temp->data;// << ' ';
		temp = temp->next;
	}
}

template <typename T>
int LinkedList<T>::size() const
{
	unsigned nodeCount = 0;
	Node<T>* temp = head;
	while (temp != nullptr)
	{
		temp = temp->next;
		nodeCount++;
	}

	return nodeCount;
}
