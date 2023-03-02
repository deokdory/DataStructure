#include "pch.h"
#include "InsertionSort.h"

#define MAX_LEN 10

void DoInsertionSort() {
	int arr[MAX_LEN];
	std::cout << "Before Sort" << std::endl;
	for (int i = 0; i < MAX_LEN; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}

	std::cout << "\n\n";

	std::cout << "After Sort\n";
	InsertionSort(arr);
	for (int i = 0; i < MAX_LEN; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	Pause;
	return;
}

void InsertionSort(int arr[]) {
	int i, j;
	int key;

	for (i = 0; i < MAX_LEN; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0; j--) {
			if (arr[j] < key) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = key;
	}
}
