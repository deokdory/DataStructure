#include "pch.h"
#include "Vector.h"

void DoVector() {
	std::vector<DataType> v; // DataType형 벡터 선언

	// 맨 뒤에 원소 추가
	for (int i = 0; i < 10; i++) {
		v.push_back(rand() % 100);
	}

	// 벡터의 사이즈
	std::cout << "Vector Size : " << v.size() << std::endl;

	// 벡터 요소의 접근
	std::cout << "Vector Element : ";
	for (int i = 0; i < 10; i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	// 벡터의 첫 번째 요소와 마지막 요소를 출력
	std::cout << "First Element : " << v.front() << std::endl;
	std::cout << "Last Element : " << v.back() << std::endl;

	// 벡터의 첫 번째 요소를 제거
	v.erase(v.begin());

	// 벡터의 모든 요소를 역순으로 출력
	std::cout << "Reverse Element : ";
	for (auto it = v.rbegin(); it != v.rend(); it++)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	// 벡터의 모든 요소 제거
	v.clear();
	std::cout << "Vector Size : " << v.size() << std::endl;

	Pause;
	return;
}