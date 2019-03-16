#include "DoublyLinkedList.hpp"
#include <iostream>
#include <string>

using namespace std;

DoublyLinkedList::Node::Node(DataType data) {
	next = nullptr;
	prev = nullptr;
	value = data;

}

DoublyLinkedList::DoublyLinkedList() {
	head_ = nullptr;
	tail_ = nullptr;
	size_ = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
	Node* curr = 0;
	if (curr != nullptr) {
		while (curr->next != nullptr) {
			curr = curr->next;
			delete curr->prev;
			curr->prev = nullptr;
		}

		if (curr != nullptr) {
			delete curr;
			curr = nullptr;
		}
	}
}

bool DoublyLinkedList::empty() const {
	return (size_ == 0);
}

unsigned int DoublyLinkedList::size() const {
	return size_;
}

unsigned int DoublyLinkedList::capacity() const {
	return CAPACITY;
}

void DoublyLinkedList::print() const {
	Node* curr = head_;
	for (unsigned i = 0; i < size_; i++) {
		cout << curr->value << "->";
		curr = curr->next;
	}
}

bool DoublyLinkedList::insert_front(DataType value) {
	if (size_ == CAPACITY)
		return false;
	if (head_ == nullptr) {
		head_ = new Node(value);
		tail_ = head_;
		size_++;
		return true;
	} else {
		Node* newNode = new Node(value);
		head_->prev = newNode;
		newNode->next = head_;
		head_ = newNode;
		size_++;
		return true;
	}
}

bool DoublyLinkedList::remove_front() {
	return remove(0);
}

bool DoublyLinkedList::insert_back(DataType value) {
	if (size_ == CAPACITY)
		return false;
	if (tail_ == nullptr) {
		head_ = new Node(value);
		tail_ = head_;
		size_++;
		return true;
	} else {
		Node* newNode = new Node(value);
		newNode->prev = tail_;
		tail_->next = newNode;
		tail_ = newNode;
		size_++;
		return true;
	}
}

bool DoublyLinkedList::remove_back() {
	return remove(size_);
}

bool DoublyLinkedList::insert(DataType value, unsigned int index) {
	if (size_ == CAPACITY)
		return false;
	else if (index > size_ || index < 0)
		return false;
	else if (size_ - 1 < index) {
		size_++;
		Node* newNode = new Node(value);
		Node* curr = head_;
		for (unsigned i = 0; i < index; i++)
			curr = curr->next;
		curr->next->prev = newNode;
		curr->prev->next = newNode;
		newNode->next = curr->next;
		newNode->prev = curr->prev;
		return true;
	} else
		return insert_back(value);
}

bool DoublyLinkedList::remove(unsigned int index) {
	if (index < 0 || index > size_ || size_ == 0)
		return false;
	else {
		Node* curr = head_;
		Node* old = head_;

		if (size_ == 1) {
			delete head_;
			head_ = tail_ = nullptr;
		}

		else if (index == 0) {
			head_ = head_->next;
			head_->prev = nullptr;
			delete old;
		}

		else if (index == size_ - 1) {
			old = tail_;
			tail_ = tail_->prev;
			tail_->next = nullptr;
			delete old;
		}

		else {
			for (unsigned i = 0; i < index; i++) {
				curr = curr->next;
			}

			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			delete curr;
		}
		size_--;
		return true;
	}
}

unsigned int DoublyLinkedList::search(DataType value) const {
	if (head_ == nullptr)
		return size_;
	else {
		Node* curr = head_;
		unsigned i = 0;
		while (curr->next != nullptr) {
			if (curr->value == value) {
				return i;
			}
			curr = curr->next;
			i++;
		}
		return size_;
	}
}

DoublyLinkedList::DataType DoublyLinkedList::select(unsigned int index) const {
	Node* curr = head_;
	if (index < 0 || index > size_)
		return tail_->value;

	else {
		for (unsigned i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr->value;
	}
}

bool DoublyLinkedList::replace(unsigned int index, DataType value) {
	remove(index);
	insert(value, index);
	return true;

}

DoublyLinkedList::Node* DoublyLinkedList::getNode(unsigned int index) const {
	Node* curr = head_;
	if (index > size_)
		return nullptr;
	else {
		for (unsigned i = 0; i < index; i++) {
			curr = curr->next;
		}
		return curr;
	}
}
bool DoublyLinkedList::full() const {
	return (size_ == CAPACITY);
}
