#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <time.h>

typedef int DataType;

//#define std::cout std::cout
//#define std::cin std::cin
//#define std::endl std::endl
//#define string std::string

#define Clear system("cls");
#define Pause system("Pause");

enum DS // Data Structure
{
	LINKED_LIST = 1,
	STACK,
	QUEUE,
	TREE,
	HEAP,
	GRAPH
};

enum AL // Algorithm
{
	SELECTION_SORT = 1,
	INSERTION_SORT,
	BUBBLE_SORT,
	QUICK_SORT,
	MERGE_SORT
};