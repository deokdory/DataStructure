#pragma once

void LinkedList();

class LLN { // Linked List Node
public:
	static LLN* Create(DataType data);			// �� ��� ����

	static void Insert(LLN* cur, LLN* new_node);	// �߰� ����
	void InsertHead();								// �� �� ����
	void Push();									// �� �� ����

	static LLN* GetNode(int index);					// ��� ������ ��������
	const DataType GetData() { return data; }		// ��� �� ������ �ҷ�����

	static const int GetLength() { return Length; } // ����Ʈ �� ����

	static int GetNodeCount(int index);				// �ش� �ε������� ������ ����

	static const LLN* GetHead() { return Head; }	// ó�� ��� �ҷ�����
	static const LLN* GetTail() { return Tail; }	// �� ��� �ҷ�����

	void Remove();									// ��� ����
	static void RemoveAll();						// ����Ʈ ��ü ����
private:
	static void RemoveAll(const LLN* head);			// ����Լ��� ���ο��� ȣ��

	LLN* Next;			// ����� ���� ��� ������
	DataType data;		// ����� ������

	static int Length;	// ����Ʈ ����

	static LLN* Head;	// ����Ʈ �� �� ó�� ���
	static LLN* Tail;	// ����Ʈ �� �� ������ ���
};

void LLN_Print();