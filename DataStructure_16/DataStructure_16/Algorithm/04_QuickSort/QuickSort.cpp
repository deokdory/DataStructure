#include "pch.h"
#include "QuickSort.h"

#define MAX_LEN 10

void DoQuickSort()
{
	int arr[MAX_LEN];
	std::cout << "Before Sort" << std::endl;
	for (int i = 0; i < MAX_LEN; i++)
	{
		arr[i] = rand() % 100;
		std::cout << arr[i] << " ";
	}

	std::cout << "\n\n";

	std::cout << "After Sort\n";
	QuickSort(arr, 0, MAX_LEN - 1);
	for (int i = 0; i < MAX_LEN; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	Pause;
	return;

}

void QuickSort(int arr[], int left, int right) {
	// 리스트의 크기가 1 이하인 경우, 정렬이 이미 완료된 상태이므로 return
	if (left >= right) return;

	// 리스트의 첫 요소를 pivot으로 설정
	int pivot = arr[left];

	// pivot보다 작은 요소들의 마지막 인덱스
	int i = left + 1;

	// pivot보다 큰 요소들의 첫 인덱스
	int j = right;

	// i와 j가 교차할 때까지 pivot보다 작은 요소는 i, pivot보다 큰 요소를 j로 찾음
	while (i <= j) {
		// 오름차순 : i <= right && arr[i] <= pivot
		while (i <= right && arr[i] > pivot) {
			i++;
		}

		// 오름차순 : j >= left && arr[j] >= pivot
		while (j >= left + 1 && arr[j] < pivot) {
			j--;
		}

		// i와 j가 교차하지 않은 경우, i와 j요소를 swap
		if (i <= j)
			std::swap(arr[i], arr[j]);
	}

	// pivot을 기준으로 분할된 왼쪽과 오른쪽 부분 리스트를 재귀적으로 정렬
	std::swap(arr[left], arr[j]);
	QuickSort(arr, left, j - 1);
	QuickSort(arr, j + 1, right);
}