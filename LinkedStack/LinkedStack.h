#pragma once
#include "Stack.h"
#include "Node.h"

template <typename T>
class LinkedStack : public Stack<T>
{
public:
	LinkedStack() : m_top(nullptr) {}
	LinkedStack(const LinkedStack<T>& st) : m_top(nullptr) { copyFrom(st); }
	LinkedStack(LinkedStack&& st) noexcept;

	LinkedStack& operator=(const LinkedStack& st);
	LinkedStack&  operator=(LinkedStack&& st) noexcept;

	virtual void push(const T&) override;
	virtual void pop() override;
	virtual void clear() override;
	virtual void showReverse() const;
	virtual void show() const;
	virtual const T& top() const override;
	virtual bool empty() const override;

	virtual ~LinkedStack() { clear(); }
private:
	Node<T>* m_top;

	void copyFrom(const LinkedStack<T>& st);
};

#include "LinkedStack.ipp"
