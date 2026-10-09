#pragma once
template<class T>
class Node
{

public:
	T value;
	Node* next;
	Node(const T& val) : value(val), next(nullptr) {};
};