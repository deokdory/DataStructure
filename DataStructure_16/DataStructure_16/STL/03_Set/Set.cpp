#include "pch.h"
#include "Set.h"

void DoSet() {
	// DataType�� ���� �����ϴ� set ����
	std::set<DataType> data;

	// set�� �� �߰�
	data.insert(3);
	data.insert(6);
	data.insert(123);
	data.insert(34265);
	data.insert(123);
	data.insert(532);
	data.insert(3);
	data.insert(12315);
	data.insert(643);
	data.insert(329);

	// set ũ�� ���
	std::cout << "set size : " << data.size() << std::endl;

	// set�� �ִ� ��� �� ���
	std::cout << "data : ";
	for (DataType x : data)
		std::cout << x << " ";

	std::cout << std::endl;

	// set���� �� ����
	data.erase(3);

	// set�� �ִ� ��� �� ���
	std::cout << "data : ";
	for (DataType x : data)
		std::cout << x << " ";

	std::cout << std::endl;

	Pause;
	return;
}