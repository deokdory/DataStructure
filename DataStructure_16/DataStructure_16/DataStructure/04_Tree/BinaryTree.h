#pragma once

void DoBinaryTree();

struct BinaryTreeNode {
	BinaryTreeNode(DataType data)
		: Data(data), LeftChild(nullptr), RightChild(nullptr) {}

	DataType Data;
	BinaryTreeNode* LeftChild;
	BinaryTreeNode* RightChild;

};

class BinaryTree
{
public:
	BinaryTree() : Root(nullptr) {}
	~BinaryTree();

	// ������ ����
	void Insert(DataType data);

	// ������ ����
	void Remove(DataType data);

	// ���� ��ȸ
	void PreOrder();

	// ���� ��ȸ
	void InOrder();

	// ���� ��ȸ
	void PostOrder();

	// ���� ���� ���
	void PrintHierarchy();

private:
	// ��� ���� �� ��ȯ
	BinaryTreeNode* Remove(BinaryTreeNode* node, DataType data);

	// ��� ���� �� �ڽ� ��� ���ġ
	BinaryTreeNode* RemoveNode(BinaryTreeNode* node);

	//�ּҰ� �Լ�
	BinaryTreeNode* FindMin(BinaryTreeNode* node);

	// ���� ��ȸ
	void PreOrder(BinaryTreeNode* node);

	// ���� ��ȸ
	void InOrder(BinaryTreeNode* node);

	// ���� ��ȸ
	void PostOrder(BinaryTreeNode* node);

	// Ʈ�� ��ü ��� ����
	void DestroyTree(BinaryTreeNode* node);

	// ���� ���� ��� �Լ�
	void PrintHierarchy(BinaryTreeNode* node, std::string indent, bool last);

private:
	BinaryTreeNode* Root;
};