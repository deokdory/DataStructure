#include "pch.h"
#include "BinaryTree.h"

void DoBinaryTree() {
	BinaryTree tree;
	int arr[15];

	for (int i = 0; i < 15; i++)
	{
		arr[i] = rand();
		std::cout << arr[i] << " ";
		tree.Insert(arr[i]);
	}

	std::cout << std::endl << std::endl;

	// ���� �� ���� Ʈ���� ������ ���
	std::cout << "Before Remove" << std::endl;
	tree.InOrder();

	std::cout << std::endl;

	Pause;
	return;
}

BinaryTree::~BinaryTree()
{
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
}

void BinaryTree::PreOrder()
{
}

void BinaryTree::InOrder()
{
	// ������ȸ�� �����ϱ� ���� ��Ʈ ��忡�� �����ϴ� �Լ��� ȣ��
	InOrder(Root);
	std::cout << std::endl;
}

void BinaryTree::PostOrder()
{
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
	return nullptr;
}

BinaryTreeNode* BinaryTree::RemoveNode(BinaryTreeNode* node)
{
	return nullptr;
}

BinaryTreeNode* BinaryTree::FindMin(BinaryTreeNode* node)
{
	return nullptr;
}

void BinaryTree::PreOrder(BinaryTreeNode* node)
{
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

void BinaryTree::PostOrder(BinaryTreeNode* node)
{
}

void BinaryTree::DestroyTree(BinaryTreeNode* node)
{
}

void BinaryTree::PrintHierarchy(BinaryTreeNode* node, std::string indent, bool last)
{
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
		indent += "| ";
	}

	// ���� ����� ���� ���
	std::cout << node->Data << std::endl;

	// ���� �ڽ� ��带 �湮�Ͽ� ���� ������ ���
	PrintHierarchy(node->LeftChild, indent, false);
	// ������ �ڽ� ��带 �湮�Ͽ� ���� ������ ���
	PrintHierarchy(node->RightChild, indent, true);
}