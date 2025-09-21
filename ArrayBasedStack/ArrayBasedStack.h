#pragma once
#include "Stack.h"

template <typename T>
class ArrayBasedStack : public Stack<T>
{
public:
	ArrayBasedStack(size_t capacity = 10);
	ArrayBasedStack(const ArrayBasedStack& arr);
	ArrayBasedStack& operator=(const ArrayBasedStack& arr);
	ArrayBasedStack& operator=(ArrayBasedStack&& arr) noexcept;
	ArrayBasedStack(ArrayBasedStack&& arr) noexcept;
	void push(const T& item) override;
	void pop() override;
	void clear() override;
	const T& top() const override;
	bool empty() const override;
	void show() const override;
	void showReverse() const override;
	~ArrayBasedStack();

private:
	T* data;
	size_t capacity;
	size_t topIndex;
	void resize();
};
#include "ArrayBasedStack.ipp"
