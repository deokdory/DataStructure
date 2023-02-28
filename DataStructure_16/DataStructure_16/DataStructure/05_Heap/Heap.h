#pragma once

void DoHeap();

class Heap {
public:
	Heap(int maxSize);
	~Heap();

	void Insert(DataType data);
	DataType Pop();					// 최상위 요소(루트)를 삭제하고 반환
	void clear();					// 초기화

	bool IsEmpty();
	bool IsFull();

	void PrintHierarchy();			// 계층구조 출력

	const DataType GetData(int i) { return Data[i]; }
private:
	int GetParent(int index);		// 노드의 부모 인덱스를 반환
	int GetLeftChild(int index);	// 노드의 왼쪽 자식 인덱스
	int GetRightChild(int index);	// 노드의 오른쪽 자식 인덱스
	
	void HeapifyUp(int index);		// 힙의 상향식 재정렬
	void HeapifyDown(int index);	// 힙의 하향식 재정렬
	void PrintHierarchy(int index, std::string indent, bool last);

private:
	DataType* Data;		// 요소들을 저장하는 배열
	int MaxSize;		// 배열의 최대 크기
	int Size;			// 현재 요소의 개수
};