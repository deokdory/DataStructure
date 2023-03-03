#include "pch.h"
#include "MergeSort.h"

#define MAX_LEN 10

void DoMergeSort()
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
	MergeSort(arr, 0, MAX_LEN - 1);
	for (int i = 0; i < MAX_LEN; i++) {
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl;

	Pause;
	return;
}

void MergeSort(int arr[], int left, int right)
{
	// 리스트의 크기가 1 이하인 경우 정렬이 이미 완료된 상태
	if (left >= right) return;

	// 리스트를 반으로 나눌 인덱스
	int mid = (left + right) / 2;

	// 왼쪽 부분 리스트를 재귀적으로 정렬
	MergeSort(arr, left, mid);

	// 오른쪽 부분 리스트를 재귀적으로 정렬
	MergeSort(arr, mid + 1, right);

	// 정렬된 왼쪽과 오른쪽 부분 리스트를 병합
	Merge(arr, left, mid, right);
}

void Merge(int arr[], int left, int mid, int right)
{
	int i = left;				// 왼쪽 부분 리스트의 시작 인덱스
	int j = mid + 1;			// 오른쪽 부분 리스트의 시작 인덱스
	int k = left;				// 정렬된 결과를 저장할 배열의 인덱스
	int size = right + 1;		// 임시 배열 사이즈
	int* temp = new int[size];	// 병합 결과를 저장할 임시 배열

	// 왼쪽 부분 리스트와 오른쪽 부분 리스트의 요소들을 비교하며 임시 배열에 병합
	while (i <= mid && j <= right) {
		if (arr[i] >= arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}

	// 왼쪽 부분 리스트나 오른쪽 부분 리스트의 요소 중 하나가 모두 병합된 경우
	// 남은 요소들을 임시 배열에 추가
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= right) temp[k++] = arr[j++];

	// 임시 배열에 저장된 병합 결과를 원래 배열에 복사
	for (int l = left; l <= right; l++)
		arr[i] = temp[l];

	delete[] temp;
}
