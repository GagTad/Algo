// ConsoleApplication3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LLBasedQueue.h"


int main()
{
	LLBasedQueue<int> queue;
	queue.enqueue(10);
	queue.enqueue(20);
	queue.enqueue(30);
	std::cout << "Front: " << queue.front() << std::endl; 
	std::cout << "Rear: " << queue.rear() << std::endl;   
	queue.dequeue();
	std::cout << "Front after dequeue: " << queue.front() << std::endl;
	std::cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << std::endl; 
	std::cout << "Queue size: " << queue.size() << std::endl; 

	return 0;

}

