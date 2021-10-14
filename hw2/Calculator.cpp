#include <sstream>
#include "Calculator.h"


Calculator::Calculator(string infxString) {
	stack = new Stack();
	infixExpression = infxString;
}

Calculator::~Calculator() {
	delete stack;
}

string Calculator::getPostfix() {
	string token = "";
	istringstream iss(infixExpression);
	iss >> token;
	while (token.compare(";") != 0) {
		StackItem* item = new StackItem(token);
		if (!item -> isOperator) {
			postfixExpression += token + " ";
		}
		else if (item->op == OPERATOR_LEFTPAR) {
			stack->push(new StackItem(token));
		}
		else if (item->op == OPERATOR_RIGHTPAR) {
			while (stack->top()->op != OPERATOR_LEFTPAR) {
				postfixExpression += stack->pop()->toString() + " ";
			}	
			stack->pop();
		}
		// operator
		else {
			while (!stack->isEmpty() && hasHigherPrecedence(item, stack->top()) && !stack->top()->op == OPERATOR_LEFTPAR) {
				postfixExpression += (stack->pop()->toString()) + " ";
			}
			stack->push(new StackItem(token));
		}
		iss >> token;
	}
	while (!stack->isEmpty()) {
		postfixExpression += (stack->pop()->toString()) + " ";
	}
	postfixExpression += ";";
	return postfixExpression;
}

bool Calculator::hasHigherPrecedence(StackItem *item,StackItem* top) {
	return top->op >= item->op;
}

int Calculator::calculate() {
	string token = "";
	istringstream iss(postfixExpression);
	iss >> token;
	while (token.compare(";") != 0) {
		StackItem* item = new StackItem(token);
		if (!item->isOperator) {
			stack->push(item);
		}
		else {
			int num1 = stack->pop()->n;
			int num2 = stack->pop()->n;

			int result = 0;
			if (item->op == OPERATOR_PLUS) {
				result = num1 + num2;
			} else if (item->op == OPERATOR_MINUS) {
				result = num2 - num1;
			} else if (item->op == OPERATOR_DIVISION) {
				result = num2 / num1;
			} else if (item->op == OPERATOR_MULTIPLICATION) {
				result = num1 * num2;
			}
			stack->push(new StackItem(false, result));
		}
		iss >> token;
	}
	return stack->pop()->n;
}