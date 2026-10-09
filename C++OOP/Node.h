#pragma once
template<class T, class TPri = int>
class Node
{

public:
	T value;
	Node* next;
	TPri priority;
	Node(const T& val) : value(val), next(nullptr) {};
	Node(const T& val, TPri pri) : value(val), priority(pri), next(nullptr) {};
};