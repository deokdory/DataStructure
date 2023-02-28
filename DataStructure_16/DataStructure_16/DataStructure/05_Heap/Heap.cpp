#include "pch.h"
#include "Heap.h"

void DoHeap()
{
	Heap h(10);
	std::cout << "Insert Heap" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		h.Insert(rand() % 100);
	}

	std::cout << "Array" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Data [ " << i << " ]  " << h.GetData(i) << std::endl;
	}

	std::cout << "Print Hierarchy" << std::endl;
	h.PrintHierarchy();

	std::cout << "Pop Heap" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << h.Pop() << " ";
	}

	Pause;
	return;
}

Heap::Heap(int maxSize)
{
	Data = new DataType[maxSize];
	MaxSize = maxSize;
	Size = 0;
}
Heap::~Heap()
{
	delete[] Data;
}

void Heap::Insert(DataType data)
{
	if (IsFull()) return;

	Data[Size] = data;
	HeapifyUp(Size);
	Size++;
}

DataType Heap::Pop()
{
	if (IsEmpty()) return -1;

	// 루트 노드의 데이터를 가져옴
	DataType RootData = Data[0];

	// 마지막 노드의 데이터를 루트 노드로 옮기고 크기를 줄인다
	Data[0] = Data[Size - 1];
	Size--;

	// 루트 노드를 기준으로 힙 구조를 유지하도록 HeapifyDown 함수 호출
	HeapifyDown(0);

	return RootData;
}
void Heap::clear()
{
	delete[] Data;
	Data = new DataType[MaxSize];
	Size = 0;
}

bool Heap::IsEmpty()
{
	return Size == 0;
}
bool Heap::IsFull()
{
	return Size == MaxSize;
}

void Heap::PrintHierarchy()
{
	PrintHierarchy(0, "", true);
}

int Heap::GetParent(int index)
{
	return (index - 1) / 2;
}
int Heap::GetLeftChild(int index)
{
	return index * 2 + 1;
}
int Heap::GetRightChild(int index)
{
	return index * 2 + 2;
}

// 새로운 원소를 삽입하거나 기존 원소를 수정한 후
// 힙 조건을 만족하도록 부모 노드와 자식 노드를 비교하여 교환하는 함수
void Heap::HeapifyUp(int index)
{
	// 부모 노드 인덱스
	int parentIndex = GetParent(index);

	// 현재 노드가 루트 노드가 아니고, 부모 노드보다 큰 경우
	if (index > 0 && Data[index] > Data[parentIndex])
	{
		// 현재 노드와 부모 노드의 값을 교환
		std::swap(Data[index], Data[parentIndex]);
		// 부모 노드와 현재 노드가 교환되었으므로, 부모 노드를 기준으로
		// HeapifyUp 을 다시 수행

		HeapifyUp(parentIndex);
	}
}

// 루트 노드를 제거하고 마지막 노드를 루트 노드로 옮긴 후
// 자식 노드와 비교하여 교환하면서 힙 조건을 만족하도록 하는 함수
void Heap::HeapifyDown(int index)
{
	// 왼쪽 자식 노드와 오른쪽 자식 노드 인덱스 불러오기
	int leftIndex = GetLeftChild(index);
	int rightIndex = GetRightChild(index);

	// 현재 노드를 가장 큰 값으로 설정
	int largestIndex = index;

	// 왼쪽 자식 노드가 힙의 크기를 넘지 않고, 현재 노드보다 큰 경우
	if (leftIndex < Size && Data[leftIndex] > Data[largestIndex])
		largestIndex = leftIndex;

	// 오른쪽 자식 노드가 힙의 크기를 넘지 않고, 현재 노드보다 큰 경우
	if (rightIndex < Size && Data[rightIndex] > Data[largestIndex])
		largestIndex = rightIndex;

	// 제일 큰 인덱스가 현재 노드와 다른 경우
	// 즉, 자식 노드 중 하나가 더 큰 경우
	if (largestIndex != index)
	{
		// 현재 노드와 largestIndex 위치의 값을 교환
		std::swap(Data[index], Data[largestIndex]);

		// largestIndex 위치로 이동한 원소를 기준으로 HeapifyDown 다시 실행
		HeapifyDown(largestIndex);
	}
}

void Heap::PrintHierarchy(int index, std::string indent, bool last)
{
	// 출력할 노드의 위치와, 마지막 노드인지 여부에 따라 출력할 문구 설정
	std::cout << indent;
	if (last)
	{
		// 마지막 노드인 경우 출력
		std::cout << "└─ ";
		// indent에 2칸 공백 추가
		indent += "  ";
	}
	else
	{
		// 마지막 노드가 아닌 경우 출력
		std::cout << "├─ ";
		// indent에 |와 공백 추가"
		indent += "| ";
	}

	// 현재 노드의 값을 출력
	std::cout << Data[index] << std::endl;

	// 오른쪽 자식 노드를 방문하여 계층 구조를 출력
	if (2 * index + 2 < Size)
	{
		bool lastRight = false;
		if (2 * index + 1 >= Size)
			lastRight = true;
		PrintHierarchy(2 * index + 2, indent + (last ? "  " : "| "), lastRight);
	}

	// 왼쪽 자식 노드를 방문하여 계층 구조를 출력
	if (2 * index + 1 < Size)
	{
		PrintHierarchy(2 * index + 1, indent + (last ? "  " : "| "), true);
	}
}
