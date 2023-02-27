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

	// 삭제 전 이전 트리의 내용을 출력
	std::cout << "Before Remove" << std::endl;
	tree.InOrder();

	std::cout << std::endl;

	Pause;
	return;
}

BinaryTree::~BinaryTree()
{
}

// 데이터 삽입
void BinaryTree::Insert(DataType data)
{
	// 새 노드 생성
	BinaryTreeNode* newNode = new BinaryTreeNode(data);

	// 트리에 Root 없으면 새 노드를 Root로 설정
	if (Root == nullptr) {
		Root = newNode;
		return;
	}

	// 루트 노드부터 시작해서 새 노드를 삽입할 위치를 찾음
	BinaryTreeNode* curNode = Root;
	while (true)
	{
		// 현재 노드보다 작은 값이면 
		if (data < curNode->Data) {
			// 왼쪽 자식 노드가 비어 있으면 ( 삽입은 무조건 왼쪽부터 )
			if (curNode->LeftChild == nullptr) {

				// 새 노드를 그 자리에 삽입
				curNode->LeftChild = newNode;
				return;
			}
			// 비어있지 않으면, 왼쪽 자식 노드를 현재 노드로 바꾸고 반복
			curNode = curNode->LeftChild;
		}

		// 현재 노드보다 큰 값이면
		else { 

			// 오른쪽 자식 노드가 비어 있으면
			if (curNode->RightChild == nullptr) {

				// 새 노드를 그 자리에 삽입
				curNode->RightChild = newNode;
				return;
			}
			// 비어 있지 않으면, 오른쪽 자식 노드를 현재 노드로 바꾸고 반복
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
	// 중위순회를 실행하기 위해 루트 노드에서 시작하는 함수를 호출
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

// 중위손회 (왼쪽 자식 -> 현재 노드 -> 오른쪽 자식)
void BinaryTree::InOrder(BinaryTreeNode* node)
{
	// 노드가 존재한다면
	if (node) {

		// 왼쪽 자식 노드 방문
		InOrder(node->LeftChild);
		// 현재 노드 출력
		std::cout << node->Data << " ";
		// 오른쪽 자식 노드 방문
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
	// 출력할 노드의 위치와, 마지막 노드인지 여부에 따라 출력할 문구 설정
	std::cout << indent;
	if (last)
	{
		// 마지막 노드인 경우 출력
		std::cout << "└─ ";
		// indent에 2칸 공백 추가
		indent += "  ";
	}
	else
	{
		// 마지막 노드가 아닌 경우 출력
		std::cout << "├─ ";
		// indent에 |와 공백 추가"
		indent += "| ";
	}

	// 현재 노드의 값을 출력
	std::cout << node->Data << std::endl;

	// 왼쪽 자식 노드를 방문하여 계층 구조를 출력
	PrintHierarchy(node->LeftChild, indent, false);
	// 오른쪽 자식 노드를 방문하여 계층 구조를 출력
	PrintHierarchy(node->RightChild, indent, true);
}