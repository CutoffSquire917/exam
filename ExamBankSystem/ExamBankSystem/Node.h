#pragma once

template<typename T>
class Node
{
private:
	Node* next;
	Node* prev;
	T value;
public:
	Node(T value) : next(nullptr), prev(nullptr), value(value) {}
	Node<T>* GetNext() {
		return next;
	}
	void SetNext(Node<T>* next) {
		this->next = next;
	}
	Node<T>* GetPrev() {
		return next;
	}
	void SetPrev(Node<T>* prev) {
		this->prev = prev;
	}
	T& GetValue() {
		return value;
	}

	~Node() {
		delete next;
		delete prev;
	}
};

