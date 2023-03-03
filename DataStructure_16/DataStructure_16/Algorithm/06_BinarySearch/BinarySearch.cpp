#include "pch.h"
#include "BinarySearch.h"

#define MAX_LEN 50

void DoBinarySearch() {
	DataType arr[MAX_LEN];

	for (int i = 0; i < MAX_LEN; i++) {
		arr[i] = i;
		if (i % 10 == 0) std::cout << std::endl;
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	int find = rand() % 50;
	std::cout << "Find  : " << find << std::endl;
	std::cout << "Index : " << BinarySearch(arr, MAX_LEN, find) << std::endl;

	Pause;
	return;
}

DataType BinarySearch(DataType arr[], int size, DataType find) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == find)		return mid;
		else if (arr[mid] < find)	left = mid + 1;
		else						right = mid - 1;
	}

	return -1;
}
