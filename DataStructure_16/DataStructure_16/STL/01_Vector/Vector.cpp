#include "pch.h"
#include "Vector.h"

void DoVector() {
	std::vector<DataType> v; // DataType�� ���� ����

	// �� �ڿ� ���� �߰�
	for (int i = 0; i < 10; i++) {
		v.push_back(rand() % 100);
	}

	// ������ ������
	std::cout << "Vector Size : " << v.size() << std::endl;

	// ���� ����� ����
	std::cout << "Vector Element : ";
	for (int i = 0; i < 10; i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	// ������ ù ��° ��ҿ� ������ ��Ҹ� ���
	std::cout << "First Element : " << v.front() << std::endl;
	std::cout << "Last Element : " << v.back() << std::endl;

	// ������ ù ��° ��Ҹ� ����
	v.erase(v.begin());

	// ������ ��� ��Ҹ� �������� ���
	std::cout << "Reverse Element : ";
	for (auto it = v.rbegin(); it != v.rend(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	// ������ ��� ��� ����
	v.clear();
	std::cout << "Vector Size : " << v.size() << std::endl;

	Pause;
	return;
}