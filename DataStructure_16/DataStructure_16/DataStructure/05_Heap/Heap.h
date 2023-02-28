#pragma once

void DoHeap();

class Heap {
public:
	Heap(int maxSize);
	~Heap();

	void Insert(DataType data);
	DataType Pop();					// �ֻ��� ���(��Ʈ)�� �����ϰ� ��ȯ
	void clear();					// �ʱ�ȭ

	bool IsEmpty();
	bool IsFull();

	void PrintHierarchy();			// �������� ���

	const DataType GetData(int i) { return Data[i]; }
private:
	int GetParent(int index);		// ����� �θ� �ε����� ��ȯ
	int GetLeftChild(int index);	// ����� ���� �ڽ� �ε���
	int GetRightChild(int index);	// ����� ������ �ڽ� �ε���
	
	void HeapifyUp(int index);		// ���� ����� ������
	void HeapifyDown(int index);	// ���� ����� ������
	void PrintHierarchy(int index, std::string indent, bool last);

private:
	DataType* Data;		// ��ҵ��� �����ϴ� �迭
	int MaxSize;		// �迭�� �ִ� ũ��
	int Size;			// ���� ����� ����
};