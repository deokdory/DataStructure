#include "pch.h"
#include "Queue.h"


void DoQueue() {

	Queue q;
	q.EnQueue(232);
	q.EnQueue(13542);
	q.EnQueue(646842);

	std::cout << "Queue Size : " << q.GetSize() << std::endl;
	
	std::cout << "Front element : " << q.GetFront() << std::endl;
	q.DeQueue();

	std::cout << "Front element : " << q.GetFront() << std::endl;
	q.DeQueue();

	std::cout << "Front element : " << q.GetFront() << std::endl;
	q.DeQueue();

	std::cout << "Queue Size : " << q.GetSize() << std::endl;

	q.DeQueue();

	Pause;
	return;
}

Queue::Queue() : Front(0), Rear(0), Size(0) {}

bool Queue::IsEmpty()
{
	return Size == 0;
}

bool Queue::IsFull()
{
	return Size == MAX_SIZE;
}

int Queue::GetSize()
{
	return Size;
}

// 삽입
void Queue::EnQueue(DataType data)
{
	if (IsFull()) {
		std::cout << "Queue is Full" << std::endl;
		return;
	}

	Data[Rear] = data;
	Rear = (Rear + 1) % MAX_SIZE; // 인덱스 끝까지 닿으면 다시 0부터 채워넣을 수 있도록
	Size++;
}

void Queue::DeQueue()
{
	if(IsEmpty()) {
		std::cout << "Queue is Empty" << std::endl;
		return;
	}

	Front = (Front + 1) % MAX_SIZE;
	Size--;

	
}

DataType Queue::GetFront()
{
	if(IsEmpty()) {
		std::cout << "Queue is Empty" << std::endl;
		return DataType();
	}
	return Data[Front];
}
