#pragma once
#include <iostream>
#define MAXX 25
class Stack {
	int empty = -1, full = MAXX;
	int top;
	char* arr;
public:
	Stack();
	void push(char c);
	char pop();
	void clear();
	bool isEmpty();
	bool isFull();
	int getCount();
	void show();
	int& clon(Stack const& cSt);
	int& operator+(Stack const& anSt);
	int& operator*(Stack const& anSt);
};
Stack::Stack() {
	arr = new char[full + 1];
	top = empty;
}
void Stack::push(char c) {
	if (isFull())
		full++;
	arr[++top] = c;
}
char Stack::pop() {
	if (!isEmpty()) {
		return arr[top - 1];
		if (full > MAXX)
			full--;
	}
	else
		return 0;
}
void Stack::clear() {
	top = empty;
	full = MAXX;
}
bool Stack::isEmpty() {
	return top == empty;
}
bool Stack::isFull() {
	return top == full;
}
int Stack::getCount() {
	return top + 1;
}
void Stack::show() {
	for (int i = 0; i <= top; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}
int& Stack::clon(Stack const& clSt) {
	if (!isEmpty())
		clear();
	for (int i = 0; i <= clSt.top; i++)
		push(clSt.arr[i]);
	return top;
}
int& Stack::operator+(Stack const& anSt) {
	for (int i = 0; i <= anSt.top; i++) 
		push(anSt.arr[i]);
	return top;
}
int& Stack::operator*(Stack const& anSt) {
	Stack nS;
	for (int i = 0; i < anSt.top; i++) 
		for (int j = 0; j < top; j++) 
			if (arr[j] == anSt.arr[i]) {
				if (!strchr(nS.arr, anSt.arr[i]))
					nS.push(arr[j]);
				else
					continue;
			}
	clear();
	clon(nS);
	return top;
}