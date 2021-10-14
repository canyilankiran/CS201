#include "Stack.h"

Stack::Stack() {
	this->head = 0;
}
bool Stack::isEmpty() {
	return head == 0;
}

void Stack::push(StackItem* item) {
	item->next = head;
	head = item;
}

StackItem* Stack::top() {
	return head;
}

StackItem* Stack::pop() {
	StackItem* temp = head;
	head = head->next;
	return temp;

}
Stack::~Stack() {
	if (!isEmpty()) {
		delete head;
		head = 0;
			
	}
}


