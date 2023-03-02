#include "pch.h"
#include "BubbleSort.h"

#define MAX_LEN 10

void DoBubbleSort() {
	int arr[MAX_LEN];
	std::cout << "Before Sort" << std::endl;
	for (int i = 0; i < MAX_LEN; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}

	std::cout << "\n\n";

	std::cout << "After Sort\n";
	BubbleSort(arr, MAX_LEN);
	for (int i = 0; i < MAX_LEN; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	Pause;
	return;
}

void BubbleSort(int arr[], int length) {
	int i, j;

	//for (int i = length - 2; k >= i; i++) {
	//	for ()
	//	if (arr[i] < arr[i + 1]) std::swap(arr[i], arr[i + 1]);
	//}

	for (i = length - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (arr[j] < arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}
