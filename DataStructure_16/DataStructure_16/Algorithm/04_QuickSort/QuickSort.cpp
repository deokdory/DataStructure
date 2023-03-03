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
	// ����Ʈ�� ũ�Ⱑ 1 ������ ���, ������ �̹� �Ϸ�� �����̹Ƿ� return
	if (left >= right) return;

	// ����Ʈ�� ù ��Ҹ� pivot���� ����
	int pivot = arr[left];

	// pivot���� ���� ��ҵ��� ������ �ε���
	int i = left + 1;

	// pivot���� ū ��ҵ��� ù �ε���
	int j = right;

	// i�� j�� ������ ������ pivot���� ���� ��Ҵ� i, pivot���� ū ��Ҹ� j�� ã��
	while (i <= j) {
		// �������� : i <= right && arr[i] <= pivot
		while (i <= right && arr[i] > pivot) {
			i++;
		}

		// �������� : j >= left && arr[j] >= pivot
		while (j >= left + 1 && arr[j] < pivot) {
			j--;
		}

		// i�� j�� �������� ���� ���, i�� j��Ҹ� swap
		if (i <= j)
			std::swap(arr[i], arr[j]);
	}

	// pivot�� �������� ���ҵ� ���ʰ� ������ �κ� ����Ʈ�� ��������� ����
	std::swap(arr[left], arr[j]);
	QuickSort(arr, left, j - 1);
	QuickSort(arr, j + 1, right);
}