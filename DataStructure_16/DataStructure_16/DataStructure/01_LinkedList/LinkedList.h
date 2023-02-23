#pragma once

void DoLinkedList();

class LLN { // Linked List Node
public:
	static LLN* LLN_Create(DataType data);			// 새 노드 생성
	static void LLN_Remove(LLN* node);				// 노드 삭제

	static void Insert(LLN* cur, LLN* new_node);	// 중간 삽입
	static void InsertHead(LLN* new_node);			// 맨 앞 삽입
	static void Push(LLN* new_node);				// 맨 뒤 삽입

	static LLN* GetNode(int index);					// 노드 포인터 가져오기ㅇ
private:
	LLN* next;			// 노드의 다음 노드 포인터
	DataType data;		// 노드의 데이터

	static int length;	// 리스트 길이

	static LLN* Head;	// 리스트 중 맨 처음 노드
	static LLN* Tail;	// 리스트 중 맨 마지막 노드
};