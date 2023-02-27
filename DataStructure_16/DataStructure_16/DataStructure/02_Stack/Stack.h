#pragma once

#define MAX_SIZE 100

void DoStack();

class Stack {
public:
	Stack();
	bool IsEmpty();
	bool IsFull();
	void Push(DataType data);
	int Pop();
	int Peek();

private:
	int Top;
	DataType Data[MAX_SIZE];
};