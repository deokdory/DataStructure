#pragma once

void DoubleLinkedList();

class DLLN {  // Linked List Node
 public:
  static DLLN* Create(DataType data);  // �� ��� ����

  void Insert(DLLN* cur);  // �߰� ����
  void InsertHead();                            // �� �� ����
  void Push();                                  // �� �� ����

  static DLLN* GetNode(int index);            // ��� ������ ��������
  const DataType GetData() { return data; }  // ��� �� ������ �ҷ�����

  static const int GetLength() { return Length; }  // ����Ʈ �� ����

  static int GetNodeCount(int index);  // �ش� �ε������� ������ ����

  static const DLLN* GetHead() { return Head; }  // ó�� ��� �ҷ�����
  static const DLLN* GetTail() { return Tail; }  // �� ��� �ҷ�����

  void Remove();            // ��� ����
  static void RemoveAll();  // ����Ʈ ��ü ����
 private:
  static void RemoveAll(const DLLN* head);  // ����Լ��� ���ο��� ȣ��

  DLLN* Next;      // ����� ���� ��� ������
  DLLN* Prev;
  DataType data;  // ����� ������

  static int Length;  // ����Ʈ ����

  static DLLN* Head;  // ����Ʈ �� �� ó�� ���
  static DLLN* Tail;  // ����Ʈ �� �� ������ ���
};

void DLLN_Print();