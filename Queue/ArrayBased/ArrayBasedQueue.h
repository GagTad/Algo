#pragma once
#include "../../LLBased/LLBased/Queue.h"


template <typename T>
class ArrayBasedQueue : public Queue<T> {

public:
	 const T& front() const;
	 const T& rear() const;
	 void enqueue(const T& value);
	 void dequeue();
	 bool empty() const;
	 size_t size() const;
	 ArrayBasedQueue();



private:
	T* arr;
	size_t capacity;
	size_t count;
	size_t frontIndex;
	size_t rearIndex;
	void resize();

};

#include "ArrayBasedQueue.ipp"