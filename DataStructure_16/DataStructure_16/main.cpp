#include "pch.h"
#include "main.h"

int main() {
	srand((unsigned)time(NULL));

	while (true) {
		Clear;

		std::cout << "1. Data Structure\t2. Algorithm : " << std::endl;
		int n;
		std::cin >> n;


		switch (n)
		{
		case 1:
			DataStructure();
			continue;
		case 2:
			Algorithm();
			continue;
		default:
			continue;
		}

		return 0;
	}
}

void DataStructure()
{
	Clear;
	while (true) {
		std::cout << "1. Linked List\t2. Stack\t3. Queue" << std::endl;
		std::cout << "4. Tree\t\t5. Heap\t\t6. Graph" << std::endl;

		int m;
		std::cin >> m;

		Clear;
		switch (m)
		{
		case LINKED_LIST:
		{
			LinkedList();
			//DoubleLinkedList();
			return;
		}
		case STACK:
		{
			DoStack();
			return;
		}
		case QUEUE:
		{
			DoQueue();
			return;
		}
		case TREE:
		{
			DoBinaryTree();
			return;
		}

		case HEAP:
			DoHeap();
			return;

		case GRAPH:
			DoGraph();
			return;

		default: return;
		}
	}
}

void Algorithm()
{
	Clear;
	while (true)
	{
		std::cout << "1. Selection Sort\t2. Insertion Sort\t3. Bubble Sort" << std::endl;
		std::cout << "4. Quick Sort\t\t5. Marge Sort" << std::endl;
		int n;
		std::cin >> n;
		switch (n) {
		case SELECTION_SORT: {
			DoSelectionSort();
			return;
		}
		case INSERTION_SORT: {
			DoInsertionSort();
			return;
		}
		case BUBBLE_SORT: {
			DoBubbleSort();
			return;
		}
		case QUICK_SORT: {
			DoQuickSort();
			return;
		}
		case MERGE_SORT: {
			DoMergeSort();
			return;
		}
		default: return;
		}
	}
}
