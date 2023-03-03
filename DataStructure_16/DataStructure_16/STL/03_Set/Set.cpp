#include "pch.h"
#include "Set.h"

void DoSet() {
	// DataType형 값을 저장하는 set 생성
	std::set<DataType> data;

	// set에 값 추가
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

	// set 크기 출력
	std::cout << "set size : " << data.size() << std::endl;

	// set에 있는 모든 값 출력
	std::cout << "data : ";
	for (DataType x : data)
		std::cout << x << " ";

	std::cout << std::endl;

	// set에서 값 삭제
	data.erase(3);

	// set에 있는 모든 값 출력
	std::cout << "data : ";
	for (DataType x : data)
		std::cout << x << " ";

	std::cout << std::endl;

	Pause;
	return;
}