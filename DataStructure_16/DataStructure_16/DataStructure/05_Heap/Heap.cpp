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

	// ��Ʈ ����� �����͸� ������
	DataType RootData = Data[0];

	// ������ ����� �����͸� ��Ʈ ���� �ű�� ũ�⸦ ���δ�
	Data[0] = Data[Size - 1];
	Size--;

	// ��Ʈ ��带 �������� �� ������ �����ϵ��� HeapifyDown �Լ� ȣ��
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

// ���ο� ���Ҹ� �����ϰų� ���� ���Ҹ� ������ ��
// �� ������ �����ϵ��� �θ� ���� �ڽ� ��带 ���Ͽ� ��ȯ�ϴ� �Լ�
void Heap::HeapifyUp(int index)
{
	// �θ� ��� �ε���
	int parentIndex = GetParent(index);

	// ���� ��尡 ��Ʈ ��尡 �ƴϰ�, �θ� ��庸�� ū ���
	if (index > 0 && Data[index] > Data[parentIndex])
	{
		// ���� ���� �θ� ����� ���� ��ȯ
		std::swap(Data[index], Data[parentIndex]);
		// �θ� ���� ���� ��尡 ��ȯ�Ǿ����Ƿ�, �θ� ��带 ��������
		// HeapifyUp �� �ٽ� ����

		HeapifyUp(parentIndex);
	}
}

// ��Ʈ ��带 �����ϰ� ������ ��带 ��Ʈ ���� �ű� ��
// �ڽ� ���� ���Ͽ� ��ȯ�ϸ鼭 �� ������ �����ϵ��� �ϴ� �Լ�
void Heap::HeapifyDown(int index)
{
	// ���� �ڽ� ���� ������ �ڽ� ��� �ε��� �ҷ�����
	int leftIndex = GetLeftChild(index);
	int rightIndex = GetRightChild(index);

	// ���� ��带 ���� ū ������ ����
	int largestIndex = index;

	// ���� �ڽ� ��尡 ���� ũ�⸦ ���� �ʰ�, ���� ��庸�� ū ���
	if (leftIndex < Size && Data[leftIndex] > Data[largestIndex])
		largestIndex = leftIndex;

	// ������ �ڽ� ��尡 ���� ũ�⸦ ���� �ʰ�, ���� ��庸�� ū ���
	if (rightIndex < Size && Data[rightIndex] > Data[largestIndex])
		largestIndex = rightIndex;

	// ���� ū �ε����� ���� ���� �ٸ� ���
	// ��, �ڽ� ��� �� �ϳ��� �� ū ���
	if (largestIndex != index)
	{
		// ���� ���� largestIndex ��ġ�� ���� ��ȯ
		std::swap(Data[index], Data[largestIndex]);

		// largestIndex ��ġ�� �̵��� ���Ҹ� �������� HeapifyDown �ٽ� ����
		HeapifyDown(largestIndex);
	}
}

void Heap::PrintHierarchy(int index, std::string indent, bool last)
{
	// ����� ����� ��ġ��, ������ ������� ���ο� ���� ����� ���� ����
	std::cout << indent;
	if (last)
	{
		// ������ ����� ��� ���
		std::cout << "���� ";
		// indent�� 2ĭ ���� �߰�
		indent += "  ";
	}
	else
	{
		// ������ ��尡 �ƴ� ��� ���
		std::cout << "���� ";
		// indent�� |�� ���� �߰�"
		indent += "| ";
	}

	// ���� ����� ���� ���
	std::cout << Data[index] << std::endl;

	// ������ �ڽ� ��带 �湮�Ͽ� ���� ������ ���
	if (2 * index + 2 < Size)
	{
		bool lastRight = false;
		if (2 * index + 1 >= Size)
			lastRight = true;
		PrintHierarchy(2 * index + 2, indent + (last ? "  " : "| "), lastRight);
	}

	// ���� �ڽ� ��带 �湮�Ͽ� ���� ������ ���
	if (2 * index + 1 < Size)
	{
		PrintHierarchy(2 * index + 1, indent + (last ? "  " : "| "), true);
	}
}
