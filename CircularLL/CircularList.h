#pragma once

#include "DLList.h"
#include "../../LLBasedDeque/LLBasedDeque/node.h"

template <typename T>
class CircularList : public ICircularList<T> {
public:
	void addFront(const T& value);
	void addBack(const T& value);
	void addAt(const T& value, size_t index) ;
	void removeFront() ;
	void removeBack() ;
	void removeAt(size_t index);
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	bool isEmpty() const;
	size_t size() const;

	CircularList();
	~CircularList() {}

private:
	Node<T>* head;
	size_t listSize;

};
#include "CircularList.ipp"


