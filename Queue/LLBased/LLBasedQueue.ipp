#include <iostream>
#include "LLBasedQueue.h"
#include "Node.h"



template<typename T>
 const T& LLBasedQueue<T>::front() const
{
	return head->data;
}

template<typename T>
 const T& LLBasedQueue<T>::rear() const
{
	return tail->data;
}

template<typename T>
 void LLBasedQueue<T>::enqueue(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	if (empty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}

template<typename T>
 void LLBasedQueue<T>::dequeue()
{
	if (empty())
	{
		std::cout << "Queue is empty" << std::endl;
		return;
	}
	else if (count == 1)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
}

template<typename T>
 bool LLBasedQueue<T>::empty() const
{
	return count == 0;
}

template<typename T>
 size_t LLBasedQueue<T>::size() const
{
	return count;
}

