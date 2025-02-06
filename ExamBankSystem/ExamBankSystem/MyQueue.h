#pragma once

#include "Node.h"
#include "CreditCard.h"
#include "CostHistory.h"
#include <stdexcept>

template<typename T>
class MyQueue
{
private:
	Node<T>* head;
	Node<T>* last;
	size_t size;
public:
	MyQueue() : head(nullptr), last(nullptr), size(0) {}
	MyQueue(Node<T>* first) : head(first), last(first), size(1) {}
	void AddToEnd(Node<T> newNode) {
		Node<T>* myNewNode = new Node<T>(newNode);
		if (size == 0) {
			head = myNewNode;
			last = myNewNode;
		}
		else {
			Node<T>* temp = last;
			last->SetNext(myNewNode);
			last = myNewNode;
			last->SetPrev(temp);
			last->SetNext(nullptr);
		}
		size++;
	}
	void DeleteByIndex(const size_t index) {
		if (index < 0 || index >= this->size) {
			throw std::out_of_range("Index out of the range");
		}
		else if (index == 0 && this->size == 1) {
			head = nullptr;
			last = nullptr;
			size--;
			return;
		}
		else if (index == this->size - 1) {
			Node<T>* temp = last;
			last = last->GetPrev();
			last->SetNext(nullptr);
			delete temp;
			size--;
			return;
		}
		Node<T>* temp = head;
		for (size_t i = 0; i < index; i++)
		{
			temp = temp->GetNext();
		}
		temp->GetPrev()->SetNext(temp->GetNext());
		temp->GetPrev()->SetPrev(temp->GetPrev());
		delete temp;
		size--;
	}
	T& GetValue(const size_t index) {
		if (index < 0 || index >= size) {
			throw std::runtime_error("index out of the range");
		}
		Node<T>* temp = head;
		for (size_t i = 0; i < index; i++)
		{
			temp = temp->GetNext();
		}
		return temp->GetValue();
	}
	size_t GetSize() {
		return size;
	}
	~MyQueue() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->GetNext();
			delete temp;
		}
		delete last;
	}
};

