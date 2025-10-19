#pragma once

#include "llBased.h"

template<typename T>
inline LLBasedDeque<T>::LLBasedDeque()
{
	head = nullptr;
	tail = nullptr;
	count = 0;
}


template<typename T>
inline void LLBasedDeque<T>::push_back(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
	++count;
}

template<typename T>
inline void LLBasedDeque<T>::pop_back()
{
	if (isEmpty()) {
		throw std::out_of_range("Deque is empty");
	}
	Node<T>* temp = tail;
	tail = tail->prev;
	if (tail) {
		tail->next = nullptr;
	}
	else {
		head = nullptr;
	}
	delete temp;
	--count;
}

template<typename T>
inline void LLBasedDeque<T>::push_front(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	if (isEmpty()) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	++count;
}

template<typename T>
inline void LLBasedDeque<T>::pop_front()
{
	if (isEmpty()) {
		throw std::out_of_range("Deque is empty");
	}
	Node<T>* temp = head;
	head = head->next;
	if (head) {
		head->prev = nullptr;
	}
	else {
		tail = nullptr;
	}
	delete temp;
	--count;
}

template<typename T>
inline const T& LLBasedDeque<T>::front() const
{
	if (isEmpty()) {
		throw std::out_of_range("Deque is empty");
	}
	return head->data;
}

template<typename T>
inline const T& LLBasedDeque<T>::back() const
{
	if (isEmpty()) {
		throw std::out_of_range("Deque is empty");
	}
	return tail->data;
}

template<typename T>
inline T& LLBasedDeque<T>::front()
{
	if (isEmpty()) {
		throw std::out_of_range("Deque is empty");
	}
	return head->data;
}

template<typename T>
inline T& LLBasedDeque<T>::back()
{
	if (isEmpty()) {
		throw std::out_of_range("Deque is empty");
	}
	return tail->data;
}

template<typename T>
inline bool LLBasedDeque<T>::isEmpty() const
{
	return count == 0;
}

template<typename T>
inline size_t LLBasedDeque<T>::size() const
{
	return count;
}

template<typename T>
inline LLBasedDeque<T>::~LLBasedDeque()
{
	while (!isEmpty()) {
		pop_front();
	}
}

