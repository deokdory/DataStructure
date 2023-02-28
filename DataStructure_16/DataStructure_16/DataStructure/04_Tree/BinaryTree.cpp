#include "pch.h"
#include "BinaryTree.h"

void DoBinaryTree() {
	BinaryTree tree;
	int arr[15];

	for (int i = 0; i < 15; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
		tree.Insert(arr[i]);
	}

	std::cout << std::endl << std::endl;

	// ���� �� ���� Ʈ���� ������ ���
	std::cout << "Before Remove" << std::endl;
	tree.InOrder();

	// �迭���� �ϳ��� ���� �����ϰ� �����ؼ� ����
	tree.Remove(arr[rand() % 15]);

	// ���� �� ����Ʈ�� ���
	std::cout << "After Remove" << std::endl;
	tree.InOrder();

	tree.PrintHierarchy();
	Pause;
	return;
}

BinaryTree::~BinaryTree()
{
	// Ʈ���� �����ϱ� ���� ���� ������ ��������� Ž���Ͽ�
	// ��带 �����ϴ� �Լ��� ȣ��
	DestroyTree(Root);
}

// ������ ����
void BinaryTree::Insert(DataType data)
{
	// �� ��� ����
	BinaryTreeNode* newNode = new BinaryTreeNode(data);

	// Ʈ���� Root ������ �� ��带 Root�� ����
	if (Root == nullptr) {
		Root = newNode;
		return;
	}

	// ��Ʈ ������ �����ؼ� �� ��带 ������ ��ġ�� ã��
	BinaryTreeNode* curNode = Root;
	while (true)
	{
		// ���� ��庸�� ���� ���̸� 
		if (data < curNode->Data) {
			// ���� �ڽ� ��尡 ��� ������ ( ������ ������ ���ʺ��� )
			if (curNode->LeftChild == nullptr) {

				// �� ��带 �� �ڸ��� ����
				curNode->LeftChild = newNode;
				return;
			}
			// ������� ������, ���� �ڽ� ��带 ���� ���� �ٲٰ� �ݺ�
			curNode = curNode->LeftChild;
		}

		// ���� ��庸�� ū ���̸�
		else {

			// ������ �ڽ� ��尡 ��� ������
			if (curNode->RightChild == nullptr) {

				// �� ��带 �� �ڸ��� ����
				curNode->RightChild = newNode;
				return;
			}
			// ��� ���� ������, ������ �ڽ� ��带 ���� ���� �ٲٰ� �ݺ�
			curNode = curNode->RightChild;
		}
	}
}

void BinaryTree::Remove(DataType data)
{
	// Ʈ������ �����͸� �����ϱ� ���� ��Ʈ ������ ��������� Ž���Ͽ�
	// ��带 �����ϴ� �Լ�
	Root = Remove(Root, data);
}

void BinaryTree::PreOrder()
{
	PreOrder(Root);
	std::cout << std::endl;
}

void BinaryTree::InOrder()
{
	// ������ȸ�� �����ϱ� ���� ��Ʈ ��忡�� �����ϴ� �Լ��� ȣ��
	InOrder(Root);
	std::cout << std::endl;
}

void BinaryTree::PostOrder()
{
	PostOrder(Root);
	std::cout << std::endl;
}

void BinaryTree::PrintHierarchy()
{
	if (Root == nullptr) {
		std::cout << "Empty Tree" << std::endl;
	}
	else {
		PrintHierarchy(Root, "", true);
	}
}

BinaryTreeNode* BinaryTree::Remove(BinaryTreeNode* node, DataType data)
{
	// ��尡 ��������� ����
	if (!node) return nullptr;

	// ���� ����� �����Ͱ� ������ �����Ϳ� ���ٸ�
	if (data == node->Data)
		// ����
		return RemoveNode(node);

	// ������ �����Ͱ� ��庸�� ���� ���
	else if (data < node->Data)
	{
		// ���� �ڽ� ��忡�� ������ ����
		node->LeftChild = Remove(node->LeftChild, data);
		return node;
	}
	// ������ �����Ͱ� ��庸�� Ŭ ���
	else
	{
		// ������ �ڽ� ��忡�� ������ ����
		node->RightChild = Remove(node->RightChild, data);
		return node;
	}
}

BinaryTreeNode* BinaryTree::RemoveNode(BinaryTreeNode* node)
{
	// ������ ��尡 leaf ����� ���
	if (node->LeftChild == nullptr && node->RightChild == nullptr)
	{
		// ��� ����
		delete node;
		// �θ� ��忡�� �ش� ��� ������ ���� ���� nullptr ��ȯ
		return nullptr;
	}
	// ������ ��尡 �ڽ��� ������ ��� (1��)
	else if (node->LeftChild != nullptr || node->RightChild != nullptr)
	{
		// ������ ����� �ڽ� ��� �� �����ϴ� �ڽ� ��带 ã�Ƽ� target���� ����
		BinaryTreeNode* target = (node->LeftChild != nullptr) ? node->LeftChild : node->RightChild;

		// ��� ����
		delete node;

		// �θ� ��忡�� �ش� ��� ������ ���� �����ϴ� �ڽ� ���� �����ϱ� ���� target�� ��ȯ
		return target;
	}
	// ���� ��尡 �ڽ��� ������ ��� (2��)
	else
	{
		// ������ ����� ������ ����Ʈ������ ���� ���� ���� ���� ��带 ã�Ƽ� target���� ����
		BinaryTreeNode* target = FindMin(node->RightChild);

		// ������ ����� �����͸� ã�� ����� �����ͷ� ����
		node->Data = target->Data;

		// ��带 �����ϰ�, ������ ����� ������ �ڽ� ���� �����ϱ� ���� target �� ��ȯ
		node->RightChild = Remove(node->RightChild, target->Data);
		return node;
	}
}

BinaryTreeNode* BinaryTree::FindMin(BinaryTreeNode* node)
{
	// ��� ���� �ڽ��� ���� ������ �ݺ��ؼ� ���� �ڽ����� �̵�
	while (node->LeftChild != nullptr)
		node = node->LeftChild;

	// ���� ���� ���� ��带 ��ȯ
	return node;
}

// ������ȸ (���� ��� -> ���� �ڽ� -> ������ �ڽ�)
void BinaryTree::PreOrder(BinaryTreeNode* node)
{
	// ��尡 �����Ѵٸ�
	if (node) {

		// ���� ��� ���
		std::cout << node->Data << " ";
		// ���� �ڽ� ��� �湮
		PreOrder(node->LeftChild);
		// ������ �ڽ� ��� �湮
		PreOrder(node->RightChild);
	}
}

// ������ȸ (���� �ڽ� -> ���� ��� -> ������ �ڽ�)
void BinaryTree::InOrder(BinaryTreeNode* node)
{
	// ��尡 �����Ѵٸ�
	if (node) {

		// ���� �ڽ� ��� �湮
		InOrder(node->LeftChild);
		// ���� ��� ���
		std::cout << node->Data << " ";
		// ������ �ڽ� ��� �湮
		InOrder(node->RightChild);
	}
}

// ������ȸ ( ���� �ڽ� -> ������ �ڽ� -> ���� ��� )
void BinaryTree::PostOrder(BinaryTreeNode* node)
{
	// ��尡 �����Ѵٸ�
	if (node) {

		// ���� �ڽ� ��� �湮
		PostOrder(node->LeftChild);
		// ������ �ڽ� ��� �湮
		PostOrder(node->RightChild);
		// ���� ��� ���
		std::cout << node->Data << " ";
	}
}

void BinaryTree::DestroyTree(BinaryTreeNode* node)
{
	if (node)
	{
		DestroyTree(node->LeftChild);
		DestroyTree(node->RightChild);
		delete node;
	}
}

void BinaryTree::PrintHierarchy(BinaryTreeNode* node, std::string indent, bool last)
{
	if (!node) return;

	// ����� ����� ��ġ��, ������ ������� ���ο� ���� ����� ���� ����
	std::cout << indent;
	if (last)
	{
		// ������ ����� ��� ���
		std::cout << "���� ";
		// indent�� 2ĭ ���� �߰�
		indent += "  ";
	}
	else
	{
		// ������ ��尡 �ƴ� ��� ���
		std::cout << "���� ";
		// indent�� |�� ���� �߰�"
		indent += "�� ";
	}

	// ���� ����� ���� ���
	std::cout << node->Data << std::endl;

	// ������ �ڽ� ��带 �湮�Ͽ� ���� ������ ���
	PrintHierarchy(node->RightChild, indent, node->LeftChild == nullptr);
	// ���� �ڽ� ��带 �湮�Ͽ� ���� ������ ���
	PrintHierarchy(node->LeftChild, indent, false);
}