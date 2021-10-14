#include "StackItem.h"

using namespace std;

class Stack {

public:
	Stack();
	StackItem* pop();
	StackItem* top();
	bool isEmpty();
	~Stack();
	void push(StackItem*);
	StackItem* head;
private:
	
	


};