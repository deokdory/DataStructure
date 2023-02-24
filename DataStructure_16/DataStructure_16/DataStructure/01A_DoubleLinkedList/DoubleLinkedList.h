#pragma once

void DoubleLinkedList();

class DLLN {  // Linked List Node
 public:
  static DLLN* Create(DataType data);  // 새 노드 생성

  void Insert(DLLN* cur);  // 중간 삽입
  void InsertHead();                            // 맨 앞 삽입
  void Push();                                  // 맨 뒤 삽입

  static DLLN* GetNode(int index);            // 노드 포인터 가져오기
  const DataType GetData() { return data; }  // 노드 안 데이터 불러오기

  static const int GetLength() { return Length; }  // 리스트 총 길이

  static int GetNodeCount(int index);  // 해당 인덱스부터 끝까지 길이

  static const DLLN* GetHead() { return Head; }  // 처음 노드 불러오기
  static const DLLN* GetTail() { return Tail; }  // 끝 노드 불러오기

  void Remove();            // 노드 삭제
  static void RemoveAll();  // 리스트 전체 삭제
 private:
  static void RemoveAll(const DLLN* head);  // 재귀함수로 내부에서 호출

  DLLN* Next;      // 노드의 다음 노드 포인터
  DLLN* Prev;
  DataType data;  // 노드의 데이터

  static int Length;  // 리스트 길이

  static DLLN* Head;  // 리스트 중 맨 처음 노드
  static DLLN* Tail;  // 리스트 중 맨 마지막 노드
};

void DLLN_Print();