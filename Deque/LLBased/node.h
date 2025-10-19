#pragma once

template <typename T >
struct Node {
	T data;
	Node* next;
	Node* prev;
	Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};
