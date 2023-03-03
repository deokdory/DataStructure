#include "pch.h"
#include "Map.h"

void DoMap() {
	// string = Ű / DataType = ��
	std::map<std::string, DataType> data;

	// ��� �߰�
	data["A"] = 1;
	data["B"] = 2;
	data["C"] = 3;

	// ��� ����
	std::cout << "data[a] : " << data["A"] << std::endl;
	std::cout << "data[b] : " << data["B"] << std::endl;
	std::cout << "data[c] : " << data["C"] << std::endl;

	// ��� ����
	data.erase("B");

	// ��� ��� ���
	for (auto it = data.begin(); it != data.end(); ++it)
		std::cout << it->first << " : " << it->second << std::endl;

	Pause;
	return;
}

