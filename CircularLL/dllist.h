#pragma once

template <typename T>
class ICircularList {
public:
	virtual void addFront(const T& value) = 0;
	virtual void addBack(const T& value) = 0;
	virtual void addAt(const T& value, size_t index) = 0;
	virtual void removeFront() = 0;
	virtual void removeBack() = 0;
	virtual void removeAt(size_t index) = 0;
	virtual T& front() = 0;
	virtual const T& front() const = 0;
	virtual T& back() = 0;
	virtual const T& back() const = 0;
	virtual bool isEmpty() const = 0;
	virtual size_t size() const = 0;
	virtual ~ICircularList() {}


};
