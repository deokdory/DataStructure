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

	// 삭제 전 이전 트리의 내용을 출력
	std::cout << "Before Remove" << std::endl;
	tree.InOrder();

	// 배열엑서 하나의 값을 랜덤하게 선택해서 삭제
	tree.Remove(arr[rand() % 15]);

	// 삭제 후 이진트리 출력
	std::cout << "After Remove" << std::endl;
	tree.InOrder();

	tree.PrintHierarchy();
	Pause;
	return;
}

BinaryTree::~BinaryTree()
{
	// 트리를 삭제하기 위해 루프 노드부터 재귀적으로 탐색하여
	// 노드를 삭제하는 함수를 호출
	DestroyTree(Root);
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
	// 트리에서 데이터를 삭제하기 위해 루트 노드부터 재귀적으로 탐색하여
	// 노드를 삭제하는 함수
	Root = Remove(Root, data);
}

void BinaryTree::PreOrder()
{
	PreOrder(Root);
	std::cout << std::endl;
}

void BinaryTree::InOrder()
{
	// 중위순회를 실행하기 위해 루트 노드에서 시작하는 함수를 호출
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
	// 노드가 비어있으면 리턴
	if (!node) return nullptr;

	// 현재 노드의 데이터가 삭제할 데이터와 같다면
	if (data == node->Data)
		// 삭제
		return RemoveNode(node);

	// 삭제할 데이터가 노드보다 작을 경우
	else if (data < node->Data)
	{
		// 왼쪽 자식 노드에서 삭제를 수행
		node->LeftChild = Remove(node->LeftChild, data);
		return node;
	}
	// 삭제할 데이터가 노드보다 클 경우
	else
	{
		// 오른쪽 자식 노드에서 삭제를 수행
		node->RightChild = Remove(node->RightChild, data);
		return node;
	}
}

BinaryTreeNode* BinaryTree::RemoveNode(BinaryTreeNode* node)
{
	// 삭제할 노드가 leaf 노드일 경우
	if (node->LeftChild == nullptr && node->RightChild == nullptr)
	{
		// 노드 삭제
		delete node;
		// 부모 노드에서 해당 노드 연결을 끊기 위해 nullptr 반환
		return nullptr;
	}
	// 삭제할 노드가 자식이 존재할 경우 (1개)
	else if (node->LeftChild != nullptr || node->RightChild != nullptr)
	{
		// 삭제할 노드의 자식 노드 중 존재하는 자식 노드를 찾아서 target으로 설정
		BinaryTreeNode* target = (node->LeftChild != nullptr) ? node->LeftChild : node->RightChild;

		// 노드 삭제
		delete node;

		// 부모 노드에서 해당 노드 연결을 끊고 존재하는 자식 노드와 연결하기 위해 target을 반환
		return target;
	}
	// 삭제 노드가 자식이 존재할 경우 (2걔)
	else
	{
		// 삭제할 노드의 오른쪽 서브트리에서 가장 작은 값을 가진 노드를 찾아서 target으로 설정
		BinaryTreeNode* target = FindMin(node->RightChild);

		// 삭제할 노드의 데이터를 찾은 노드의 데이터로 변경
		node->Data = target->Data;

		// 노드를 삭제하고, 삭제된 노드의 오른쪽 자식 노드와 연결하기 위해 target 을 반환
		node->RightChild = Remove(node->RightChild, target->Data);
		return node;
	}
}

BinaryTreeNode* BinaryTree::FindMin(BinaryTreeNode* node)
{
	// 노드 왼쪽 자식이 없을 때까지 반복해서 왼쪽 자식으로 이동
	while (node->LeftChild != nullptr)
		node = node->LeftChild;

	// 가장 작은 값의 노드를 반환
	return node;
}

// 전위순회 (현재 노드 -> 왼쪽 자식 -> 오른쪽 자식)
void BinaryTree::PreOrder(BinaryTreeNode* node)
{
	// 노드가 존재한다면
	if (node) {

		// 현재 노드 출력
		std::cout << node->Data << " ";
		// 왼쪽 자식 노드 방문
		PreOrder(node->LeftChild);
		// 오른쪽 자식 노드 방문
		PreOrder(node->RightChild);
	}
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

// 후위순회 ( 왼쪽 자식 -> 오른쪽 자식 -> 현재 노드 )
void BinaryTree::PostOrder(BinaryTreeNode* node)
{
	// 노드가 존재한다면
	if (node) {

		// 왼쪽 자식 노드 방문
		PostOrder(node->LeftChild);
		// 오른쪽 자식 노드 방문
		PostOrder(node->RightChild);
		// 현재 노드 출력
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
		indent += "│ ";
	}

	// 현재 노드의 값을 출력
	std::cout << node->Data << std::endl;

	// 오른쪽 자식 노드를 방문하여 계층 구조를 출력
	PrintHierarchy(node->RightChild, indent, node->LeftChild == nullptr);
	// 왼쪽 자식 노드를 방문하여 계층 구조를 출력
	PrintHierarchy(node->LeftChild, indent, false);
}