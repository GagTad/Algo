#pragma once

#include "../../Deque/Deque/deque.h"
#include "node.h"


template <typename T>
class LLBasedDeque : public IDeque<T> {
public:
	void push_back(const T&);
	void pop_back();
	void push_front(const T&);
	void pop_front();
	const T& front() const;
	const T& back() const;
	T& front();
	T& back();
	bool isEmpty() const;
	size_t size() const;

	LLBasedDeque();
	~LLBasedDeque();

private:

	Node<T>* head;
	Node<T>* tail;
	size_t count;

};

#include "llBased.ipp"


