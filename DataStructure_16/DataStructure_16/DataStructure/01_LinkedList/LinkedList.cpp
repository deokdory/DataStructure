#include "pch.h"
#include "LinkedList.h"

// static ��� ���� �ʱ�ȭ
int LLN::length = 0;
LLN* LLN::Head = nullptr;
LLN* LLN::Tail = nullptr;

void DoLinkedList() {
	LLN* node = LLN::LLN_Create(32);	// ��� ����
	LLN::Push(node);					// ����Ʈ�� ���
}

LLN* LLN::LLN_Create(DataType data)
{
	LLN* node = new LLN;

	node->data = data;
	node->next = nullptr;
	
	return node;
}

void LLN::LLN_Remove(LLN* node)
{
}

void LLN::Insert(LLN* cur, LLN* new_node)
{
}

void LLN::InsertHead(LLN* new_node)
{
}

void LLN::Push(LLN* new_node)
{
	if (Head == nullptr)		// ����Ʈ�� �ƹ� ���� ������
	{
		Head = new_node;		// ����Ʈ �� ó�� ���� ���
		Tail = new_node;		// ����Ʈ �� ������ ���� ���
	}
	else						// ����Ʈ�� ���� �ϳ��� ����
	{
		Tail->next = new_node;	// ����Ʈ ������ ����� ���� ��带 ���ο� ���� ����
		Tail = new_node;		// ����Ʈ�� ������ ���ο� ���� ����
	}
	++length;					// ���� + 1
}

LLN* LLN::GetNode(int index)
{
	return nullptr;
}
