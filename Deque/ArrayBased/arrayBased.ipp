#pragma once
#include <iostream>
#include "arrayBased.h"

template <typename T>
void ArrayBasedDeque<T>::push_back(const T& value) {
	
	if (m_size == m_capacity)
		resize();

	size_t back_idx = (m_front_idx + m_size) % m_capacity;
	m_arr[back_idx] = value;
	m_size++;


}

template<typename T>
inline void ArrayBasedDeque<T>::pop_back()
{
	if (isEmpty())
		throw std::out_of_range("Deque is empty");
	m_size--;
}

template<typename T>
inline void ArrayBasedDeque<T>::push_front(const T& value)
{
	if(m_size == m_capacity)
		resize();

	m_front_idx = (m_front_idx - 1 + m_size) % m_capacity;
	m_arr[m_front_idx] = value;
	m_size++;


}

template<typename T>
inline void ArrayBasedDeque<T>::pop_front()
{
	if (isEmpty())
		throw std::out_of_range("Deque is empty");

	m_front_idx = (m_front_idx + 1) % m_capacity;
	m_size--;
}

template<typename T>
inline const T& ArrayBasedDeque<T>::front() const
{
	return m_arr[m_front_idx];
}


template<typename T>
inline const T& ArrayBasedDeque<T>::back() const
{
	return m_arr[(m_front_idx + m_size - 1) % m_capacity];
}

template<typename T>
inline T& ArrayBasedDeque<T>::front()
{
	return m_arr[m_front_idx];
}

template<typename T>
inline T& ArrayBasedDeque<T>::back()
{
	return m_arr[(m_front_idx + m_size - 1) % m_capacity];
}

template<typename T>
inline bool ArrayBasedDeque<T>::isEmpty() const
{
	return m_size == 0;
}

template<typename T>
inline size_t ArrayBasedDeque<T>::size() const
{
	return m_size;
}

template<typename T>
 ArrayBasedDeque<T>::ArrayBasedDeque()
{
	 m_capacity = 10;
	 m_size = 0;
	 m_front_idx = 0;
	 m_arr = new T[m_capacity];


}

 template<typename T>
 inline ArrayBasedDeque<T>::~ArrayBasedDeque()
 {
	 delete[] m_arr;
 }

 template<typename T>
 inline void ArrayBasedDeque<T>::resize()
 {

	size_t new_capacity = m_capacity * 2;
	T* new_data = new T[new_capacity];
	size_t back_idx = (m_front_idx + m_size) % m_capacity;

	for (size_t i = 0; i < m_size; ++i) {
		new_data[i] = m_arr[(m_front_idx + i) % m_capacity];
	}

	delete[] m_arr;

	m_arr = new_data;
	m_capacity = new_capacity;
	m_front_idx = 0; 
 }

