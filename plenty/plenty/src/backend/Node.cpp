#include "include\backend\Node.h"

template <typename T>
Node<T>::Node()
{
	data = next = prev = nullptr;
}

template <typename T>
Node<T>::Node(T node)
{
	data = node;
	next = prev = nullptr;
}

template <typename T>
T Node<T>::getData()
{
	return data;
}
