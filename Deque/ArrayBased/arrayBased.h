#pragma once
#include "deque.h"


template <typename T>
class ArrayBasedDeque : public IDeque<T> {

public:

	 void push_back(const T&);
	 void pop_back();
	 void push_front(const T&);
	 void pop_front();
	 const T& front() const;
	 const T& back() const;
	 T& front() ;
	 T& back() ;
	 bool isEmpty() const;
	 size_t size() const;

	ArrayBasedDeque();

	~ArrayBasedDeque();

private:
	void resize();

private:
	T* m_arr;
	size_t m_capacity;
	size_t m_size;
	size_t m_front_idx;
	//size_t back_idx;

};

#include "arrayBased.ipp"

