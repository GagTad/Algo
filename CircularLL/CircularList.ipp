#pragma once

#include "CircularList.h"


template<typename T>
inline bool CircularList<T>::isEmpty() const
{
	return listSize == 0;
}

template<typename T>
inline size_t CircularList<T>::size() const
{
	return listSize;
}

template<typename T>
inline CircularList<T>::CircularList() {
	head = nullptr;
	listSize = 0;
}

	
template <typename T>
void CircularList<T>::addFront(const T& value) {

	if (isEmpty())
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = newNode;
		newNode->prev = newNode;
		head = newNode;

	}
	else {

		Node<T>* newNode = new Node<T>(value);
		Node<T>* tail = head->prev;
		newNode->next = head;
		newNode->prev = tail;
		tail->next = newNode;
		head->prev = newNode;
		head = newNode;
	}
	
	listSize++;
}

template<typename T>
inline void CircularList<T>::addBack(const T& value)
{
	if (isEmpty())
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = newNode;
		newNode->prev = newNode;
		head = newNode;
	}
	else {
		Node<T>* newNode = new Node<T>(value);
		Node<T>* tail = head->prev;
		newNode->next = head;
		newNode->prev = tail;
		tail->next = newNode;
		head->prev = newNode;
	}
	listSize++;
}

template<typename T>
inline void CircularList<T>::addAt(const T& value, size_t index)
{
	if (index >= listSize)
	{
		throw std::out_of_range("Index out of range");
	}
	if (index - 1 == listSize)
	{
		addBack(value);
		return;
	}
	if (index == 0)
	{
		addFront(value);
		return;
	}
	Node<T>* current = head; 
	while (index > 0)
	{
		current = current->next;
		index--;

	}
	Node<T>* newNode = new Node<T>(value);
	newNode->next = current;
	newNode->prev = current->prev;
	current->prev->next = newNode;
	current->prev = newNode;
	listSize++;

}

template<typename T>
inline void CircularList<T>::removeFront()
{
	if (isEmpty())
	{
		throw std::out_of_range("List is empty");
	}
	Node<T>* tail = head->prev;
	Node<T>* temp = head;
	if (listSize == 1)
	{
		head = nullptr;
	}
	else
	{
		head = head->next;
		tail->next = head;
		head->prev = tail;
	}
	delete temp;
	listSize--;
}

template<typename T>
inline void CircularList<T>::removeBack()
{
	if (isEmpty())
	{
		throw std::out_of_range("List is empty");
	}
	Node<T>* tail = head->prev;
	if (listSize == 1)
	{
		head = nullptr;
	}
	else
	{
		Node<T>* newTail = tail->prev;
		newTail->next = head;
		head->prev = newTail;
	}
	delete tail;
	listSize--;
}

template<typename T>
inline void CircularList<T>::removeAt(size_t index)
{
	if (isEmpty())
	{
		throw std::out_of_range("List is empty");
	}
	if (index >= listSize)
	{
		throw std::out_of_range("Index out of range");
	}
	if (index == 0)
	{
		removeFront();
		return;
	}
	if (index == listSize - 1)
	{
		removeBack();
		return;
	}
	Node<T>* current = head;
	while (index > 0)
	{
		current = current->next;
		index--;
	}
	current->prev->next = current->next;
	current->next->prev = current->prev;
	delete current;
	listSize--;
}

template<typename T>
inline T& CircularList<T>::front()
{
	if (isEmpty())
	{
		throw std::out_of_range("List is empty");
	}
	return head->data;
}

template<typename T>
inline const T& CircularList<T>::front() const
{
	if (isEmpty())
	{
		throw std::out_of_range("List is empty");
	}
	return head->data;
}

template<typename T>
inline T& CircularList<T>::back()
{
	if (isEmpty())
	{
		throw std::out_of_range("List is empty");
	}
	return head->prev->data;
}

template<typename T>
inline const T& CircularList<T>::back() const
{
	if (isEmpty())
	{
		throw std::out_of_range("List is empty");
	}
	return head->prev->data;
}




