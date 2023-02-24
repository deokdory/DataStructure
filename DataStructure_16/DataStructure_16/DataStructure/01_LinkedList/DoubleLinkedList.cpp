#include "pch.h"
#include "DoubleLinkedList.h"

// static 멤버 변수 초기화
int DLLN::Length = 0;
DLLN* DLLN::Head = nullptr;
DLLN* DLLN::Tail = nullptr;

void LinkedList() {
	// 생성 및 푸시
	DLLN* node = nullptr;

	for (int i = 0; i < 5; i++)
	{
		node = DLLN::Create(i);		// 0 ~ 4 까지 값을 가진 노드를 생성
		node->Push();				// 만들어진 순서에 따라서 리스트에 푸쉬
	}
	// 현재 리스트
	// 0 -> 1 -> 2 -> 3 -> 4

	DLLN_Print();
	cout << endl;

	cout << "================================================" << endl;

	// 중간 값 삽입, 맨 앞에 값 삽입
	DLLN* new_node = DLLN::Create(100);		// 새로운 노드 생성
	new_node->Insert(DLLN::GetNode(2));	// 인덱스 2번 뒤에 새로운 노드를 삽입

	DLLN* forward_node = DLLN::Create(13223);	// 새로운 노드 생성
	forward_node->InsertHead();				// 맨 앞에 노드 삽입

	DLLN_Print();

	cout << endl;

	cout << "================================================" << endl;

	// 중간 값 제거
	DLLN::GetNode(3)->Remove();
	DLLN_Print();

	cout << "================================================" << endl;

	// 특정 인덱스부터 끝까지의 리스트 길이
	int count = DLLN::GetNodeCount(1);
	cout << "index[1] ~ Tail Length : " << count << endl;

	cout << "================================================" << endl;

	// 모든 값 제거
	DLLN::RemoveAll();
	DLLN_Print();

	cout << "================================================" << endl;

	pause;
}

DLLN* DLLN::Create(DataType data)
{
	DLLN* node = new DLLN;

	node->data = data;
	node->Next = nullptr;
	node->Prev = nullptr;

	return node;
}

void DLLN::Insert(DLLN* cur)	// cur 다음 인덱스에 들어오게 됨
{
	this->Next = cur->Next;				// 새로운 노드의 다음 노드를 기존 위치에 있던 노드의 다음으로 설정
	this->Prev = cur;

	cur->Next = this;					// 원래 노드의 다음 노드를 새로운 노드로 설정

	++Length;								// 길이 1 증가
}

void DLLN::InsertHead()
{
	this->Next = Head;		// 새로운 노드가 (전)머리를 가리키게 함
	Head->Prev = this;

	Head = this;			// 새로운 노드를 (현)머리로 설정

	++Length;				// 길이 1 증가
}

void DLLN::Push()
{
	if (Head == nullptr)	// 리스트에 아무 값도 없으면
	{
		Head = this;		// 리스트 맨 처음 값에 이 노드 등록
		Tail = this;		// 리스트 맨 마지막 값에 이 노드 등록
	}
	else					// 리스트에 값이 하나라도 존재
	{
		Tail->Next = this;	// 이전 리스트 마지막 노드의 다음 노드를 이 노드로 설정
		this->Prev = Tail;
		Tail = this;		// 리스트의 꼬리를 이 노드로 설정
	}
	++Length;				// 길이 + 1
}

DLLN* DLLN::GetNode(int index)
{
	if (Head == nullptr) return nullptr;	// 리스트가 존재하지 않음

	DLLN* find = Head;						// Linked List는 원하는 인덱스에 있는 값을 찾기 위해
											// 처음(Head)부터 모든 노드를 뒤져야 함

	while (find != nullptr && --index >= 0) // find 포인터가 nullptr 아니어야 하고, 인덱스가 0이 될 때까지 들어가야 함
		find = find->Next;					// 다음 노드로 넘어감

	return find;
}

int DLLN::GetNodeCount(int index)
{
	DLLN* cur = GetNode(index);
	if (cur == nullptr) {
		return -1;
	}
	int count = 1;
	while (cur->Next != nullptr) {
		cur = cur->Next;
		++count;
	}
	return count;
}

void DLLN::Remove()
{
	if (this == Head)					// this가 head면 전 노드를 굳이 알 필요가 없음
	{
		if (this->Next != nullptr)		// 다음 노드가 존재한다면
		{
			Head = this->Next;				// 머리를 다음 노드로 설정
		}
		delete this;					// 삭제
		return;
	}

	this->Prev->Next = this->Next;
	this->Next->Prev = this->Prev;

	delete this;

	--Length;							// 길이 -1
}

void DLLN::RemoveAll() // 외부에서 호출되는 함수
{
	Length = 0;

	if (Head == nullptr)					// 리스트가 존재하지 않음
	{
		cout << "List is already NULL" << endl;
		return;
	}

	if (Head->Next != nullptr)
	{
		RemoveAll(Head->Next);
	}
	cout << Head->data << "\tData Remove Completed!" << endl;
	delete Head;

	Head = nullptr;
	Tail = nullptr;
}

void DLLN::RemoveAll(const DLLN* head)	// 내부에서 호출되는 함수 (재귀함수 용도)
{
	if (head->Next != nullptr)			// 현재 노드의 다음이 비어있지 않으면
	{
		RemoveAll(head->Next);			// 재귀함수로 다음 노드를 현재 노드로 넣어서 다시 실행
	}
	cout << head->data << "\tData Remove Completed!" << endl;	// 다음 노드가 nullptr일 경우 실행됨
	delete head;												// 현재 노드 삭제
}

void DLLN_Print()
{
	int length = DLLN::GetLength();
	if (length <= 0)
	{
		cout << "List is NULL" << endl;
		return;
	}
	for (int i = 0; i < length; i++)
	{
		cout << "index [" << i << "] " << DLLN::GetNode(i)->GetData() << endl;
	}
}