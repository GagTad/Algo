#pragma once

#include "LinkedStack.h"
#include <cassert>
#include <vector>


template<typename T>
void LinkedStack<T>::copyFrom(const LinkedStack<T>& st) {
	if (st.m_top == nullptr) {
		m_top = nullptr;
		return;
	}

	m_top = new Node<T>(st.m_top->val);
	Node<T>* current = m_top;
	Node<T>* stCurrent = st.m_top->next;

	while (stCurrent) {
		current->next = new Node<T>(stCurrent->val);
		current = current->next;
		stCurrent = stCurrent->next;
	}
}


template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack<T>&& st) noexcept :m_top(st.m_top)
{
	st.m_top = nullptr;// goxanum enq hascen
}

template<typename T>
LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& st)
{
		if (this != &st)
		{
			clear();
			copyFrom(st);
		}
		return *this;

}

template<typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack<T>&& st) noexcept
{
	if (this != &st)
	{
		clear();
		m_top = st.m_top;
		st.m_top = nullptr;// goxanum enq hascen
	}
	return *this;


}
template <typename T>
bool LinkedStack<T>::empty() const
{
    return m_top == nullptr;
}

template <typename T>
const T& LinkedStack<T>::top() const
{
    assert(m_top != nullptr);
    return m_top->val;
}

template <typename T>
void LinkedStack<T>::pop()
{
    if (empty())
        return;
    Node<T>* temp = m_top;
    m_top = m_top->next;
    delete temp;
}

template <typename T>
void LinkedStack<T>::push(const T& newVal)
{
    m_top = new Node<T>(newVal, m_top);
}

template <typename T>
void LinkedStack<T>::clear()
{
    while (!empty())
        pop();
}

template <typename T>
void LinkedStack<T>::show() const
{
	Node<T>* current = m_top;
	while (current != nullptr)
	{
		std::cout << current->val << " ";
		current = current->next;
	}
}

template <typename T>
void LinkedStack<T>::showReverse() const
{
	std::vector<T> elem;

	Node<T>* current = m_top;
	while (current != nullptr)
	{
		elem.push_back(current->val);
		current = current->next;
	}
	for (int i = elem.size() - 1; i >= 0; --i)
		std::cout << elem[i] << " ";
}
