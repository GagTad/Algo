#pragma once

#include "Node.h"
#include "Queue.h"

template <typename T>
class LLBasedQueue : public Queue<T>
{
public:

	const T& front() const;
	const T& rear() const;
	void enqueue(const T& value);
	void dequeue();
	bool empty() const;
	size_t size() const;

	
	private:
		Node<T>*head = nullptr;
		Node<T>* tail = nullptr;
		size_t count = 0;

	};

#include "LLBasedQueue.ipp"