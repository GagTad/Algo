#pragma once

template <typename T>
class Queue
{
	public:
		virtual const T&  front() const = 0;
		virtual const T&  rear() const = 0;
		virtual void enqueue(const T& value) = 0;
		virtual void dequeue() = 0;
		virtual bool empty() const = 0;
		virtual size_t size() const = 0;

		virtual ~Queue() {};
};

