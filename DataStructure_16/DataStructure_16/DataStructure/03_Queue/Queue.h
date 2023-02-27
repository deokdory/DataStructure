#pragma once

#define MAX_SIZE 100

void DoQueue();

// 환형큐 ( 도넛 모양과 같은 원리 )
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