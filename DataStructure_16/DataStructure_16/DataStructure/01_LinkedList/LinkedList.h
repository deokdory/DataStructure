#pragma once

void DoLinkedList();

class LLN { // Linked List Node
public:
	static LLN* LLN_Create(DataType data);			// �� ��� ����
	static void LLN_Remove(LLN* node);				// ��� ����

	static void Insert(LLN* cur, LLN* new_node);	// �߰� ����
	static void InsertHead(LLN* new_node);			// �� �� ����
	static void Push(LLN* new_node);				// �� �� ����

	static LLN* GetNode(int index);					// ��� ������ �������⤷
private:
	LLN* next;			// ����� ���� ��� ������
	DataType data;		// ����� ������

	static int length;	// ����Ʈ ����

	static LLN* Head;	// ����Ʈ �� �� ó�� ���
	static LLN* Tail;	// ����Ʈ �� �� ������ ���
};