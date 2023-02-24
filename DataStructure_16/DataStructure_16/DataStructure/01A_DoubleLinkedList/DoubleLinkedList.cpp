#include "pch.h"
#include "DoubleLinkedList.h"

// static ��� ���� �ʱ�ȭ
int DLLN::Length = 0;
DLLN* DLLN::Head = nullptr;
DLLN* DLLN::Tail = nullptr;

void DoubleLinkedList() {
  // ���� �� Ǫ��
  DLLN* node = nullptr;

  for (int i = 0; i < 5; i++) {
    node = DLLN::Create(i);  // 0 ~ 4 ���� ���� ���� ��带 ����
    node->Push();  // ������� ������ ���� ����Ʈ�� Ǫ��
  }
  // ���� ����Ʈ
  // 0 -> 1 -> 2 -> 3 -> 4

  DLLN_Print();
  cout << endl;

  cout << "================================================" << endl;

  // �߰� �� ����, �� �տ� �� ����
  DLLN* new_node = DLLN::Create(100);  // ���ο� ��� ����
  new_node->Insert(DLLN::GetNode(2));  // �ε��� 2�� �ڿ� ���ο� ��带 ����

  DLLN* forward_node = DLLN::Create(13223);  // ���ο� ��� ����
  forward_node->InsertHead();              // �� �տ� ��� ����

  DLLN_Print();

  cout << endl;

  cout << "================================================" << endl;

  // �߰� �� ����
  DLLN::GetNode(3)->Remove();
  DLLN_Print();

  cout << "================================================" << endl;

  // Ư�� �ε������� �������� ����Ʈ ����
  int count = DLLN::GetNodeCount(1);
  cout << "index[1] ~ Tail Length : " << count << endl;

  cout << "================================================" << endl;

  // ��� �� ����
  DLLN::RemoveAll();
  DLLN_Print();

  cout << "================================================" << endl;

  pause;
}

DLLN* DLLN::Create(DataType data) {
  DLLN* node = new DLLN;

  node->data = data;
  node->Next = nullptr;
  node->Prev = nullptr;

  return node;
}

void DLLN::Insert(DLLN* cur)  // cur ���� �ε����� ������ ��
{
  this->Next = cur->Next;  // ���ο� ����� ���� ��带 ���� ��ġ�� �ִ�
                               // ����� �������� ����
  this->Prev = cur;

  cur->Next = this;  // ���� ����� ���� ��带 ���ο� ���� ����

  ++Length;  // ���� 1 ����
}

void DLLN::InsertHead() {
  this->Next = Head;  // ���ο� ��尡 (��)�Ӹ��� ����Ű�� ��
  Head->Prev = this;
  Head = this;        // ���ο� ��带 (��)�Ӹ��� ����

  ++Length;  // ���� 1 ����
}

void DLLN::Push() {
  if (Head == nullptr)  // ����Ʈ�� �ƹ� ���� ������
  {
    Head = this;  // ����Ʈ �� ó�� ���� �� ��� ���
    Tail = this;  // ����Ʈ �� ������ ���� �� ��� ���
  } else          // ����Ʈ�� ���� �ϳ��� ����
  {
    Tail->Next = this;  // ���� ����Ʈ ������ ����� ���� ��带 �� ���� ����
    this->Prev = Tail;
    Tail = this;  // ����Ʈ�� ������ �� ���� ����
  }
  ++Length;  // ���� + 1
}

DLLN* DLLN::GetNode(int index) {
  if (Head == nullptr) return nullptr;  // ����Ʈ�� �������� ����

  DLLN* find = Head;  // Linked List�� ���ϴ� �ε����� �ִ� ���� ã�� ����
                     // ó��(Head)���� ��� ��带 ������ ��
  while (find != nullptr && --index >= 0)  // find �����Ͱ� nullptr �ƴϾ�� �ϰ�, �ε����� 0�� ��
                        // ������ ���� ��
    find = find->Next;  // ���� ���� �Ѿ
  return find;
}

int DLLN::GetNodeCount(int index) {
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

void DLLN::Remove() {
  if (this == Head)  // this�� head�� �� ��带 ���� �� �ʿ䰡 ����
  {
    if (this->Next != nullptr)  // ���� ��尡 �����Ѵٸ�
    {
      this->Next->Prev = nullptr;
      Head = this->Next;  // �Ӹ��� ���� ���� ����
    }
  } else {
    if (this == Tail) {
      this->Prev->Next = nullptr;
      Tail = this->Prev;
    } else {
      this->Next->Prev = this->Prev;
      this->Prev->Next = this->Next;
    }
  }
  delete this;  // ����
  --Length;  // ���� -1
  return;
}

void DLLN::RemoveAll()  // �ܺο��� ȣ��Ǵ� �Լ�
{
  Length = 0;  // length�� 0 �̸����� �������� ���ϵ��� ����

  if (Head == nullptr)  // ����Ʈ�� �������� ����
  {
    cout << "List is already NULL" << endl;
    return;
  }

  if (Head->Next != nullptr) {
    RemoveAll(Head->Next);
  }
  cout << Head->data << "\tData Remove Completed!" << endl;
  delete Head;

  Head = nullptr;
  Tail = nullptr;
}

void DLLN::RemoveAll(const DLLN* head)  // ���ο��� ȣ��Ǵ� �Լ� (����Լ� �뵵)
{
  if (head->Next != nullptr)  // ���� ����� ������ ������� ������
  {
    RemoveAll(
        head->Next);  // ����Լ��� ���� ��带 ���� ���� �־ �ٽ� ����
  }
  cout << head->data << "\tData Remove Completed!"
       << endl;  // ���� ��尡 nullptr�� ��� �����
  delete head;   // ���� ��� ����
}

void DLLN_Print() {
  int length = DLLN::GetLength();
  if (length <= 0) {
    cout << "List is NULL" << endl;
    return;
  }
  for (int i = 0; i < length; i++) {
    cout << "index [" << i << "] " << DLLN::GetNode(i)->GetData() << endl;
  }
}