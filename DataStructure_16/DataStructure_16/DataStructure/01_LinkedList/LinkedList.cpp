#include "pch.h"
#include "LinkedList.h"

// static 멤버 변수 초기화
int LLN::length = 0;
LLN* LLN::Head = nullptr;
LLN* LLN::Tail = nullptr;

void DoLinkedList() {
	LLN* node = LLN::LLN_Create(32);	// 노드 생성
	LLN::Push(node);					// 리스트에 등록
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
	if (Head == nullptr)		// 리스트에 아무 값도 없으면
	{
		Head = new_node;		// 리스트 맨 처음 값에 등록
		Tail = new_node;		// 리스트 맨 마지막 값에 등록
	}
	else						// 리스트에 값이 하나라도 존재
	{
		Tail->next = new_node;	// 리스트 마지막 노드의 다음 노드를 새로운 노드로 설정
		Tail = new_node;		// 리스트의 꼬리를 새로운 노드로 설정
	}
	++length;					// 길이 + 1
}

LLN* LLN::GetNode(int index)
{
	return nullptr;
}
