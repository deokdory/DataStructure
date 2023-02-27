#include "pch.h"
#include "Stack.h"

void DoStack()
{
	Stack s;
	s.Push(1);
	s.Push(2);
	s.Push(3);

	std::cout << s.Pop() << std::endl;
	std::cout << s.Peek() << std::endl;
	std::cout << s.Pop() << std::endl;
	std::cout << s.Pop() << std::endl;
	std::cout << s.Pop() << std::endl;
	std::cout << s.Pop() << std::endl;
	std::cout << s.Pop() << std::endl;



	Pause;
	return;
}

Stack::Stack()
{
	Top = -1;
}

bool Stack::IsEmpty()
{
	// 비어있으면 true, 아니면 false
	return Top == -1;
}

// 삽입
bool Stack::IsFull()
{
	return Top == MAX_SIZE - 1;
}

void Stack::Push(DataType data)
{ 
	// 가득 차있다면
	if (IsFull()) { 
		std::cout << "Stack Overflow" << std::endl;
		return;
	}
	Data[++Top] = data;
}

int Stack::Pop()
{
	if (IsEmpty()) {
		std::cout << "Stack Underflow" << std::endl;
		return -1;
	}

	return Data[Top--];
}

int Stack::Peek()
{
	if (IsEmpty())
	{
		std::cout << "Stack Underflow" << std::endl;
		return -1;
	}
	return Data[Top];
}
