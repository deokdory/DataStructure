#include "pch.h"
#include "SelectionSort.h"

#define MAX_LEN 10

void DoSelectionSort() {
	int arr[MAX_LEN];
	std::cout << "Before Sort" << std::endl;
	for (int i = 0; i < MAX_LEN; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}

	std::cout << "\n\n";

	std::cout << "After Sort\n";
	SelectionSort(arr, MAX_LEN);
	for (int i = 0; i < MAX_LEN; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	Pause;
	return;
}


void SelectionSort(int arr[], int length) {
	int index;
	for (int i = 0; i < length - 1; i++) {
		index = i;
		for (int j = i + 1; j < length; j++)
			if (arr[j] > arr[index]) { // <- 내림차순 ( 오름차순 : arr[j] < arr[index] )
				index = j;
			}
		std::swap(arr[index], arr[i]);
	}
}
