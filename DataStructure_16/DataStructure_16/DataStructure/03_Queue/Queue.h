#pragma once

#define MAX_SIZE 100

void DoQueue();

// ȯ��ť ( ���� ���� ���� ���� )
class Queue {
public:
	Queue();

	bool IsEmpty();
	bool IsFull();

	int GetSize();

	void EnQueue(DataType data);
	void DeQueue();

	DataType GetFront();

private:
	int Front;
	int Rear;
	int Size;
	DataType Data[MAX_SIZE];
};