#include "pch.h"
#include "LinkedList.h"

// static 멤버 변수 초기화
int LLN::Length = 0;
LLN* LLN::Head = nullptr;
LLN* LLN::Tail = nullptr;

void LinkedList() {
	// 생성 및 푸시
	LLN* node = nullptr;

	for (int i = 0; i < 5; i++)
	{
		node = LLN::Create(i);		// 0 ~ 4 까지 값을 가진 노드를 생성
		node->Push();				// 만들어진 순서에 따라서 리스트에 푸쉬
	}				
	// 현재 리스트
	// 0 -> 1 -> 2 -> 3 -> 4

	LLN_Print();
	std::cout << std::endl;

	std::cout << "================================================" << std::endl;

	// 중간 값 삽입, 맨 앞에 값 삽입
	LLN* new_node = LLN::Create(100);		// 새로운 노드 생성
	LLN::Insert(LLN::GetNode(2), new_node);	// 인덱스 2번 뒤에 새로운 노드를 삽입

	LLN* forward_node = LLN::Create(13223);	// 새로운 노드 생성
	forward_node->InsertHead();				// 맨 앞에 노드 삽입

	LLN_Print();

	std::cout << std::endl;

	std::cout << "================================================" << std::endl;

	// 중간 값 제거
	LLN::GetNode(3)->Remove();
	LLN_Print();

	std::cout << "================================================" << std::endl;

	// 특정 인덱스부터 끝까지의 리스트 길이
	int count = LLN::GetNodeCount(1);
	std::cout << "index[1] ~ Tail Length : " << count << std::endl;

	std::cout << "================================================" << std::endl;

	// 모든 값 제거
	LLN::RemoveAll();
	LLN_Print();

	std::cout << "================================================" << std::endl;

	Pause;
}

LLN* LLN::Create(DataType data)
{
	LLN* node = new LLN;

	node->data = data;
	node->Next = nullptr;
	
	return node;
}

void LLN::Insert(LLN* cur, LLN* new_node)	// cur 다음 인덱스에 들어오게 됨
{
	new_node->Next = cur->Next;				// 새로운 노드의 다음 노드를 기존 위치에 있던 노드의 다음으로 설정
	cur->Next = new_node;					// 원래 노드의 다음 노드를 새로운 노드로 설정

	++Length;								// 길이 1 증가
}

void LLN::InsertHead()
{
	this->Next = Head;		// 새로운 노드가 (전)머리를 가리키게 함
	Head = this;			// 새로운 노드를 (현)머리로 설정

	++Length;				// 길이 1 증가
}

void LLN::Push()
{
	if (Head == nullptr)	// 리스트에 아무 값도 없으면
	{
		Head = this;		// 리스트 맨 처음 값에 이 노드 등록
		Tail = this;		// 리스트 맨 마지막 값에 이 노드 등록
	}
	else					// 리스트에 값이 하나라도 존재
	{
		Tail->Next = this;	// 이전 리스트 마지막 노드의 다음 노드를 이 노드로 설정
		Tail = this;		// 리스트의 꼬리를 이 노드로 설정
	}
	++Length;				// 길이 + 1
}

LLN* LLN::GetNode(int index)
{
	if (Head == nullptr) return nullptr;	// 리스트가 존재하지 않음
		
	LLN* find = Head;						// Linked List는 원하는 인덱스에 있는 값을 찾기 위해
											// 처음(Head)부터 모든 노드를 뒤져야 함

	while (find != nullptr && --index >= 0) // find 포인터가 nullptr 아니어야 하고, 인덱스가 0이 될 때까지 들어가야 함
		find = find->Next;					// 다음 노드로 넘어감

	return find;
}

int LLN::GetNodeCount(int index)
{
	LLN* cur = GetNode(index);
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

void LLN::Remove()
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

	LLN* checker = Head;			// 삭제할 노드의 앞 노드를 찾기 위해서 체커를 생성
									// 앞 노드의 next 를 삭제할 노드의 next 값을 넣기 위해서
	while (1)
	{
		if (checker->Next == this)		// 머리부터 하나씩 체크했을 때 다음 노드가 해당 노드면
		{
			checker->Next = this->Next;	// 체커의 다음을 삭제될 노드의 다음으로 설정
			delete this;				// 삭제
			break;						// 반복문 빠져나옴
		}
		else							// 다음 노드가 삭제시킬 노드가 아니면
		{
			checker = checker->Next;	// checker가 한 칸 이동
		}
	}
	--Length;							// 길이 -1
}

void LLN::RemoveAll() // 외부에서 호출되는 함수
{
	Length = 0;	// length가 0 미만으로 떨어지지 못하도록 방지

	if (Head == nullptr)					// 리스트가 존재하지 않음
	{
		std::cout << "List is already NULL" << std::endl;
		return;
	}

	if (Head->Next != nullptr)
	{
		RemoveAll(Head->Next);
	}
	std::cout << Head->data << "\tData Remove Completed!" << std::endl;
	delete Head;

	Head = nullptr;
	Tail = nullptr;
}

void LLN::RemoveAll(const LLN* head)	// 내부에서 호출되는 함수 (재귀함수 용도)
{
	if (head->Next != nullptr)			// 현재 노드의 다음이 비어있지 않으면
	{
		RemoveAll(head->Next);			// 재귀함수로 다음 노드를 현재 노드로 넣어서 다시 실행
	}
	std::cout << head->data << "\tData Remove Completed!" << std::endl;	// 다음 노드가 nullptr일 경우 실행됨
	delete head;												// 현재 노드 삭제
}

void LLN_Print()
{
	int length = LLN::GetLength();
	if (length <= 0)
	{
		std::cout << "List is NULL" << std::endl;
		return;
	}
	for (int i = 0; i < length; i++)
	{
		std::cout << "index [" << i << "] " << LLN::GetNode(i)->GetData() << std::endl;
	}
}