#include "pch.h"
#include "Map.h"

void DoMap() {
	// string = 키 / DataType = 값
	std::map<std::string, DataType> data;

	// 요소 추가
	data["A"] = 1;
	data["B"] = 2;
	data["C"] = 3;

	// 요소 접근
	std::cout << "data[a] : " << data["A"] << std::endl;
	std::cout << "data[b] : " << data["B"] << std::endl;
	std::cout << "data[c] : " << data["C"] << std::endl;

	// 요소 삭제
	data.erase("B");

	// 모든 요소 출력
	for (auto it = data.begin(); it != data.end(); ++it)
		std::cout << it->first << " : " << it->second << std::endl;

	Pause;
	return;
}

