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

	// 데이터 삽입
	void Insert(DataType data);

	// 데이터 삭제
	void Remove(DataType data);

	// 전위 순회
	void PreOrder();

	// 중위 순회
	void InOrder();

	// 후위 순회
	void PostOrder();

	// 계층 구조 출력
	void PrintHierarchy();

private:
	// 노드 삭제 및 반환
	BinaryTreeNode* Remove(BinaryTreeNode* node, DataType data);

	// 노드 삭제 후 자식 노드 재배치
	BinaryTreeNode* RemoveNode(BinaryTreeNode* node);

	//최소값 함수
	BinaryTreeNode* FindMin(BinaryTreeNode* node);

	// 전위 순회
	void PreOrder(BinaryTreeNode* node);

	// 중위 순회
	void InOrder(BinaryTreeNode* node);

	// 후위 순회
	void PostOrder(BinaryTreeNode* node);

	// 트리 전체 노드 삭제
	void DestroyTree(BinaryTreeNode* node);

	// 계층 구조 출력 함수
	void PrintHierarchy(BinaryTreeNode* node, std::string indent, bool last);

private:
	BinaryTreeNode* Root;
};