#include "pch.h"
#include "LinkedList.h"

// static ��� ���� �ʱ�ȭ
int LLN::Length = 0;
LLN* LLN::Head = nullptr;
LLN* LLN::Tail = nullptr;

void LinkedList() {
	// ���� �� Ǫ��
	LLN* node = nullptr;

	for (int i = 0; i < 5; i++)
	{
		node = LLN::Create(i);		// 0 ~ 4 ���� ���� ���� ��带 ����
		node->Push();				// ������� ������ ���� ����Ʈ�� Ǫ��
	}				
	// ���� ����Ʈ
	// 0 -> 1 -> 2 -> 3 -> 4

	LLN_Print();
	std::cout << std::endl;

	std::cout << "================================================" << std::endl;

	// �߰� �� ����, �� �տ� �� ����
	LLN* new_node = LLN::Create(100);		// ���ο� ��� ����
	LLN::Insert(LLN::GetNode(2), new_node);	// �ε��� 2�� �ڿ� ���ο� ��带 ����

	LLN* forward_node = LLN::Create(13223);	// ���ο� ��� ����
	forward_node->InsertHead();				// �� �տ� ��� ����

	LLN_Print();

	std::cout << std::endl;

	std::cout << "================================================" << std::endl;

	// �߰� �� ����
	LLN::GetNode(3)->Remove();
	LLN_Print();

	std::cout << "================================================" << std::endl;

	// Ư�� �ε������� �������� ����Ʈ ����
	int count = LLN::GetNodeCount(1);
	std::cout << "index[1] ~ Tail Length : " << count << std::endl;

	std::cout << "================================================" << std::endl;

	// ��� �� ����
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

void LLN::Insert(LLN* cur, LLN* new_node)	// cur ���� �ε����� ������ ��
{
	new_node->Next = cur->Next;				// ���ο� ����� ���� ��带 ���� ��ġ�� �ִ� ����� �������� ����
	cur->Next = new_node;					// ���� ����� ���� ��带 ���ο� ���� ����

	++Length;								// ���� 1 ����
}

void LLN::InsertHead()
{
	this->Next = Head;		// ���ο� ��尡 (��)�Ӹ��� ����Ű�� ��
	Head = this;			// ���ο� ��带 (��)�Ӹ��� ����

	++Length;				// ���� 1 ����
}

void LLN::Push()
{
	if (Head == nullptr)	// ����Ʈ�� �ƹ� ���� ������
	{
		Head = this;		// ����Ʈ �� ó�� ���� �� ��� ���
		Tail = this;		// ����Ʈ �� ������ ���� �� ��� ���
	}
	else					// ����Ʈ�� ���� �ϳ��� ����
	{
		Tail->Next = this;	// ���� ����Ʈ ������ ����� ���� ��带 �� ���� ����
		Tail = this;		// ����Ʈ�� ������ �� ���� ����
	}
	++Length;				// ���� + 1
}

LLN* LLN::GetNode(int index)
{
	if (Head == nullptr) return nullptr;	// ����Ʈ�� �������� ����
		
	LLN* find = Head;						// Linked List�� ���ϴ� �ε����� �ִ� ���� ã�� ����
											// ó��(Head)���� ��� ��带 ������ ��

	while (find != nullptr && --index >= 0) // find �����Ͱ� nullptr �ƴϾ�� �ϰ�, �ε����� 0�� �� ������ ���� ��
		find = find->Next;					// ���� ���� �Ѿ

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
	if (this == Head)					// this�� head�� �� ��带 ���� �� �ʿ䰡 ����
	{
		if (this->Next != nullptr)		// ���� ��尡 �����Ѵٸ�
		{
		Head = this->Next;				// �Ӹ��� ���� ���� ����
		}
		delete this;					// ����
		return;
	}

	LLN* checker = Head;			// ������ ����� �� ��带 ã�� ���ؼ� üĿ�� ����
									// �� ����� next �� ������ ����� next ���� �ֱ� ���ؼ�
	while (1)
	{
		if (checker->Next == this)		// �Ӹ����� �ϳ��� üũ���� �� ���� ��尡 �ش� ����
		{
			checker->Next = this->Next;	// üĿ�� ������ ������ ����� �������� ����
			delete this;				// ����
			break;						// �ݺ��� ��������
		}
		else							// ���� ��尡 ������ų ��尡 �ƴϸ�
		{
			checker = checker->Next;	// checker�� �� ĭ �̵�
		}
	}
	--Length;							// ���� -1
}

void LLN::RemoveAll() // �ܺο��� ȣ��Ǵ� �Լ�
{
	Length = 0;	// length�� 0 �̸����� �������� ���ϵ��� ����

	if (Head == nullptr)					// ����Ʈ�� �������� ����
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

void LLN::RemoveAll(const LLN* head)	// ���ο��� ȣ��Ǵ� �Լ� (����Լ� �뵵)
{
	if (head->Next != nullptr)			// ���� ����� ������ ������� ������
	{
		RemoveAll(head->Next);			// ����Լ��� ���� ��带 ���� ���� �־ �ٽ� ����
	}
	std::cout << head->data << "\tData Remove Completed!" << std::endl;	// ���� ��尡 nullptr�� ��� �����
	delete head;												// ���� ��� ����
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