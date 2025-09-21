#pragma once

#include "ArrayBasedStack.h"
#include <iostream>

template<typename T>
ArrayBasedStack<T>::ArrayBasedStack(const ArrayBasedStack& arr)
	: capacity(arr.capacity), topIndex(arr.topIndex)
{
	data = new T[capacity];
	for (size_t i = 0; i < topIndex; ++i)
	{
		data[i] = arr.data[i];
	}
}

template<typename T>
ArrayBasedStack<T>& ArrayBasedStack<T>::operator=(const ArrayBasedStack& arr)
{
	if (this != &arr)
	{
		delete[] data;
		capacity = arr.capacity;
		topIndex = arr.topIndex;
		data = new T[capacity];
		for (size_t i = 0; i < topIndex; ++i)
		{
			data[i] = arr.data[i];
		}
	}
	return *this;
}

template<typename T>
ArrayBasedStack<T>& ArrayBasedStack<T>::operator=(ArrayBasedStack&& arr) noexcept
{
	if (this != &arr)
	{
		delete[] data;
		data = arr.data;
		capacity = arr.capacity;
		topIndex = arr.topIndex;
		arr.data = nullptr;
		arr.capacity = 0;
		arr.topIndex = 0;
	}
	return *this;
}

template<typename T>
ArrayBasedStack<T>::ArrayBasedStack(ArrayBasedStack&& arr) noexcept
	: data(arr.data), capacity(arr.capacity), topIndex(arr.topIndex)
{
	arr.data = nullptr;
	arr.capacity = 0;
	arr.topIndex = 0;
}

template <typename T>
ArrayBasedStack<T>::ArrayBasedStack(size_t capacity)
	: capacity(capacity), topIndex(0)
{
	data = new T[capacity];
}

template <typename T>
ArrayBasedStack<T>::~ArrayBasedStack()
{
	delete[] data;
}

template <typename T>
void ArrayBasedStack<T>::push(const T& item)
{
	if (topIndex == capacity)
	{
		resize();
	}
	data[topIndex++] = item;
}

template <typename T>
void ArrayBasedStack<T>::pop()
{
	if (empty())
	{
		throw std::out_of_range("Stack is empty");
	}
	--topIndex;
}

template <typename T>
void ArrayBasedStack<T>::clear()
{
	topIndex = 0;
}

template <typename T>
const T& ArrayBasedStack<T>::top() const
{
	if (empty())
	{
		throw std::out_of_range("Stack is empty");
	}
	return data[topIndex - 1];
}

template <typename T>
bool ArrayBasedStack<T>::empty() const
{
	return topIndex == 0;
}

template <typename T>
void ArrayBasedStack<T>::show() const
{
	for (size_t i = 0; i < topIndex; ++i)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void ArrayBasedStack<T>::showReverse() const
{
	for (size_t i = topIndex; i > 0; --i)
	{
		std::cout << data[i - 1] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void ArrayBasedStack<T>::resize()
{
	capacity *= 2;
	T* newData = new T[capacity];
	for (size_t i = 0; i < topIndex; ++i)
	{
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}


