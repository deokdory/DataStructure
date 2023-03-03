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
	// ����Ʈ�� ũ�Ⱑ 1 ������ ��� ������ �̹� �Ϸ�� ����
	if (left >= right) return;

	// ����Ʈ�� ������ ���� �ε���
	int mid = (left + right) / 2;

	// ���� �κ� ����Ʈ�� ��������� ����
	MergeSort(arr, left, mid);

	// ������ �κ� ����Ʈ�� ��������� ����
	MergeSort(arr, mid + 1, right);

	// ���ĵ� ���ʰ� ������ �κ� ����Ʈ�� ����
	Merge(arr, left, mid, right);
}

void Merge(int arr[], int left, int mid, int right)
{
	int i = left;				// ���� �κ� ����Ʈ�� ���� �ε���
	int j = mid + 1;			// ������ �κ� ����Ʈ�� ���� �ε���
	int k = left;				// ���ĵ� ����� ������ �迭�� �ε���
	int size = right + 1;		// �ӽ� �迭 ������
	int* temp = new int[size];	// ���� ����� ������ �ӽ� �迭

	// ���� �κ� ����Ʈ�� ������ �κ� ����Ʈ�� ��ҵ��� ���ϸ� �ӽ� �迭�� ����
	while (i <= mid && j <= right) {
		if (arr[i] >= arr[j]) temp[k++] = arr[i++];
		else temp[k++] = arr[j++];
	}

	// ���� �κ� ����Ʈ�� ������ �κ� ����Ʈ�� ��� �� �ϳ��� ��� ���յ� ���
	// ���� ��ҵ��� �ӽ� �迭�� �߰�
	while (i <= mid) temp[k++] = arr[i++];
	while (j <= right) temp[k++] = arr[j++];

	// �ӽ� �迭�� ����� ���� ����� ���� �迭�� ����
	for (int l = left; l <= right; l++)
		arr[i] = temp[l];

	delete[] temp;
}
