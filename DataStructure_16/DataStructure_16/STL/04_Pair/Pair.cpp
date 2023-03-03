#include "pch.h"
#include "Pair.h"

void DoPair() {
	std::vector<std::pair<std::string, int>> people;

	people.push_back(std::make_pair("Alice", 32));
	people.push_back(std::make_pair("John", 16));
	people.push_back(std::make_pair("Bob", 54));

	for (auto& person : people)
		std::cout << person.first << " is " << person.second << "\tyears old" << std::endl;

	Pause;
	return;

}