// ArrayBasedQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ArrayBasedQueue.h"

int main()
{
	ArrayBasedQueue<int> queue;
	queue.enqueue(1);
	queue.enqueue(2);
	queue.enqueue(3);
	std::cout << "Front: " << queue.front() << std::endl; 
	std::cout << "Rear: " << queue.rear() << std::endl;   
	queue.dequeue();
	std::cout << "Front after dequeue: " << queue.front() << std::endl; 
	std::cout << "Size: " << queue.size() << std::endl; 
	return 0;
}