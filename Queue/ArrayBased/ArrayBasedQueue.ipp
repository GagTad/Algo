#pragma once

#include <iostream>
#include "ArrayBasedQueue.h"

template <typename T>
const T& ArrayBasedQueue<T>::front() const {

	return arr[frontIndex];

}

template <typename T>
const T& ArrayBasedQueue<T>::rear() const {
	return arr[(rearIndex + capacity - 1) % capacity];
}

template <typename T>
void ArrayBasedQueue<T>::enqueue(const T& value) {
	if (count == capacity) {
		resize();
	}	
	arr[rearIndex] = value;
	rearIndex = (rearIndex + 1) % capacity; 

	count++;
}	

template <typename T>
void ArrayBasedQueue<T>::dequeue() {
	if (empty()) {
		std::cout << "Queue is empty. Cannot dequeue." << std::endl;
		return;
	}
	frontIndex = (frontIndex + 1) % capacity;
	count--;
}

template <typename T>
bool ArrayBasedQueue<T>::empty() const {
	return count == 0;
}

template <typename T>
size_t ArrayBasedQueue<T>::size() const {
	return count;
}

template <typename T>
void ArrayBasedQueue<T>::resize() {
	size_t newCapacity = capacity * 2;
	T* newArr = new T[newCapacity];
	for (size_t i = 0; i < count; i++) {
		newArr[i] = arr[(frontIndex + i) % capacity];
	}
	delete[] arr;
	arr = newArr;
	capacity = newCapacity;
	frontIndex = 0;
	rearIndex = count;
}


template <typename T>
ArrayBasedQueue<T>::ArrayBasedQueue() { 
	capacity = 10;

	arr = new T[capacity];

	count = 0;
	frontIndex = 0;
	rearIndex = 0;
}
